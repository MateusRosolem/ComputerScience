#include <stdio.h>
#include <math.h>


int main(){
int n=0;
int fat=1;
int aux=0;


float x=0;
int nt=0;
float cosh=0;

printf("digfite um numero pra calcular fatorial \n");
scanf("%d", &n);
aux=n;
for(int i=1;i<=n;i++){
fat=fat*i;
}
printf(" o fatorial eh %d  \n", fat);





printf("digfite um numero pra x \n");
scanf("%f", &x);
printf("digfite um numero pra nt \n");
scanf("%d", &nt);

fat=1;
n=aux;
n=n*2;
for(int i=1;i<=n;i++){
fat=fat*i;
}
printf(" %d", fat);

n=aux;
for(int i=0;i<nt;i++){
cosh+= (pow(x,2*n))/fat;
}
printf(" cosh: %f \n", cosh);




//COSH DE 0 A 100
fat=1;
n=aux;
n=n*2;
for(int i=1;i<=n;i++){
fat=fat*i;
}
printf(" %d", fat);


nt=100;
cosh=0;
x=0;
for(int i=0;i<1000;i++){
    printf(" Valor de x %f", x);
    for( int j=0;j<nt;j++){
        cosh+= (pow(x,2*n))/fat;
    }
    printf(" Valor de Cosh de X %f", cosh);
    printf("\n");
    cosh=0;
    x=x+0.1;
}


    return 0;
}