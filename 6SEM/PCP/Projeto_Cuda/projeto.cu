#include <stdio.h>
#include <cuda.h>
#include <math.h>


#define THREADS_PER_BLOCK 512
#define NUM_RUNS 10

#define CUDA_CHECK_RETURN(value)                                               \
{                                                                              \
    cudaError_t _m_cudaStat = value;                                           \
    if (_m_cudaStat != cudaSuccess) {                                          \
      fprintf(stderr, "Error %s at line %d in file %s\n",                      \
              cudaGetErrorString(_m_cudaStat), __LINE__, __FILE__);            \
      exit(1);                                                                 \
    }                                                                          \
}

/**
 * Função device que calcula o valor da função a ser integrada
 * @param x Coordenada x do ponto
 * @param y Coordenada y do ponto
 * @return Valor de sin(x² + y²) no ponto (x,y)
 */
__device__ double f(double x, double y) {
    return sin(x*x + y*y);
}

/**
 * Kernel CUDA que implementa a integração pelo método do trapézio
 * @param result Ponteiro para o resultado da integração (em memória de device)
 * @param nx Número de intervalos na direção x
 * @param ny Número de intervalos na direção y
 * 
 * O kernel divide o domínio de integração entre as threads disponíveis,
 * onde cada thread calcula sua contribuição local para a integral.
 * Os pontos nas bordas são tratados com peso 0.5 conforme o método do trapézio.
 */
__global__ void trapezoidalIntegration(double *result, int nx, int ny) {
    // Define os limites do domínio de integração
    const double x_start = 0.0;
    const double x_end = 1.5;
    const double y_start = 0.0;
    const double y_end = 1.5;
    
    // Calcula o tamanho dos intervalos em cada direção
    const double dx = (x_end - x_start) / nx;
    const double dy = (y_end - y_start) / ny;
    
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int total_threads = blockDim.x * gridDim.x;
    double local_sum = 0.0;

    // Calcula o número total de pontos e distribui entre as threads
    long long total_points = (long long)(nx + 1) * (ny + 1);
    long long points_per_thread = (total_points + total_threads - 1) / total_threads;
    long long start_point = tid * points_per_thread;
    long long end_point = min(start_point + points_per_thread, total_points);
    
    // Itera sobre os pontos atribuídos a esta thread
    for(long long global_idx = start_point; global_idx < end_point; global_idx++) {
        // Converte índice para coordenadas 2D
        int i = global_idx / (ny + 1);
        int j = global_idx % (ny + 1);
        
        if(i <= nx && j <= ny) {
            double x = x_start + i * dx;
            double y = y_start + j * dy;
            
            // Aplica os pesos do método do trapézio para pontos nas bordas
            if(i == 0 || j == 0 || i == nx - 1 || j == ny - 1)
                local_sum += f(x, y) * 0.5f;
            else
                local_sum += f(x, y); 
        }
    }
    // Multiplica pela área do elemento de integração
    local_sum *= dx * dy;
    // Soma atomicamente ao resultado global
    atomicAdd(result, local_sum);
}

int main() {
    const int block_sizes[] = {10, 100, 1000};
    const int interval_sizes[] = {1000, 10000, 100000};

    // Itera sobre todas as combinações de parâmetros
    for(int b = 0; b < 3; b++) {
        for(int ix = 0; ix < 3; ix++) {
            for(int iy = 0; iy < 3; iy++) {
                float total_time = 0.0;
                double total_int = 0.0;
                int blocks = block_sizes[b];
                int nx = interval_sizes[ix];
                int ny = interval_sizes[iy];
                // Executa 10 vezes para média
                for(int exec = 0; exec < NUM_RUNS; exec++) {
                    // Aloca e inicializa memória na GPU
                    double *d_result;
                    CUDA_CHECK_RETURN(cudaMalloc(&d_result, sizeof(double)));
                    CUDA_CHECK_RETURN(cudaMemset(d_result, 0, sizeof(double)));

                    // Cria eventos para medição de tempo
                    cudaEvent_t start, stop;
                    CUDA_CHECK_RETURN(cudaEventCreate(&start));
                    CUDA_CHECK_RETURN(cudaEventCreate(&stop));
                    
                    // Executa e mede o tempo do kernel
                    CUDA_CHECK_RETURN(cudaEventRecord(start));
                    trapezoidalIntegration<<<blocks, THREADS_PER_BLOCK>>>(d_result, nx, ny);
                    CUDA_CHECK_RETURN(cudaEventRecord(stop));
                    
                    // Copia o resultado de volta para CPU
                    double result;
                    CUDA_CHECK_RETURN(cudaMemcpy(&result, d_result, sizeof(double), cudaMemcpyDeviceToHost));
                    total_int += result;

                    // Calcula o tempo de execução
                    float milliseconds = 0;
                    CUDA_CHECK_RETURN(cudaEventElapsedTime(&milliseconds, start, stop));
                    total_time += milliseconds;

                    CUDA_CHECK_RETURN(cudaFree(d_result));
                    CUDA_CHECK_RETURN(cudaEventDestroy(start));
                    CUDA_CHECK_RETURN(cudaEventDestroy(stop));
                }

                // Calcula e imprime médias                
                float avg_time = total_time / NUM_RUNS;

                printf("%d, %d, %d, %15.15f, %15.15lf\n", 
                       blocks, nx, ny, 
                       avg_time, 
                       total_int / NUM_RUNS);
            }
        }
    }
    
    return 0;
}