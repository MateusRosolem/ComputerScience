#include <stdio.h>
#define max 8

int main(){
int v[8]={9,8,7,6,5,4,3,2};
int aux=0, i;

    for (int k = 1; k < max; k++){ 
        aux = v[k];
        for (i = k-1; i >= 0 && aux < v[i]; i--){
            v[i+1] = v[i];
        }
        v[i+1]=aux;
    }


    for(i=0; i<max;i ++){
        printf("[%d]", v[i]);
    }

    return 0;
}