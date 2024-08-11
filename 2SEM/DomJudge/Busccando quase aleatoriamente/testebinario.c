#include <stdio.h>
#include <stdlib.h>

int crescente(int buscados, int N, int v[]){
    int min = 0, max = N / 2 - 1, mid;
     printf(" [%d] e [%d]", v[mid], buscados);
    if(v[min] == buscados)
        return min;
    else if(v[max] == buscados)
        return max;
    while(min <= max && buscados != v[mid]){
        mid = (min + max) / 2;
       
        if(v[mid] < buscados)
            min = mid + 1;
        else 
            max = mid - 1;
      }
        if(buscados == v[mid])
            return mid;
    return -1;
}

int decrescente(int buscados, int N, int v[]){
        int min = N / 2, max = N - 1, mid;
    if(v[min] == buscados)
        return min;
    else if(v[max] == buscados)
        return max;
    while(min <= max && buscados != v[mid]){
        mid = (min + max) / 2;
        if(v[mid] > buscados)
            min = mid + 1;
        else 
            max = mid - 1;
      }
        if(buscados == v[mid])
            return mid;
    return -1;
}


int main(){
int n, m, i, j;
int vetbusca;

scanf("%d", &n);
int vet[n];
for(i=0;i<n;i++){
    scanf("%d", &vet[i]);//mudar pra float ou long int
}

scanf("%d", &m);

for(i=0;i<m;i++){
    scanf("%d", &vetbusca);

    if(crescente(vetbusca, n, vet)!=-1){
        printf("%d ",crescente(vetbusca, n, vet));
    }
    else if(decrescente(vetbusca, n, vet)!=-1){
        printf("%d ",decrescente(vetbusca, n, vet));
    }
    else{
        printf("-1 ");
    }

}





    return 0;
}