#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC

#define nvalores 200000 //define valores

                             //2.147.483.647
typedef struct biggo {
int high; //Bilhoes            2
int low; //menor que bilhoes    147.483.647
} BigInt;


int mediana3(BigInt *v,int i, int j, int k){
if((v[i].high > v[j].high && v[i].high < v[k].high) || (v[i].high < v[j].high && v[i].high > v[k].high))
    return i;
if((v[j].high > v[i].high && v[j].high < v[k].high) || (v[j].high < v[i].high && v[j].high > v[k].high))
    return j;
else //casos que numeros sao iguais entra aqui tambem
    return k;
}

void troca(BigInt *vet,int ind1,int ind2) {
    int aux,aux2;

    aux = vet[ind1].high;
    vet[ind1].high = vet[ind2].high;
    vet[ind2].high = aux;

    aux2 = vet[ind1].low;
    vet[ind1].low  = vet[ind2].low;
    vet[ind2].low  = aux2;
}

void quicksort(BigInt *vet, int lo, int hi){
int i, pivo,bigger;
//hi eh o pivo(que é deixado sempre em ultimo)

if(lo<hi){// indice da primeira e ultima posicak)
    pivo=mediana3(vet,lo,(lo+hi)/2, hi); //retorna o indice da mediana 
    troca(vet,pivo,hi); //troca o pivo de lugar com o hi
    bigger=lo;

    for(i=bigger;i<hi;i++){  
        if(vet[i].high < vet[hi].high){
            troca(vet,i,bigger);
            bigger++;
        }  
        else if(vet[i].high==vet[hi].high){ //se os bilhoes forem iguais
            if(vet[i].low < vet[hi].low && vet[i].high>0){ 
                troca(vet,i,bigger);
                bigger++;
            }
            else if(vet[i].low > vet[hi].low && vet[i].high<0){//se for negativo o menor, eh o que tem maior valor em modulo
                troca(vet,i,bigger);
                bigger++;
            }
        }
    }

    troca(vet,i,bigger);//troca o pivo com o bigger(pra colcoar o pivo bem no meio)
    quicksort(vet, lo, bigger-1);
    quicksort(vet,bigger+1,hi);
}
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

quicksort(num, 0, nvalores-1);//função

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

