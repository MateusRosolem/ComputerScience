#include <stdio.h>

int main(){
float matriz[2][2];
float det;
int i, j;

for(i=0;i<2;i++){
    for(j=0; j<2; j++){
        printf("digite um valor para a matriz no lugar %i %i \n", i, j);
        scanf("%f", &matriz[i][j]);
    }
}

for(i=0;i<2;i++, j++){
        printf("[%i] [%i]", i,j);
    
}

det = matriz[0][0]*matriz[1][1] - (matriz[0][1]*matriz[1][0]);
printf("seu det eh igual a %f", det);



    return 0;
}