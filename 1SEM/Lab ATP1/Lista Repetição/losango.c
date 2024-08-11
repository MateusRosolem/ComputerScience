#include <stdio.h>
#define n 12


int main(){
    int i;
    int cont;
    int contx;
    int aux;


if(n%2==1){
    
    for(i=1; i<=n*2; i+=4){
        cont=n*2-(i/2);
        do{
            printf(" ");
            cont-=1;
        }
        while(cont>0);
        
        
        contx=i;
        do{
            
            printf("x");
            contx--;
        }
        while(contx>0);
        printf("\n");
        }


    for(i=(n*2)-5;i>0; i-=4){
        cont=n*2-(i/2);
        do{
            printf(" ");
            cont-=1;
        }
        while(cont>0);



        contx=i;
        do{
            printf("x");
            contx--;
        }
        while(contx>0);
        printf("\n");
    }
}

else{
for(i=1; i<=n*2; aux=i, i+=4){
        cont=n*2-(i/2);
        do{
            printf(" ");
            cont-=1;
        }
        while(cont>0);
        
        
        contx=i;
        do{
            
            printf("x");
            contx--;
        }
        while(contx>0);
        printf("\n");
        }


    for(i=aux;i>0; i-=4){
        cont=n*2-(i/2);
        do{
            printf(" ");
            cont-=1;
        }
        while(cont>0);



        contx=i;
        do{
            printf("x");
            contx--;
        }
        while(contx>0);
        printf("\n");
    }
}

    return 0;
}