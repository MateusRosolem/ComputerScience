#include <stdio.h>
#include <math.h>
#define n 4


int main(){
    int i=0;

    typedef struct rect{
        float x[4], y[4], aresta[4], area;
    }Ret;

    Ret ret;

    for(i=0;i<n;i++){
        printf("digite o valor das coordenadas do ponto %d desejadas ", i);
        scanf("%f %f", &ret.x[i], &ret.y[i]);
    }


        if(ret.x[1]-ret.x[0]==0){
            ret.aresta[0]=sqrt(pow(ret.x[2]-ret.x[0],2));
            ret.aresta[2]=sqrt(pow(ret.x[2]-ret.x[1],2));
        }
        else{
            ret.aresta[0]=sqrt(pow(ret.x[1]-ret.x[0],2));
            ret.aresta[2]=sqrt(pow(ret.x[3]-ret.x[2],2));
        }


        if(ret.y[1]-ret.y[0]==0){
            ret.aresta[1]=sqrt(pow(ret.y[2]-ret.y[0],2));
            ret.aresta[3]=sqrt(pow(ret.y[2]-ret.y[1],2));
        }
        else{
            ret.aresta[1]=sqrt(pow(ret.y[1]-ret.y[0],2));
            ret.aresta[3]=sqrt(pow(ret.y[3]-ret.y[2],2));
        }


    
    if(ret.aresta[0]==ret.aresta[2] && ret.aresta[1]==ret.aresta[3]){
        ret.area=ret.aresta[0]*ret.aresta[1];
        printf(" o comprimento de cada aresta 1 e 2 sao %f %f\n", ret.aresta[0], ret.aresta[1]);
        printf("o valor da area do retangulo eh: %f \n", ret.area);
    }
    else{
        printf("esses valores nao formam um retângulo");
    }

    return 0;
}