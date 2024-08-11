 #include <stdio.h>

typedef struct circulo{
int i; //identificiador
int k;//Valor do próximo K
int o;//Operador(remoção==0 ou inserção==1)
struct dupla *prox;//ponteiro pra frente
}Lista;


void InsereCirc(Lista *ki, Lista *op, Lista **h){//Lista pra criar a lista circular
Lista *atual=(*h), *antes=(*h), *novo;
int ind=2;

novo = (Lista *)malloc(sizeof(Lista));

    if(!atual){//Se nao tiver elemento, a cabeca vai ser elemento
        (*h)=novo;
        novo->prox=novo;
        novo->i=1;
        novo->k=ki;
        novo->o=op;
        return;
    }

    
    novo->k=ki;//novo elemento recebe o K
    novo->o=op;//novo elemento recebe o O
    while(atual->prox!=*h){// roda enquanto o Atual for diferente de HEADER
        ind++; //aumenta o indice
        antes=atual; 
        atual=atual->prox;
    }
    novo->prox=atual->prox; 
    atual->prox=novo;
    novo->i=ind;
    return;

}

//Reinserir
void ReinsereCirc(Lista *antes, Lista *atual, Lista *ex){

    if(ex==NULL)
        return;
    
    ex->o=0;
    antes->prox=ex;

    return;
}


void RemoveCirc(Lista *atual,Lista *antes, Lista **h){
    printf("%d:H\n", **h);
    Lista *aux;
    aux=*h;

    if(aux->prox==aux)// se lista só tem um elemento(último caso)
        return;

    if(aux==atual)//se for remover o elemento que header ta apontando
        (*h)=atual->prox;

    antes->prox=atual->prox; //remove
    atual=atual->prox;
    printf("ATUAL:%d\n", *atual);
    return;
}



int rodar(Lista **h){ //Função pra executar as remoções e inserções
int j;
int num;
Lista *antes, *atual;
Lista *ex;
ex=NULL;
Lista *head;
head=*h;

Lista *point;

    point=antes=atual=*h;
    while(atual->prox!=atual){
        for(j=0; j<(point->k -1); j++){ //K-1 pois conta o elemento atual e a partir dele
            antes=atual; 
            atual=atual->prox;
        }


            printf("%d:atual\n\n",*atual);
            if(atual->o) //if op==1 Reinserir em seu lugar original(nao tira o ponteiro dele, so tira os apontamentos pra ele)
                ReinsereCirc(antes,atual,ex);
            else if(!(atual->o)){ //Se o==0, remover o elemento
                RemoveCirc(atual, antes, &head);
                ex=atual;
                point=atual;
            }
    }
    num=atual->i;
    return num;
}




int main(){
int n, i;
int k, o;
Lista *h=NULL;

scanf("%d", &n);//número de pessoas na lista
for(i=0;i<n;i++){
    scanf("%d %d", &k, &o);
    InsereCirc(k,o, &h);
}
printf("%d", rodar(&h));

    return 0;
}