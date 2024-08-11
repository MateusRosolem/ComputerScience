#include <stdio.h>
#include <stdlib.h>

typedef struct list{
int ti;
int c;
struct list *prox;
struct list *prev;
}lista;




void insereProcesso(int ti, int c, lista **h){
lista *novo, *aux, *antes;

novo = (lista *)malloc(sizeof(lista));
novo->ti=ti;
novo->c=c;

    if(*h==NULL){// se tiver vazia

        novo->prox=NULL;
        novo->prev=NULL;
        *h=novo;
        return;
    }


    aux=antes=*h;
    while(aux->prox!=NULL && ti>(aux->ti)){// ou acabou a lista ou achou um tempo pra colocar
        antes=aux;
        aux=aux->prox;
    }


    if(aux==*h){//se for o unico elemento
        if(aux->ti > ti){//insere antes
            *h=novo;
            novo->prox=aux;
            aux->prev=novo;
            return;
        }
        //insere depois
        aux->prox=novo;
        novo->prev=aux;
        return;
    }
    //se adiciona no meio de antes e aux
    antes->prox=novo;
    novo->prev=antes;
    novo->prox=aux;
    aux->prev=novo;
    return;
//   18/11/18/19/15/10/17/10/10/16/16/13 ORDEM POR TEMPO MANDADO



}



void organizar(lista **h, int n){
    if(*h==NULL) return;


lista *aux, *antes, *cont;
aux=antes=*h;
cont=NULL;
int clock;


clock=aux->ti;
clock+=aux->c;

while(antes->prox){
    printf("\nI PASSOU\n");
    while(aux->prox!=NULL && antes->prox!=NULL){
        if(aux->ti==clock){
            (aux->prev)->prox=aux->prox;
            (aux->prox)->prev=aux->prev;

            aux->prox=antes->prox;
            (aux->prox)->prev=aux;
            antes->prox=aux;
            aux->prev=antes;
            cont=aux;

            clock+=aux->c;
            aux=aux->prox;
            printf("[[%d]]", (cont->c));
            break;
        }
        if(aux->ti < clock){ //tem um tratamento de dado que nao vo faze
            if(!cont && cont!=antes){
                cont=aux;
                // cont->prox=antes->prox;
                // (antes->prox)->prev=cont;
                // antes->prox=cont;
                // cont->prev=antes;
                            printf("[[%d]]", (cont->c));
            }
            else if(aux->c > cont->c){
                (aux->prev)->prox=aux->prox;
                (aux->prox)->prev=aux->prev;

                antes->prox=aux;
                aux->prev=antes;

                aux->prox=cont;
                cont->prev=aux;
                cont=aux;
            }
            else if(aux->c == cont->c){
                if(aux->ti > cont->ti){
                    (aux->prev)->prox=aux->prox;
                    (aux->prox)->prev=aux->prev;


                    aux->prox=aux->prev;
                    (aux->prox)->prev=aux;
                    cont->prox=aux;
                    aux->prev=cont;
                }
                else{
                    (aux->prev)->prox=aux->prox;
                    (aux->prox)->prev=aux->prev;

                    antes->prox=aux;
                    aux->prev=antes;
                    aux->prox=cont;
                    cont->prev=aux;
                }
            }
                        aux=aux->prox;
                printf("CONT:%d ", cont->c);
                printf("aux:%d\n", aux->c);

        }
        else{
            aux=aux->prox;
        }
    }
    printf("[[%d]]", (cont->c));
    if(aux->prox==NULL && cont!=antes)
        clock+=cont->c;
antes=antes->prox;
cont=aux=antes;
    
}




printf("oi\n \n");
for(int i=0;i<n;i++){
    cont=*h;
    printf("[[%d]]", (cont->c));
    cont=cont->prox;
}


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
organizar(&h,n);
printar(h);
    return 0;
}