#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//tamanho N/8 < P ≤ N/4, com P = 2k
//, e que a cada itera¸c˜ao esse passo ´e dividido por 2.


void shellsort(int *vet, int n){
int i, j, k=1, l, valor;


while(k<(n/2)) k=3*k+1; //para num valor maior que n/2 // acha o valor dos passos iniciais

while(k!=1){ 
    k=k/3;//Razao
    for(l=0;l<k;l++){ // laco pra fazer todos os insertions daquele passos
        for(i=l+k; i<n; i=i+k){ //comeca os conjuntos(comeca no K, anda K passos
            valor=vet[i]; j=i;
            while(j-k>=0 && vet[j-k]>valor){ // compara os valores(o primeiro pra nao trocar o primeiro valor com ele memso toda vez)
                vet[i]=vet[j-k];
                j=j-k;
            }
            vet[j]=valor;
        }
    }
}


}


int main(){
int n,i,tam=0;
char **pal;

int vet[10]={4,8,5,2,10,3,4,1,9,6};
shellsort(vet,10);
for(i=0;i<10;i++) printf("%d", vet[i]);








    return 0;
}