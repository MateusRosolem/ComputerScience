#include <stdio.h>

typedef struct passenger
{
    char nome[50];
    int bilhete;
    struct passenger *prox;
}passageiros;

typedef struct Voo
{
    passageiros pass;
    int num_voo;
    struct voo *prox;
}voo;


void reserva(voo **h){
voo *novo, *aux, *antes;
novo=(voo *)malloc(sizeof(voo));
(novo->pass).bilhete=NULL;

    if(*h==NULL){
        (novo->pass).bilhete==1000;
        *h=novo;
        return;
    }

    return 0;
}



int main(){
int op;
voo *h=NULL;

printf("Menu de Opções:\n");
printf("1 - Reserva de Bilhete\n");
printf("2 - Cancelamento de Bilhete\n");
printf("3 - Verificação de Bilhete para X Pessoa\n");
printf("4 - Exibição dos passageiros\n");
scanf("%d", &op);

switch (op)
{
case 1:reserva();break;
case 2:cancelar();break;
case 3:procura();break;
case 4:listar();break;

default:return;break;
}



    /*Escreva um programa em c de reserva de bilhetes de uma linha aérea
    o programa exibe um menu com as seguintes opções:
    Reserva de bilhete, cancelamento de bilhete, verificação se um bilhete esta reservado para uma pessoa particular e exibição dos passageiros.
    A informação eh mantida alfabeticamente numa lista encadeada de nomes. Assuma que os bilhetes estao reservados para somente 1 voo.
    Crie uma lista encadeada de voos, com cada nó incluindo um ponteiro para uma lista ligada de passageiros.
    
    */

    return 0;
}