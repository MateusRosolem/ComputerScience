#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list{
    char pal[30];
    struct list *prox;
}Lista;


void Listinsere(char *np,Lista **h){
Lista *adicionar, *aux, *antes;

adicionar = (Lista *)malloc(sizeof(Lista));

    if(*h==NULL){//se nao tem nenhum elemento
        strcpy(adicionar->pal,np);
        adicionar->prox = NULL;
        *h=adicionar;
        return;
    }


    aux=antes=*h;
    while(aux->prox!=NULL && strcmp(np,aux->pal)>0){//ou sai porque chegou no ultimo elemento ou porque o elemento AUX eh maior que a palavra a ser inserida
        antes=aux;
        aux=aux->prox;
    }

    if(strcmp(np,aux->pal)==0)
        return;

    if (aux==*h) {//se só tem um elemento
        if(strcmp(np,aux->pal)>0){//se verdadeiro adiciona a direita
            aux->prox = adicionar;
            adicionar->prox = NULL;
        }
        else if(strcmp(np,aux->pal)<0){//senao, adiciona na esquerda
            adicionar->prox=aux;
            *h=adicionar;
        }
        strcpy(adicionar->pal,np);
        return;
    }


    if (strcmp(np,aux->pal)>0){
        adicionar->prox = aux->prox; //opcional?
        aux->prox = adicionar;
    }
    else if(strcmp(np,aux->pal)<0){
        antes->prox = adicionar;
        adicionar->prox = aux;
    }
    else
        return;
    strcpy(adicionar->pal,np);
    return;
}



void Listremover(char *np, Lista **h){
Lista *aux, *antes;

    if(*h==NULL)
        return;

    aux=antes=*h;
    while(aux->prox!=NULL && strcmp(np,aux->pal)!=0){//ou sai porque chegou no ultimo elemento ou porque o elemento AUX eh maior que a palavra a ser inserida
        antes=aux;
        aux=aux->prox;
    }


    if(strcmp(np,aux->pal)==0){//se achar a palavra a ser removida
        if(aux==(*h)){// se for remover o 1 elemento
            *h=aux->prox;
            free(aux);
            return;
        }
        antes->prox=aux->prox;//se tiver mais elementos
        free(aux);
        return;
    }
    else
        return;

} 


void printar(Lista *h){

    if(h==NULL){ 
        printf("NULL\n");
        return;
    }


    while (h!=NULL){
        printf("%s ", h->pal);
        h=h->prox;
    }
    printf("\n");
}



int main(){
int n, m, op;
int i;

Lista *h=NULL;
char ex[30];


scanf("%d %d", &n, &m);//numero de palavras iniciais e numero de operacoes


for(i=0;i<n;i++){
    scanf("%s", ex);
    Listinsere(ex, &h);
}

for(i=0;i<m;i++){
    scanf("%d %s", &op, ex);
    if(op){
        Listinsere(ex, &h);
    }
    else if(!op){
        Listremover(ex, &h);
        printar(h);
    }
}
    return 0;
}