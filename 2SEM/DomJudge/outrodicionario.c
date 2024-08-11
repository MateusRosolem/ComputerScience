#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
    char pal[30];
    struct list *prox;
}Lista;





void insereLista(char *np,Lista **h){
Lista *adicionar, *aux, *antes;

adicionar = (Lista *)malloc(sizeof(Lista));
    strcpy(adicionar->pal,np);
  
    if(*h==NULL){//se nao tem nenhum elemento
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
        else if(strcmp(np,aux->pal)==0){
          return;
        }
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
    else if(strcmp(np,aux->pal)==0){
          return;
    }
    return;
}





void removeLista(char *np, Lista **h){
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





void listar(Lista *h, char *np){
Lista *aux, *antes;

  
if(h==NULL){ 
  printf("NULL\n");
  return;
}

    aux=antes=h;
    while(aux!=NULL && strcmp(np,aux->pal)>0){//ou sai porque chegou no ultimo elemento ou porque o elemento AUX eh maior que a palavra a ser inserida
        antes=aux;
        aux=aux->prox;
    }
    
    if (aux==NULL) 
    {
        printf("NULL\n");
        return;
    }
  
    while (aux!=NULL)
    {
        printf("%s ", aux->pal); // Imprimir as palavras a partir da que eu quero
        aux = aux->prox;
    }
    printf("\n");
    return;
    
}

  




int main() {
int i, n, m,op;
char pal[25];
Lista **h=NULL;

scanf("%d %d", &n, &m);//numero de palaras iniciais e numero de operações
if(n!=0){
  for(i=0;i<n;i++){
    scanf("%s", &pal);
    insereLista(pal, &h);
  }
}


  
for(i=0;i<m;i++){
  scanf("%d %s", &op, &pal);
  switch(op){
    case 0:removeLista(pal, &h);break;
    case 1:insereLista(pal, &h);break;
    case 2:listar(h, pal);break;
    default:break;
  }
}
  

  
  return 0;
}
