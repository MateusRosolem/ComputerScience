#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//tamanho N/8 < P ≤ N/4, com P = 2k
//, e que a cada itera¸c˜ao esse passo ´e dividido por 2.


void shellsort(char **vet, int size){
 int i , j , g, passo = 1;
 char *carac;
 carac=malloc(sizeof(char)*20);
  
    do{
        passo = 2*passo;
    } while(passo <= size/4);
  
    do {
        passo /= 2;
        for(i = passo; i < size; i++) {
            carac = vet[i];
            j = i - passo;
            while (j >= 0 && strcmp(carac,vet[j]) < 0) {
                vet[j + passo] = vet[j];
                j -= passo;
            }
            vet[j + passo] = carac;
        }

        for(g=0;g<size;g++) {
            printf("%s ",vet[g]);
        }
        printf("\n");

    }while(passo > 1);
}



int main(){
int n,i;
char **pal;


 //ENTRADA
scanf("%d", &n);
pal=malloc(n*sizeof(char *));
for(i=0;i<n;i++) //Loop para percorrer todos os índices do seu "vetor"
    pal[i]=malloc(sizeof(char)*20); //String Dinâmica Normal


for(i=0;i<n;i++){
    scanf("%s", pal[i]);
}


//PROCESSAMENTO
shellsort(pal,n);



for(i=0;i<n;i++) //Percorre o "Vetor"
    free(pal[i]); //Libera a String
free(pal); //No término do Loop, libera o "Vetor"

    return 0;
}