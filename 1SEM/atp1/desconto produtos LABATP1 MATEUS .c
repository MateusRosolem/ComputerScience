#include <stdio.h>

int main(){
char nome[25];
int  qtde;
float preco, total;


printf("qual o nome do produto?\n");
scanf("%s", &nome);
printf("qual o preco?\n");
scanf("%f", &preco);
printf("Qual a quantidade desejada?\n");
scanf("%i", &qtde);

if (qtde<=10){

}
else if(qtde>10 && qtde<21){
    preco=preco*9/10;
}
else if(qtde>20 && qtde<51 ){
    preco=preco*8/10;
}
else{
    preco=preco*75/100;
}


total=qtde*preco;
printf("o %s tera um valor total de %f \n", nome, total);



    return 0;
}