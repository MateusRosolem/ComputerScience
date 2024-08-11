#include <stdio.h>
#include <stdlib.h>


int buscabcresc(int *vet, int tam, int num){
int min=0, max=(tam/2)-1, mid;

if(num==vet[min]) return(min);
if(num==vet[max]) return(max);
mid=(min+max)/2;
while(num!=vet[mid] && min<max){
        mid=(min+max)/2;
    if(num>vet[mid]){
        min=mid+1;
    }
    else
        max=mid-1;
}
if(num==vet[mid])
  return mid;
else
    return -1;
}

int buscabdecresc(int *vet, int tam, int num){
int min=(tam/2), max=tam-1, mid;

if(num==vet[min]) return(min);
if(num==vet[max]) return(max);
mid=(min+max)/2;
while(num!=vet[mid] && min<max){
    mid=(min+max)/2;
    if(num<vet[mid])
        min=mid+1;
    else
        max=mid-1;
}
if(num==vet[mid])
  return mid;
else
    return -1;
}



int main(){
int n, m, i, j;
int *vet, vetbusca, num=0;

scanf("%d", &n);
vet=malloc(n*sizeof(int));
for(i=0;i<n;i++){
    scanf("%d", &vet[i]);//mudar pra float ou long int
}

scanf("%d", &m);

for(i=0;i<m;i++){
    scanf("%d", &vetbusca);

    num=buscabcresc(vet, n, vetbusca);
    if(num!=-1){
        printf("%d ",buscabcresc(vet, n, vetbusca));
    }
    else {
        printf("%d ",buscabdecresc(vet, n, vetbusca));
    }


}





    return 0;
}