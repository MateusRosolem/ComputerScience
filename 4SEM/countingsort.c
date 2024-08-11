#include <stdio.h>
#include <stdlib.h>

int* countingSort(int A[], int size, int k){
    int* C = (int*)malloc((k+1) * sizeof(int));

for (int i = 0; i < k; i++) {
    C[i]=0;
}

// Frequência
for (int i = 0; i < size; i++){
    C[A[i]-1]++;
}

// Cumulativa
for (int i = 1; i < k; i++){
    C[i] += C[i-1];
}

int* B = (int*)malloc(size* sizeof(int));

for (int i = size -1;i>=0;i--){
    B[C[A[i]-1]-1] = A[i];  
    C[A[i]-1]--;
}
free(C);
printf("deu certo");
return B;

}



int main(){
int size = 10;
int k = 8;
int* result = (int*)malloc(size* sizeof(int));
int A[]={0,4,6,2,4,1,7,8,3,2};
int i=0;

printf("Lista ordenada:\n");
result = countingSort(A,size,k);
for(i=0; i<size; i++){
    printf("[%d]", result[i]);
}
    free(result);
    return 0;
}