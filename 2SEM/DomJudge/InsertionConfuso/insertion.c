#include <stdio.h>
#include <stdlib.h>

void insercaocresc(double *vet, int k){
int i, j;
double aux;

for (i=1;i<k+1; i++){
    aux=vet[i];
    j=i;
    while(j>0 && vet[j-1]>aux){ // vai comparando pra tras
        vet[j]=vet[j-1]; j--;
    }
    vet[j]=aux;
}

}


void insercaodecresc(double *vet, int n, int k){
int i, j;
double aux;

  if(k==0){
    for (i=1; i < n; i++){
        aux = vet[i];
        j = i - 1;
        while (aux > vet[j] && j >= 0){
            vet[j + 1] = vet[j];
            j--;
        }
    vet[j + 1] = aux;
    }
  }
  else{
    for (i=k+2; i < n; i++){
        aux = vet[i];
        j = i - 1;
      
        while (aux > vet[j] && j >= k+1){
            vet[j+1] = vet[j];
            j--;
        }
    vet[j+1] = aux;
    }
  }

}



void funcao(double *vet, int n, int k){

if(k==0){
  insercaodecresc(vet,n,k);
}
else{
  insercaocresc(vet,k);
  insercaodecresc(vet,n,k);
}
  
}


int main(){
int n, k, i;
double *v;


scanf("%d %d", &n, &k);
v=malloc(n*sizeof(double));
for(i=0;i<n;i++)
    scanf("%lf", &v[i]);


funcao(v,n,k);

for(i=0;i<n;i++)
    printf("%.3lf ", v[i]);


    return 0;
}


