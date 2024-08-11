#include <stdio.h>
#include <stdlib.h>

typedef struct list{
int ti;
int c;
struct list *prox;
}lista;



void insereProcesso(int ti, int c, lista **h){
lista *novo, *aux, *antes;

novo = (lista *)malloc(sizeof(lista));
novo->ti=ti;
novo->c=c;

    if(*h==NULL){// se tiver vazia
        novo->prox = NULL;
        *h=novo;
        return;
    }

aux=antes=*h;
}







void printar(lista *h){

    while(h!=NULL){
        printf("[%d] ",h->c);
        h=h->prox;
    }
}


int main(){
int n, ti, c;
int i;

lista *h=NULL;

scanf("%d", &n);

for(i=0;i<n;i++){
    scanf("%d %d", &ti, &c);
    insereProcesso(ti,c,&h);
}
organizar(&h);
printar(h);
    return 0;
}