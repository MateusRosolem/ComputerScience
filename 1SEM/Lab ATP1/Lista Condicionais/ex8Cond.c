#include <stdio.h>

int main(){
float valor, venda;

printf("qual o valor do produto comprado?\n");
scanf("%f", &valor);

if(valor<20){
venda=145*valor/100;
} 

else{
venda = (valor*13)/10;
}
printf("o valor de venda eh: %f ", venda);

    return 0;
}