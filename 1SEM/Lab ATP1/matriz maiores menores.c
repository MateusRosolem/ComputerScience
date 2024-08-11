#include <stdio.h>

int main(){
int a[3][4], i, j, menor, maior;
int s[3] = {0,0,0};

for(i=0;i<3;i++){
    for(j=0;j<4;j++){
        printf("digite o elemento %i %i \n", i, j);
        scanf("%i", &a[i][j]);
    }
}

menor=a[0][0];
maior=a[0][0];
for(i=0; i<3;i++){
    for(j=0;j<4;j++){
        s[i]+=a[i][j];

        if(a[i][j]<menor){
          menor=a[i][j];
        }
        if(a[i][j]>maior){
            maior=a[i][j];
        }

    }
}
printf("o menor e maior valor são %i %i\n", menor, maior);
printf("o valor da soma de cada linha da matriz são:\n");
for(i=0;i<3;i++){
    printf("Linha%i: %i\n", i, s[i]);
}



    return 0;
}