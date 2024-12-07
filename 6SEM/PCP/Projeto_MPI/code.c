#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

double f(const double x, const double y){
  return (sin(x * x + y * y));
}

/**
 * Calcula a integral de uma função usando o método do trapézio em paralelo com MPI.
 *
 * @param a      O limite inferior do intervalo no eixo x.
 * @param b      O limite superior do intervalo no eixo x.
 * @param c      O limite inferior do intervalo no eixo y.
 * @param d      O limite superior do intervalo no eixo y.
 * @param nx     O número de subdivisões no eixo x.
 * @param ny     O número de subdivisões no eixo y.
 * @param rank   O rank do processo atual no ambiente MPI.
 * @param size   O número total de processos no ambiente MPI.
 * 
 * @return O valor aproximado da integral no intervalo definido, calculado em paralelo.
 *
 */
double Trapezoidal_Rule(const double a, const double b, const double c, const double d, const int nx, const int ny, int rank, int size){
  double hx, hy, integral = 0.0, local_integral = 0.0;
  
  hx = (b - a) / nx;
  hy = (d - c) / ny;

  int rows_p_work = nx / size; // quantas linhas cada processo calcula
  int start = rank * rows_p_work;
  int end = (rank == size - 1) ? nx : start + rows_p_work; //ultimo processo pega o restante das linhas

  for(int i = start; i < end; i++){
    for(int j = 0; j < ny; j++){
        float xi = a + i * hx;
        float yj = c + hy * j;
        
        if(i == 0 || j == 0 || i == nx - 1 || j == ny - 1)
            local_integral += f(xi, yj) * 0.5f;
        else
            local_integral += f(xi, yj); 
    }
  }
  // utilizando de reduce para realizar a soma de todos os resultados locais
  MPI_Reduce(&local_integral, &integral, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  
  return integral * hx * hy;
}

int main(int argc, char* argv[]){
  double itime, ftime, result = 0.0;
  int rank, num_tasks;
  MPI_Status mpi_status;
  
  //inicializando o comunicador e o tamanho do número de processos
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &num_tasks);

  int intervals_x = atoi(argv[1]);
  int intervals_y = atoi(argv[2]);

  // calculando o tempo para realizar a regra do trapézio
  itime = MPI_Wtime();
  result = Trapezoidal_Rule(0.0, 1.5, 0.0, 1.5, intervals_x, intervals_y, rank, num_tasks);
  ftime = MPI_Wtime();

  // se for processo root printa o valor
  if (rank == 0) {
    printf("%d,%d,%d,%15.15f,%15.15f\n", 
            rank, intervals_x, intervals_y, 
            ftime - itime, result);
  }
  // finaliza o ambiente MPI
  MPI_Finalize();
}