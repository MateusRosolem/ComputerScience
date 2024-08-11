#include <stdio.h>

int main(){
int n, result=0;

printf("escolha n\n");
scanf("%i", &n);



while(n>1){
result+=n;

n--;
}



printf(" a soma dos elementos de 1 ate n eh:%i\n", result);
    return 0;
}