#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho 100

int* countingSort(int A[], int size, int k) {
    int* C = (int*)malloc(k * sizeof(int));

    // Inicializar C com zeros
    for (int i = 0; i < k; i++) {
        C[i] = 0;
    }
    

    // Frequência
    for (int i = 0; i < size; i++) {
        C[A[i] - 1]++;
    }


    // Cumulativa
    for (int i = 1; i < k; i++) {
        C[i] += C[i - 1];
    }

    int* B = (int*)malloc(size * sizeof(int));

    for (int i = size - 1; i >= 0; i--) {
        B[C[A[i] - 1] - 1] = A[i];
        C[A[i] - 1]--;
    }

    free(C);
    return B;
}

int main() {
    srand(time(NULL)); // Inicializar srand
    int *A = (int *)malloc(tamanho * sizeof(int));

    int k = 30; // Supondo que os elementos de A estão no intervalo de 1 a k
    // Preencher o array com números aleatórios entre 0 e 29
    for (int i = 0; i < tamanho; i++)
    {
        A[i] = rand() % 30;
    }
    int size = sizeof(A) / sizeof(A[0]);

    clock_t start, end;
    long double cpu_time;
    start = clock();
    int* sortedArray = countingSort(A, size, k);
    end = clock();
    cpu_time = ((long double)(end - start)) / (CLOCKS_PER_SEC / 1000);
    printf("Tempo gasto: %Le\n", cpu_time);

    // Imprimir array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }

    free(sortedArray);

    return 0;
}