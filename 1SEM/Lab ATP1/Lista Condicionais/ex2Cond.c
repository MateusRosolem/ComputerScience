#include <stdio.h>

int main(){
int num;

printf("diga um numero\n");
scanf("%i", &num);


if(num%2==0){
printf("seu numero eh par");
}
else{
    printf("seu numero eh impar");
}
    return 0;
}