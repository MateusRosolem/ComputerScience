#include <stdio.h>
#include <stdlib.h>

int crescente(int num, int N, int vet[]);
int decrescente(int num, int N, int vet[]);

int main(){
int n, m, i, num, key;

scanf("%d", &n);
int a[n];
for(i = 0; i < n; i++)
    scanf("%d ", &a[i]);

scanf("%d", &m);
for(i = 0; i < m; i++){
    scanf("%d", &num);
    key = crescente(num, n, a);
    if(key != -1)
        printf("%d ", key);
    else{
        key = decrescente(num, n, a);
        printf("%d ", key);
    }
}
return 0;
}

int crescente(int num, int N, int vet[]){
int min = 0, max = N / 2 - 1, mid;

if(vet[min] == num) return min;
else if(vet[max] == num) return max;
while(min <= max && num != vet[mid]){
    mid = (min + max) / 2;
    if(vet[mid] < num)
        min = mid + 1;
    else 
        max = mid - 1;
    }
    if(num == vet[mid])
        return mid;
return -1;
}

int decrescente(int num, int N, int vet[]){
int min = N / 2, max = N - 1, mid;
if(vet[min] == num)return min;
else if(vet[max] == num)return max;
while(min <= max && num != vet[mid]){
    mid = (min + max) / 2;
    if(vet[mid] > num)
         min = mid + 1;
    else 
        max = mid - 1;
}
if(num == vet[mid])
    return mid;
return -1;
}