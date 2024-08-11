#include <stdio.h>

int main(){
int m[5][5];
int sim=1;
int i, j;

for(i=0;i<5;i++){
    for(j=0; j<5; j++){
        printf("digite um valor para a matriz no lugar %d %d \n", i, j);
        scanf("%d", &m[i][j]);
    }
}

for(i=0;i<5;i++){
    for(j=0;j<5;j++){
        if(m[i][j]!=m[j][i]) sim=0;
    }
}
 
if(sim==0)
    printf("ela nao eh simetrica!");
else
    printf("ela eh simetrica");

    return 0;
}