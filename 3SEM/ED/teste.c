#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
struct no
{
    int valor;
    struct no *esquerda;
    struct no *direita;
};

// Função para criar um novo nó da árvore
struct no *criarNo(int valor)
{
    struct no *novoNo = (struct no *)malloc(sizeof(struct no));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para fazer uma rotação simples à esquerda em uma árvore binária
struct no *rotacaoEsquerda(struct no *p)
{
    struct no *q = p->direita;
    p->direita = q->esquerda;
    q->esquerda = p;
    return q;
}

// Função principal para testar a rotação à esquerda
int main()
{
    struct no *raiz = criarNo(1);
    raiz->esquerda = criarNo(2);
    raiz->direita = criarNo(3);
    raiz->direita->esquerda = criarNo(4);
    raiz->direita->direita = criarNo(5);

    printf("Árvore original:\n");
    printf("%d\n", raiz->valor);
    printf("%d %d\n", raiz->esquerda->valor, raiz->direita->valor);
    printf("  %d %d\n", raiz->direita->esquerda->valor, raiz->direita->direita->valor);

    raiz = rotacaoEsquerda(raiz);

    printf("\nÁrvore após rotação à esquerda:\n");
    printf("%d\n", raiz->valor);
    printf("%d %d\n", raiz->esquerda->valor, raiz->direita->valor);
    printf("  %d %d\n", raiz->direita->esquerda->valor, raiz->direita->direita->valor);

    return 0;
}
