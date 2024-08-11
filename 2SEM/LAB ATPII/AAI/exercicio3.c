#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

int qtde[12][4], custo[4][2];
int i=0, j=0;
int quantmensal[12], quantanual[4], customensal[12], prodanual=0, custoanual=0, lucromensal[12], lucroanual=0;
//quantidade por mes][4 produtos       && produto[i][custo==1, lucro==2]

srand(time(NULL));

for(i=0;i<12;i++){
    for(j=0;j<4;j++){//le os produtos em cada mes

        qtde[i][j]=(rand()%10);
        custo[j][0]=(rand()%10);
        custo[j][1]=(rand()%10);
        quantmensal[i]+=qtde[i][j]; //ok
        quantanual[j]=qtde[i][j];

        customensal[i]=custo[j][0];
        lucromensal[i]=custo[j][1];
    }
    custoanual+=customensal[i];
    lucroanual+=lucromensal[i];
    prodanual+=quantmensal[i];
}



/*for(i=0;i<12;i++)
    for(j=0;j<4;j++){
        printf("Qual a quantidade do produto%d no mes%d ?\n",j+1 ,i+1);
        scanf("%d", &qtde[i][j]);
        printf("qual o custo?\n");
        scanf("%d", &custo[j][0]);
        printf("qual o lucro?\n");
        scanf("%d", &custo[j][1]);
    }*/


//SAIDA

printf("Quantidade de produtos por mes:\n");
for(i=0;i<12;i++){
        printf("Mes %d ", i+1);
        printf("%d\n", quantmensal[i]);
}
printf("\nQuantidade anual de cada produto:\n");
for(i=0;i<4;i++){
        printf("Produto %d", i+1);
        printf("Quant:%d \n", quantmensal[i]);
}

printf("\nProducao anual total: %d\n", prodanual);

printf("\nCusto Mensal e Lucro Mensal:\n");
for(i=0;i<12;i++){
        printf("Mes %d:  ", i+1);
        printf("Custo Mensal:%d ", customensal[i]);
        printf("Lucro Mensal:%d\n", lucromensal[i]);
}

printf("\nCusto anual: %d\n", custoanual);

printf("\nLucro anual: %d\n", lucroanual);

    return 0;
}