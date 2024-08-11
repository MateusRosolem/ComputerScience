#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.c"

// Alunos: Mateus Rosolem Baroni e Leandro Aguiar Mota

int main(int argc, char *argv[])
{
  lista *l = malloc(sizeof(lista));
  int num, i, j = 0;
  tipo_chave x;
  tipo_elem dado;

  // Cadastro
  Definir(l);
  printf("Digite a quantidade de elementos ");
  scanf("%d", &num);

  for (i = 1; i <= num; i++)
  {
    printf("Digite o nome: ");
    scanf("%s", dado.info.nome);
    printf("\n");
    printf("Digite a idade: ");
    scanf("%d", &dado.info.idade);
    printf("\n");
    printf("Digite a media final: ");
    scanf("%f", &dado.info.media_final);
    printf("\n");
    printf("Digite o numero da chave: ");
    scanf("%d", &dado.chave);
    Inserir_posic(dado, i, l);
  }

  // Operação
  int op = -1;
  while (op != -1)
  {
    printf("\nEscolha uma das opcoes abaixo:\n");
    printf("1 - Buscar elemento\n");
    printf("2 - Remover elemento\n");
    printf("3 - Inserir elemento ordenado\n");
    printf("4 - Imprimir tamanho da lista\n");
    printf("5 - Imprimir dados de um elemento\n");
    printf("6 - Imprimir dados de toda a lista\n");
    printf("7 - Verificar se esta cheia\n");
    printf("8 - Verificar se esta vazia\n");
    printf("9 - Apagar a Lista\n");
    printf("0 - Sair\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      printf("Digite a chave do elemento a ser buscado: \n");
      scanf("%d", &x);
      if (Busca_bin(x, l, &j) == TRUE)
        printf("Elemento encontrado na posicao %d\n", j);
      else
        printf("elemento nao encontrado");
      break;

    case 2:
      printf("Digite a chave do elemento a ser removido\n");
      scanf("%d", &x);
      if (Remover_ch(x, l))
      {
        printf("Elemento removido\n");
        break;
      }
      else
        printf("elemento nao encontrado");
      break;

    case 3:
      printf("Digite o nome: ");
      scanf("%s", dado.info.nome);
      printf("\n");
      printf("Digite a idade: ");
      scanf("%d", &dado.info.idade);
      printf("\n");
      printf("Digite a media final: ");
      scanf("%f", &dado.info.media_final);
      printf("\n");
      printf("Digite o numero da chave: ");
      scanf("%d", &dado.chave);
      if (Inserir_ord(dado, l) == 0)
        printf("Lista cheia");
      break;

    case 4:
      printf("O Tamanho da lista eh de %d\n", Tamanho(l));
      break;

    case 5:
      printf("Digite o elemento a ser mostrado");
      scanf("%d", &x);
      if (Busca_bin(x, l, &j) == TRUE)
      {
        printf("O Nome do elemento eh: %s\n", l->A->info.nome);
        printf("A idade do elemento eh: %d\n", l->A->info.idade);
        printf("A media final do elemento eh: %f\n", l->A->info.media_final);
      }
      else
        printf("elemento nao encontrado");
      break;

    case 6:
      Imprimir(l);
      break;

    case 7:
      if (Cheia(l))
        printf("A lista está Cheia\n");
      else
        printf("A lista não está Cheia\n");
      break;

    case 8:
      if (Vazia(l))
        printf("A lista está Vazia\n");
      else
        printf("A lista não está Vazia\n");
      break;

    case 9:
      Apagar(l);
      printf("Lista apagada\n");
      break;

    case -1:
      break;
    }
  }

  return 0;
}
