#include <stdio.h>

int main(){

int aux=0, *pa;
scanf("%d", &aux);
pa=&aux;
printf("numero %d \n", aux);
printf("pa %d \n", pa);
printf("*pa %d \n", *pa);


    return 0;
}