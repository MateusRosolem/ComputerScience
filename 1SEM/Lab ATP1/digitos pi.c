#include <stdio.h>
#include <math.h>

int main(){
float den=1;
float termo=1;
float sinal=1;
float pi;
float e=0.01;
float soma=0;


while(fabs(termo)>e){
termo=0;

termo = sinal/den;
soma += termo;
printf("soma %f\n", soma);
printf("\n");
printf("sinal %f\n", sinal);
printf("den %f\n", den);
printf("termo %f\n", termo);
printf("\n");

sinal=-1*sinal;
den=den+2;


}

pi=4*soma;
printf("o valor de pi eh %f\n", pi);
    return 0;
}