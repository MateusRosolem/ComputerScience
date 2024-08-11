#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


struct timeval start_time;
struct timeval stop_time;
#define MICRO_PER_SECOND 1000000

void countingSort(long int array[], long int size)
{
    int i;
    long int *output = malloc(size * sizeof(long int));

    // Find the largest element of the array
    long int max = array[0];
    for ( i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    // The size of count must be at least (max+1)
    long int *count = malloc((max + 1) * sizeof(long int));

    // Initialize count array with all zeros.
    for (  i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    // Store the count of each element
    for (  i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (  i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for ( i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements long into the original array
    for (  i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    free(output);
    free(count);
}

// Function to prlong int an array
void printArray(long int array[], long int size)
{
    for (long int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// Driver code
long int main()
{

double result;
long int tamanho = 100000000;


    srand(time(NULL)); // Inicializar srand
    long int *array = (long int *)malloc(tamanho * sizeof(long int));
    long int *arrayinv = (long int *)malloc(tamanho * sizeof(long int));
    for (long int i = 0; i < tamanho; i++)
    {
        array[i] = rand() % 500;
    }

    gettimeofday(&start_time, NULL);
    countingSort(array, tamanho);
    gettimeofday(&stop_time, NULL);
    result = (double)(stop_time.tv_sec - start_time.tv_sec);
    result += (stop_time.tv_usec - start_time.tv_usec) / (double)MICRO_PER_SECOND;
    printf("Tempo Aleatorio: %.6lf  ", result);

    for (long int i = 0; i < tamanho; i++)
    {
        arrayinv[i] = array[tamanho-i-1];
    }
    //printArray(arrayinv, tamanho);

    gettimeofday(&start_time, NULL);
    countingSort(array, tamanho);
    gettimeofday(&stop_time, NULL);

    result = (double)(stop_time.tv_sec - start_time.tv_sec);
    result += (stop_time.tv_usec - start_time.tv_usec) / (double)MICRO_PER_SECOND;
    printf("Tempo Ordenado: %.6lf  ", result);

    gettimeofday(&start_time, NULL);
    countingSort(arrayinv, tamanho);
    gettimeofday(&stop_time, NULL);
    result = (double)(stop_time.tv_sec - start_time.tv_sec);
    result += (stop_time.tv_usec - start_time.tv_usec) / (double)MICRO_PER_SECOND;
    printf("Tempo Descending: %.6lf  ", result);

    // prlong intArray(array, tamanho);


    free(array);
    return 0;
}
