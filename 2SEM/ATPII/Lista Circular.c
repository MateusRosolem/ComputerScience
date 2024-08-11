 #include <stdio.h>
//LISTA CIRCULAR
//Usar lista circular no teclado(buffer circular) ou rede(pacotes de video)

typedef struct circulo{
int indice; //KEY, nome, indice, numero,etc
char nome[10];
struct dupla *prox;//ponteiro pra frente
}Lista;




void InsereCirc(Lista **h,Lista *elem){
Lista *atual=(*h), *antes=(*h);

    if(!atual){//Se nao tiver elemento, a cabeca vai ser elemento
        (*h)=elem; 
        return;
    }

    //elem->prox=elem( se tiver 1 elemento, ele mesmo se aponta )
    if((*h)->prox==(*h)){//So 1 elemento
    //o (*h) serve pra nao confundir (*h)->prox com *h->prox
        elem->prox=atual;
        atual->prox=elem;
        if(elem->key < atual->key)// ver se o que vai inserir eh maior ou menor que o existente
            (*h)=elem;
        return;
    }

    while(antes->prox!=*h && jaChegou(elem->key,atual->key)){
        antes=atual; atual=atual->prox;
    }
    //Mais de 1 elemento
    //primeiro teste, ve se o prox do ultimo elemento ja eh o primeiro elemento denovo
    //segundo teste ve onde vai enfia

    if(atual==*h && elem->key < atual->key){ //Inserir antes que o primeiro elemento e for menor que o primeiro elemento
        antes=atual->prox;
        while(antes->prox!=atual)//vai ter wue rodar a lista inteira dnv pro ultimo elemento apontar pro elemento inserido
        antes=antes->prox;
        antes->prox=elem;
        elem->prox=*h;
        *h=elem;
        return;
    } 
    //vai inserir entre dois  no meio da lista
    elem->prox=atual;
    antes->prox=elem;
    return;

//os IF nao tem ELSE porque tem RETURN dentro deles
}



void RemoveCirc(int **h, TipoK Key){
Lista *aux, *antes;

  if(*h==NULL){// se lista vazia
    puts("Lista Vazia");
    return;
  }

  aux=antes=*h;
  while(aux->prox!=h && Key>aux->Key){//ir ate o final OU numero do elemento maior que os anteriores(aux== para no que vai remover)
    antes=aux; 
    aux=aux->prox;
  }
  if(Key==aux->Key){//se achou o elemento pra remover
    if(aux->prox==aux){//ver se vai remover o unico elemento da lista
      *h==NULL;
      free(aux);
      return;
      }
    if(aux==antes){//ver se vai remover o primeiro elemento da lista
      antes=aux->prox;
      while(antes->prox!=*h)
        antes=antes->prox;
      antes->prox=aux->prox;
      *h=aux->prox;
      free(aux);
      return;
      }

    //Caso normal
    antes->prox=aux->prox;
    free(aux);
    return;
  }

  //se nao achou
  printf("%k nao esta na lista\n",key);
  return;
}



 int main(){


    return 0;
 }