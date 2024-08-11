#include <stdio.h>
#define n 5

int main(){
int a[n][n], i ,j;

printf("\n");
printf("sua matriz eh: \n");
for(i=0; i<n; i++){
    for(j=0; j<=i;j++){  //j<i pelo triangulo diagonal direita ser 0
        if(i==j || j==0){ //diagonal principal
            a[i][j]=1;
        }
        else{// a 2,1 //x= cara de cima mais cara do lado
            a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
        
        printf("%d", a[i][j]);

    }
    printf("\n");
}


    return 0;
}