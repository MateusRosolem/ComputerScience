#include <stdio.h>

typedef struct{
  Key elem;
  struct Fila *prox;
}Fila;



void InsereFila(Fila **h, Fila **t, Fila *elem){

//cabeca so serve pro caso se nao tem elementos
    if(*h==NULL){
        *h=*t=elem;
        return;
    }

    (*t)->prox=elem;
    (*t)=elem;
    return;
}


Fila *RemoveFila(Fila **h, Fila **t){// da o endereco do cara que eh removido pra usar ele
Fila *aux;

    if(*h==NULL){
        puts("fila vazia\n");
        return (NULL);
    }

    aux=*h;
    
    if(*h==*t)//so tem 1
        *h=*t=NULL;
    else
        (*h)=(*h)->prox;//tem varios elementos
    
    return *aux;
    
}

  
//Se tiver Prioridade ou mexe na funcao insere ou mexe na funcao remove

int main() {


  return 0;
}