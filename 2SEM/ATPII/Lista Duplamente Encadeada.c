#include <stdio.h>
//Lista encadeada simples tem o AUX que recebe o proximo da onde vc vai inserir e o ANTES que eh o ANTES da onde vc vai inserir



//LISTA DUPLAMENTE ENCADEADA
typedef struct dupla{
int indice; //KEY, nome, indice, numero,etc
char nome[10];
struct dupla *prox;//ponteiro pra frente
struct dupla *prev;//ponteiro pra trás
}Ldupla;


void inseredupla(Ldupla **h, Ldupla **t, Ldupla *elem){
Ldupla *aux;
int pos=1;


    if(*h==NULL){//se nao tiver elementos
    *h=*t=elem;
      return;
    }

    if(MelhorPonto(elem, *h,*t)<0){//Menor que 0 comeca da cabeca
        aux=*h;

        while(aux->prox && jachegou(elem,aux)) //1 ainda nao chegou e 0 chegou e insere antes ou depois
        aux=aux->prox;
        if(aux==*h){// se so tiver um elemento
            if(!JaChegou(elem,aux)){ //Insere Antes
                elem->prox=aux;
                elem->prev=NULL;
                aux->prev=elem;
                *h=elem;
            }
            else{//Insere Depois
                *t=elem;
                elem->prox=aux->prox;
                elem->prev=aux;
                aux->prox=elem;
            }
        }
        else{//Se tem mais de um elemento
            elem->prox=aux;
            elem->prev=aux->prev;
            aux->prev=elem;
            (elem->prev)->prox=elem;
        }
    }
    else if(MelhorPonto(elem, *h,*t)>0){
        aux=*t;
        //Tudo que eh prox vira prev e tudo whe eh prev vira prox
        // e a funcao ja chegou vai ter que funcionar ao contrario
    }
}





  








  

//key(chave de busca, nome ds fruta, numeros(indices)
void RemoveDupla(Ldupla **h,Ldupla **t, tipo1 key){
Ldupla *aux;
  
if(!h){//Se nao tiver elementos  
  puts("Lista Vazia");
  return;
  }

if(MelhorPonto(key,*h,*t)){
  aux=*h;
  while(JaChegou(key,aux,1))
    aux=aux->prox;
    //1 indica que vai da cabeca pra cauda,  esquerda pra direita
    //Ele busca e para, ou achou ou ou nao achou
    
  if(key==aux->key){// se parou de procurar no while e vc achou ,entao faca isso
    if(aux==*h){// se vc for remover o primeiro elemento
        *h=aux->prox;
        (aux->prox)->prev=NULL;
    }
    else// senao for, excluir a cabeca
        (aux->prev)->prox=aux->prox;
    
    if(*t==aux)// se tiver um elemento só
        *t=NULL;
    else
        (aux->prox)->prev=aux->prev;

  free(aux);
}
else
    printf("%k nao esta na na lista\n",key);//%k seria o tipo da chsve
}      
else{
  //FAZER PRA se for comecar da causa muda H por T E PROX por PREV
}
  
}

      

//funcao MAIS PROXIMO se cabeca for igual cauda, comeca pela cabeca
int main() {

  return 0;
}