#include <stdio.h>

typedef struct{
    char nome[20];
    struct lista *prox;
}lista;

lista frutas[200];

void insereProcesso(lista frutas[200], char *fr,int *h){
int i=1, j, antes;

    while(frutas[i].prox=!NULL && i<200) i++;//acha um lugar pra guarda a fruta
    if(i==200){ 
        puts("vetor está cheio");
        return;
    }
    strcpy(frutas[i].nome,fr);
    j=*h;
    while(j!=NULL && strcmp(frutas[j].nome,fr)<0){// ou chegou ou acabou o vetor e tem que inserir no ultimo
        antes=j;
        j=frutas[j].prox;
    }
    frutas[i].prox=j;

    if (j==*h)
        *h=i;
    else
        frutas[antes].prox=i;
}


void remove(lista frutas[200], char *fr, int *h){
int i=*h, j, antes;

    while(i>0 && strcmp(frutas[i].nome, fr)<0){ //i>o ou seja !=NULL  e o <0 sai quando for igual ou maior
        antes=i;
        i=frutas[i].prox;
    }

    if(strcmp(frutas[i].nome, fr)){
        puts("fruta nao existe");
        return;
    }

    frutas[antes].prox=frutas[i].prox; //o ponteiro do anterior aponta pro elemento depois do que vai remover
    if(i==*h) //se tiver um elemento só
        *h=frutas[i].prox; //Header zera
    frutas[i].prox=NULL; //opcional(vai tirar o apontamento do elemento que vai remover)
}



int main(){
lista *h;


    return 0;
}