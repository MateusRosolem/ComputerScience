#include <stdio.h>
#include <math.h>
#define n 10

int main(){
    float v[10];
    float dp, soma=0;
    float media=0;

    for(int i=0; i<n ;i++){
        printf("digite o valor [%i] \n", i);
        scanf("%f", &v[i]);

        media+=v[i];
    }

    media=media/n;

    for(int i=0; i<n; i++){
        soma+=pow(v[i]-media,2);
    }


    dp=sqrt(soma/10);
    printf("media eh %f \n", media);
    printf("desvio padrao eh%f", dp);

    return 0;
}