#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC


#define nvalores 200000 //define valores

                             //2.147.483.647
typedef struct biggo {
int high; //Bilhoes            2
int low; //menor que bilhoes    147.483.647
} BigInt;

void insertion(BigInt *vet, int n){
int i, j, k, aux, aux2;

for (i=1;i<n; i++){
    aux=vet[i].high;//começa no segundo elemento(pra comparar com o 1)
    aux2=vet[i].low;
    j=i; 
    while(j > 0 && ((vet[j-1].high > aux) || (vet[j-1].high==aux && aux > 0 && vet[j-1].low > aux2) || (vet[j-1].high==aux && aux < 0 && vet[j-1].low < aux2))){ // vai comparando pra tras ( e se for negativo, ele troca se o menor valor vier antes)
        vet[j].high = vet[j-1].high;
        vet[j].low = vet[j-1].low;  
        j--;
    }
    vet[j].high=aux;
    vet[j].low=aux2;

}
return;
}



int main(){
//Declaração de variáveis
FILE *fpnum, *fpquick;
BigInt num[nvalores];
fpnum=fopen("bigint.dat", "r");
fpquick=fopen("quick.dat", "w");
int i=0;
double time_spent = 0.0;
clock_t begin = clock();

 


while(!feof(fpnum)){//leitura de dados
    fscanf(fpnum,"%d %d", &num[i].high, &num[i].low);
    i++;
}

insertion(num, nvalores);//função

for(i=0;i<nvalores;i++)//saida de dados
    fprintf(fpquick,"%d %d\n", num[i].high, num[i].low);

//fechamento de arquivos
fclose(fpnum);
fclose(fpquick);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("The elapsed time is %f seconds", time_spent);
    return 0;
}

