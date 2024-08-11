#include <stdio.h>
#include <stdlib.h>

typedef struct fila{//Struct da fila
  int id;
  int tc;
  int te;
  struct fila *prox;
} Fila;


typedef struct centro{//struct do centro de distribuição
  int tempo;
  int tocioso;
  int total;
} Centro;


Fila *insere(){//Função que pega os elementos dados e transforma em um elemento tipo FILA e devolve ele
  int id,tc,te;
  Fila *aux;
  
  aux = (Fila *)malloc(sizeof(Fila));
  scanf("%d %d %d",&id,&tc,&te);

  aux->id = id;
  aux->tc = tc;
  aux->te = te;
  aux->prox = NULL;
  return aux;
}

void insereFila(Fila **h, Fila *elem) {//Função pra pegar deixar os elementos organizados em uma fila de acordo com sua ordem de chegada(e restrição quando o tempo de chegada for o mesmo)
Fila *antes,*atual;

  if(!(*h)){//se estiver vazia
    *h = elem;
    return;
  }

  antes=atual=*h;
  while(atual->prox && elem->tc > atual->tc){ //Coloca de acordo com o tempo de chegada
    antes=atual;
    atual=atual->prox;
  }

    if(atual == (*h)){//Caso só haja um elemento
      if(elem->tc>atual->tc){
          atual->prox = elem;
        }
      else if (elem->tc<atual->tc){
          elem->prox = atual;
          *h=elem;
      } 
      else if (elem->tc==atual->tc){
        if(elem->id<atual->id){
              elem->prox = atual;
              *h=elem;
        } 
        else{
          if(atual->prox != NULL && (atual->prox)->id < elem->id){
            atual = atual->prox;
            atual->prox = elem;
            return;
          }
          elem->prox = atual->prox;
          atual->prox = elem;
        }
      }
        return;
    }

    
    if((!(atual->prox)) && elem->tc > atual->tc) { //Caso o elemento seja adicionado no ultimo
        atual->prox = elem;
        return;
    }

  
    if(elem->tc == atual->tc){ //Restrição dos tempos iguais
      if(elem->id<atual->id){//Se for menor, adiciona na esquerda
        antes->prox = elem;
        elem->prox = atual;
      } 
      else{//Senão, adiciona na direita
        elem->prox = atual->prox;
        atual->prox = elem;
      }
      return;
    }

    antes->prox = elem;//Caso comum
    elem->prox = atual;
    return;
}




Fila *removeFila(Fila **h){//Remove o item para ser usado
    Fila *aux;

    if(!(*h)){//Lista vazia
      return NULL;
    }
  
    if ((*h)->prox == NULL){//Remoção do unico elemento
      aux = *h;
      *h = NULL;
      return aux;
    }

    aux = *h;//Caso comum
    *h = (*h)->prox;
    return aux;
}




int main() {
int i,n,m,*cont;
Fila *h=NULL,*aux;
Centro *centro;

cont = (int *)malloc(m*sizeof(int));
centro = (Centro *)malloc(m*sizeof(Centro));
  
scanf("%d %d",&n,&m);

  //For para inserir o elemento na lista ordenada
  for(i=0;i<n;i++){
    aux = insere();
    insereFila(&h,aux);
  }   



  for(i=0;i<m;i++){
    cont[i] = 0;
    centro[i].tempo = 0; 
    centro[i].total = 0;
    centro[i].tocioso = 0;
  }

    
  while(aux!=NULL){//While com contador descente, que pega o valor do tempo de cada elemento, conta o tempo ocioso, e faz as matemáticas para achar o valor final
    for(i=0;i<m;i++){
      if(centro[i].tempo == 0){
        aux = removeFila(&h);
        if (aux != NULL && centro[i].tocioso >= aux->tc){
          centro[i].total = centro[i].total + aux->te + cont[i];
          centro[i].tocioso = centro[i].tocioso + aux->te;
          centro[i].tempo = aux->te;
          cont[i] = 0;
        } 
        else if(aux != NULL){
          centro[i].tocioso++;
          cont[i]++;
          insereFila(&h,aux);
        }
      } 
      else{
        centro[i].tempo--;
      }   
    }
  } 


for(i=0;i<m;i++){
  printf("%d ",centro[i].total);
}

}