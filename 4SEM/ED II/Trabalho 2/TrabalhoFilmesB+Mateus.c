#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

#define MAX_CHILD_NUMBER 3200

typedef struct BPlusTreeNode
{
    int isRoot, isLeaf;
    int key_num;
    int key[MAX_CHILD_NUMBER];
    int pos[MAX_CHILD_NUMBER];
    void *child[MAX_CHILD_NUMBER];
    struct BPlusTreeNode *father;
    struct BPlusTreeNode *next;
    struct BPlusTreeNode *last;
} BPlusTreeNode;

struct BPlusTreeNode *Root;

int MaxChildNumber = 50;
int TotalNodes;
int QueryAnsNum;

typedef struct{
    char code[6];
    char nomePort[65];  // Variável
    char nomeOrigi[65]; // Variável
    char diretor[25];   // Variável
    int ano;
    char pais[20]; // Variável
    int nota;
    int tam; // tamanho dos bytes( nao deve passar de 175)
} Filme;

typedef struct{
    char code[6];
    unsigned int rrn;
    struct indicePrim *esq;
    struct indicePrim *dir;
} indicePrim;

typedef struct{
    char titulo[50];
    char code[6];
    struct indiceSec *prox;
} indiceSec;






// Função para criar um nó da árvore
indicePrim *criarNo(char *code, int rrn)
{
    indicePrim *novono = (indicePrim *)malloc(sizeof(indicePrim));
    strcpy(novono->code, code);
    novono->rrn = rrn;
    novono->esq = NULL;
    novono->dir = NULL;
    return novono;
}

// Função para inserir um valor na árvore
indicePrim *inserir(indicePrim *raiz, indicePrim *novono)
{
    if (raiz == NULL)
    {
        return criarNo(novono->code, novono->rrn);
    }

    if (strcmp(novono->code, raiz->code) < 0)
    {
        raiz->esq = inserir(raiz->esq, novono);
    }
    else if (strcmp(novono->code, raiz->code) > 0)
    {
        raiz->dir = inserir(raiz->dir, novono);
    }
    return raiz;
}

// Função para contar elementos na árvore no índice primário
int contarElementos(indicePrim *raiz){
    if (raiz == NULL)
        return 0;
    else{
        // Recursivamente contar os elementos nas subárvores esquerda e direita
        int numEsq = contarElementos(raiz->esq);
        int numDir = contarElementos(raiz->dir);

        return 1 + numEsq + numDir;
    }
}
// Função para imprimir em ordem na árvore no índice primário
void imprimirEmOrdem(FILE *fppri, indicePrim *raiz){
    if (raiz != NULL){
        // Recursivamente imprime a subárvore esquerda
        imprimirEmOrdem(fppri, raiz->esq);

        // Imprime o valor do nó atual
        fprintf(fppri, "#%s", raiz->code);
        fprintf(fppri, "@%d", raiz->rrn);

        // Recursivamente imprime a subárvore direita
        imprimirEmOrdem(fppri, raiz->dir);
    }
}

// Função para criar um novo nó na lista encadeada do índice secundário
indiceSec *criarNovoNo(char *titulo, char *code){
    indiceSec *novoNo = (indiceSec *)malloc(sizeof(indiceSec));
    strcpy(novoNo->titulo,titulo);
    strcpy(novoNo->code, code);
    novoNo->prox = NULL;
    return novoNo;
}

// Função para inserir um elemento na lista encadeada de forma ordenada no índice secundário
void inserirOrdenado(indiceSec **head, char *titulo, char *code){
    indiceSec *novoNo = criarNovoNo(titulo,code);
    indiceSec *current = *head;
    indiceSec *next = *head;

    if (*head == NULL || strcmp(titulo,(*head)->titulo)<0)
    {
        novoNo->prox = *head;
        *head = novoNo;
    }else{
        while (current->prox != NULL && strcmp(next->titulo, titulo) < 0){
            current = current->prox;
            next = current->prox;
        }
        novoNo->prox = current->prox;
        current->prox = novoNo;
    }
}

// Função para imprimir os elementos da lista encadeada no índice secundário
void imprimirEmOrdemSec(FILE *fpsec, indiceSec *head){
    indiceSec *current = head;
    while (current != NULL){
        fprintf(fpsec, "#%d", head->titulo);
        fprintf(fpsec, "@%s", head->code);
        current = current->prox;
    }
}

// Função para liberar a memória da árvore no índice primário
void freeTree(indicePrim *raiz){
    if (raiz == NULL)return; // Caso base: árvore vazia

    freeTree(raiz->esq);
    freeTree(raiz->dir);
    // Liberar o próprio nó
    free(raiz);
}

// FUNÇÕES
// Inserir novo Filme
void inserirFilme(FILE *fppri, FILE *fpsec, FILE *fpdados, indicePrim *raiz)
{
    // dever ser inserido no final do arquivo de dados e atualizado nos  ́indices.
    Filme filme;
    int rrn = 0, flag;
    indicePrim *novono;

    printf("Digite o nome do filme em Portugues:");
    scanf(" %[^\n]", filme.nomePort);
    fflush(stdin);
    printf("\nDigite o nome do filme original:");
    scanf(" %[^\n]", filme.nomeOrigi);
    fflush(stdin);
    printf("\nDigite o Sobrenome e nome do diretor:");
    scanf(" %[^\n]", filme.diretor);
    fflush(stdin);
    do{
        printf("\nDigite o ano de lancamento:");
        scanf("%d", &filme.ano);
        if (filme.ano < 1900 || filme.ano > 2100) printf("Ano inválido. Tente novamente.\n");
    } while (filme.ano < 1900 || filme.ano > 2100);
    printf("\nDigite o pais do filme:");
    scanf(" %[^\n]", filme.pais);
    fflush(stdin);
    do
    {
        printf("\nDigite a nota do filme:[0 a 9]");
        scanf("%d", &filme.nota);
        if (filme.nota < 0 || filme.nota > 9)
            printf("Nota invalida. Tente novamente.\n");
    } while (filme.nota < 0 || filme.nota > 9);

    filme.code[0] = toupper(filme.diretor[0]);
    filme.code[1] = toupper(filme.diretor[1]);
    filme.code[2] = toupper(filme.diretor[2]);
    filme.code[3] = (filme.ano % 100) / 10 + '0';
    filme.code[4] = (filme.ano % 10) + '0';
    filme.code[5] = '\0';
    filme.tam = strlen(filme.nomePort) + strlen(filme.nomeOrigi) + strlen(filme.diretor) + strlen(filme.pais);
    if (filme.tam > 175){
        printf("Dados ultrapassam o limite de bytes! Por favor diminua");
    }else{
        fseek(fpdados, 0, SEEK_END); // Se nao usar append
        // Escreve os campos do filme no arquivo de dados
        fprintf(fpdados, "%5s@", filme.code);
        fprintf(fpdados, "%s@", filme.nomePort);
        fprintf(fpdados, "%s@", filme.nomeOrigi);
        fprintf(fpdados, "%s@", filme.diretor);
        fprintf(fpdados, "%d@", filme.ano);
        fprintf(fpdados, "%s@", filme.pais);
        fprintf(fpdados, "%d@", filme.nota);
        // Preenche com '#' até atingir 175 bytes
        while (filme.tam != 175){
            fprintf(fpdados, "#");
            filme.tam++;
        }
        printf("\n");

        // Obtém o número de elementos no índice primário para determinar o RRN
        rrn = contarElementos(raiz);
        raiz = inserir(raiz, criarNo(filme.code, rrn * 192));

        //Atualiza Flag
        fscanf(fppri, "%d", &flag);
        if(flag == 0) fprintf(fppri, "1", SEEK_SET);

        fprintf(fpsec, "#%s", filme.nomePort);
        fprintf(fpsec, "@%s", filme.code);
    }
}

// Função para remover um filme a partir de uma chave primária
void removerFilme(FILE *fppri, FILE *fpsec, FILE *fpdados){
    char chave[6],code[6], temp[32];
    int rrn, tamNum;
    char lixo;
    char carac;
    code[6]='\0';

    printf("Digite a chave do filme: \n");
    scanf("%s", chave);

    fseek(fppri, 1, SEEK_SET);
    do{
        fscanf(fppri, "%c", &lixo);
        fscanf(fppri, "%5[^@]@", code);
        fscanf(fppri, "%d", &rrn);

    } while (!feof(fppri) && strcmp(code, chave) != 0);


    if (strcmp(code, chave) == 0){ // Filme encontrado no índice primário
        printf("Filme localizado! DELETADO!\n");

        // não remover do indice primario
        // remover do arquivo de dados
        fseek(fpdados, rrn, SEEK_SET);
        fprintf(fpdados, "*|");// Marcando como excluído
                fseek(fppri, 0, SEEK_SET);
                fprintf(fppri, "1"); // Atualizar a flag do índice primári
    }else{
        printf("Filme nao localizado!");
    }
}

// Função para mudar a nota de um filme
void mudarNota(FILE *fppri, FILE *fpdados)
{
    char chave[6];
    int code[6], rrn;
    int del = 0, nota=0; // numero de delimitadores
    char car, lixo;

    // BUSCA DA CHAVE
    printf("Digite a chave do filme que deseja mudar a nota: \n");
    scanf("%s", chave);

    fseek(fppri, 1, SEEK_SET);
    do
    {
        fscanf(fppri, "%c", &lixo);
        fscanf(fppri, "%5[^@]@", code);
        fscanf(fppri, "%d", &rrn);
        printf("Valor de lixo: %c\n", lixo);
        printf("Valor de code: %s\n", code);
        printf("Valor de lixo: %c\n", lixo);
        printf("Valor de rrn: %d\n", rrn);

    } while (!feof(fppri) && strcmp(code, chave) != 0);

    if (strcmp(code, chave) == 0) // Filme encontrado no índice primário
    { // achou ele pelo indice
        printf("Filme localizado!\n");

        // MUDANÇA DE NOTA
        printf("Para qual nota deseja mudar o filme[0-9]?\n");
        scanf("%d", &nota); // ler numero da nota
        // Busca pelo campo nota no arquivo de dados
        fseek(fpdados, rrn, SEEK_SET);
        while (del != 6){
            fscanf(fpdados, "%c", &car);
            if (car=='@'){
                del++;
            }
        }

        fprintf(fpdados, "%d", nota); // Atualiza a nota no arquivo de dados
        printf("Nota Alterada!\n");
    }
    else{
        printf("Filme nao localizado!");
        return;
    }
}

// Função para buscar um filme pelo índice primário ou secundário
void buscarFilme(FILE *fppri, FILE *fpsec, FILE *fpdados)
{
    int opt;
    char codigo[6], code[6], titulo[65], tituloDados[65], lixo;
    int i = 0, rrn=0;
    Filme filme;

    printf("Deseja buscar pela chave[1] ou pelo titulo[2]?\n");
    scanf("%d", &opt);
    if (opt == 1){
        printf("Digite a chave do filme: ");
        scanf("%s", codigo);

        // Busca no índice primário
        fseek(fppri,1,SEEK_SET);
        do{
            fscanf(fppri, "%c" , &lixo);
            fscanf(fppri, "%5[^@]@", code);
            fscanf(fppri, "%d", &rrn);

        }while (!feof(fppri) && strcmp(code, codigo) != 0);

        

        if (strcmp(code, codigo) == 0){
            printf("Filme localizado!\n");

            // Ler o registro no arquivo de dados a partir do RRN obtido
            fseek(fpdados,rrn,SEEK_SET);
            printf("RRN %d", rrn);

            // Leitura e impressão dos campos
            fscanf(fpdados, "%5[^@]@", filme.code);
            fscanf(fpdados, "%[^@]@s", filme.nomePort);
            fscanf(fpdados, "%[^@]@s", filme.nomeOrigi);
            fscanf(fpdados, "%[^@]@s", filme.diretor);
            fscanf(fpdados, "%d%c", &filme.ano, &lixo);
            fscanf(fpdados, "%[^@]@s", filme.pais);
            fscanf(fpdados, "%d%c", &filme.nota, &lixo);

            printf("Codigo: %s\n", filme.code);
            printf("Titulo Portugues: %s\n", filme.nomePort);
            printf("Titulo Original: %s\n", filme.nomeOrigi);
            printf("Diretor: %s\n", filme.diretor);
            printf("Ano: %d\n", filme.ano);
            printf("Pais: %s\n", filme.pais);
            printf("Nota: %d\n", filme.nota);
        }
        else
        {
            printf("Filme nao localizado!");
        }
    }
    else if (opt == 2){
        printf("Digite o titulo do filme: ");
        scanf(" %[^\n]", tituloDados);

        // Busca no índice secundário
        fseek(fpdados,0,SEEK_SET);
        do{
            if (i != 0){
                fseek(fpdados, 192 * i, SEEK_SET); // Code=5 @=1      // rrn = (185 - strlen(titulo))+192*i;
            }
            fseek(fpdados, 6, SEEK_CUR);
            fscanf(fpdados, "%[^@]@", titulo);
            i++;
        } while (!feof(fpdados) && strcmp(titulo, tituloDados) != 0);

        if (strcmp(titulo, tituloDados) == 0)
        { // Verificacao dois titulos iguais
            printf("Filme localizado!\n");
            Filme filme;
            fseek(fpdados, 192*(i-1), SEEK_SET); // Code=5 @=1
            // Leitura e impressão dos campos
            fscanf(fpdados, "%5[^@]@", filme.code);
            fscanf(fpdados, "%[^@]@s", filme.nomePort);
            fscanf(fpdados, "%[^@]@s", filme.nomeOrigi);
            fscanf(fpdados, "%[^@]@s", filme.diretor);
            fscanf(fpdados, "%d%c", &filme.ano);
            fscanf(fpdados, "%[^@]@s", filme.pais);
            fscanf(fpdados, "%d%c", &filme.nota);

            printf("Codigo: %s\n", filme.code);
            printf("Titulo Portugues: %s\n", filme.nomePort);
            printf("Titulo Original: %s\n", filme.nomeOrigi);
            printf("Diretor: %s\n", filme.diretor);
            printf("Ano: %d\n", filme.ano);
            printf("Pais: %s\n", filme.pais);
            printf("Nota: %d\n", filme.nota);
        }
        else
        {
            printf("Filme nao localizado!");
        }
    }
}

void listarFilmes(FILE *fppri, FILE *fpsec, FILE *fpdados, indicePrim *raiz)
{
    printf("Listando filmes...\n");
    fseek(fpdados, 0, SEEK_SET);
    Filme filme;

    for(int i = 0; i < contarElementos(raiz); i++){
        fscanf(fpdados, "%5[^@]@", filme.code);
        fscanf(fpdados, "%[^@]@s", filme.nomePort);
        fscanf(fpdados, "%[^@]@s", filme.nomeOrigi);
        fscanf(fpdados, "%[^@]@s", filme.diretor);
        fscanf(fpdados, "%d@", &filme.ano);
        fscanf(fpdados, "%[^@]@", filme.pais);
        fscanf(fpdados, "%d%[^@]@", &filme.nota);
        filme.tam = strlen(filme.nomePort) + strlen(filme.nomeOrigi) + strlen(filme.diretor) + strlen(filme.pais);
        fseek(fpdados, 192-(16+filme.tam), SEEK_CUR);

        // Ler os caracteres extras até o final do registro (192 bytes)
    
        printf("/-------------------------------------------/\n");
        printf("Codigo: %s\n", filme.code);
        printf("Titulo Portugues: %s\n", filme.nomePort);
        printf("Titulo Original: %s\n", filme.nomeOrigi);
        printf("Diretor: %s\n", filme.diretor);
        printf("Ano: %d\n", filme.ano);
        printf("Pais: %s\n", filme.pais);
        printf("Nota: %d\n", filme.nota);
        printf("/-------------------------------------------/\n");
        
    }
}

void finalizar(FILE *fppri, FILE *fpsec, FILE *fpdados, indicePrim *raiz,indiceSec *head)
{
    int flag=0;

    fseek(fppri, 0, SEEK_SET);
    fprintf(fppri,"0");
    fseek(fppri,1,SEEK_SET);
    imprimirEmOrdem(fppri, raiz);

    // Fecha os aqruivos
    fclose(fpdados);
    fclose(fpsec);
    fclose(fppri);

    // Liberar memoria alocada
    freeTree(raiz);
    return;
}



























/** Create a new B+tree Node */
BPlusTreeNode *New_BPlusTreeNode()
{
    struct BPlusTreeNode *p = (struct BPlusTreeNode *)malloc(sizeof(struct BPlusTreeNode));
    p->isRoot = false;
    p->isLeaf = false;
    p->key_num = 0;
    p->child[0] = NULL;
    p->father = NULL;
    p->next = NULL;
    p->last = NULL;
    TotalNodes++;
    return p;
}

/** Binary search to find the biggest child l that Cur->key[l] <= key */
int Binary_Search(BPlusTreeNode *Cur, int key)
{
    int l = 0, r = Cur->key_num;
    if (key < Cur->key[l])
        return l;
    if (Cur->key[r - 1] <= key)
        return r - 1;
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (Cur->key[mid] > key)
            r = mid;
        else
            l = mid;
    }
    return l;
}

/**
 * Cur(MaxChildNumber) split into two part:
 *	(1) Cur(0 .. Mid - 1) with original key
 *	(2) Temp(Mid .. MaxChildNumber) with key[Mid]
 * where Mid = MaxChildNumber / 2
 * Note that only when Split() is called, a new Node is created
 */
void Insert(BPlusTreeNode *, int, int, void *);
void Split(BPlusTreeNode *Cur)
{
    // copy Cur(Mid .. MaxChildNumber) -> Temp(0 .. Temp->key_num)
    BPlusTreeNode *Temp = New_BPlusTreeNode();
    BPlusTreeNode *ch;
    int Mid = MaxChildNumber >> 1;
    Temp->isLeaf = Cur->isLeaf; // Temp's depth == Cur's depth
    Temp->key_num = MaxChildNumber - Mid;
    int i;
    for (i = Mid; i < MaxChildNumber; i++)
    {
        Temp->child[i - Mid] = Cur->child[i];
        Temp->key[i - Mid] = Cur->key[i];
        if (Temp->isLeaf)
        {
            Temp->pos[i - Mid] = Cur->pos[i];
        }
        else
        {
            ch = (BPlusTreeNode *)Temp->child[i - Mid];
            ch->father = Temp;
        }
    }
    // Change Cur
    Cur->key_num = Mid;
    // Insert Temp
    if (Cur->isRoot)
    {
        // Create a new Root, the depth of Tree is increased
        Root = New_BPlusTreeNode();
        Root->key_num = 2;
        Root->isRoot = true;
        Root->key[0] = Cur->key[0];
        Root->child[0] = Cur;
        Root->key[1] = Temp->key[0];
        Root->child[1] = Temp;
        Cur->father = Temp->father = Root;
        Cur->isRoot = false;
        if (Cur->isLeaf)
        {
            Cur->next = Temp;
            Temp->last = Cur;
        }
    }
    else
    {
        // Try to insert Temp to Cur->father
        Temp->father = Cur->father;
        Insert(Cur->father, Cur->key[Mid], -1, (void *)Temp);
    }
}

/** Insert (key, value) into Cur, if Cur is full, then split it to fit the definition of B+tree */
void Insert(BPlusTreeNode *Cur, int key, int pos, void *value)
{
    int i, ins;
    if (key < Cur->key[0])
        ins = 0;
    else
        ins = Binary_Search(Cur, key) + 1;
    for (i = Cur->key_num; i > ins; i--)
    {
        Cur->key[i] = Cur->key[i - 1];
        Cur->child[i] = Cur->child[i - 1];
        if (Cur->isLeaf)
            Cur->pos[i] = Cur->pos[i - 1];
    }
    Cur->key_num++;
    Cur->key[ins] = key;
    Cur->child[ins] = value;
    Cur->pos[ins] = pos;
    if (Cur->isLeaf == false)
    { // make links on leaves
        BPlusTreeNode *firstChild = (BPlusTreeNode *)(Cur->child[0]);
        if (firstChild->isLeaf == true)
        { // which means value is also a leaf as child[0]
            BPlusTreeNode *temp = (BPlusTreeNode *)(value);
            if (ins > 0)
            {
                BPlusTreeNode *prevChild;
                BPlusTreeNode *succChild;
                prevChild = (BPlusTreeNode *)Cur->child[ins - 1];
                succChild = prevChild->next;
                prevChild->next = temp;
                temp->next = succChild;
                temp->last = prevChild;
                if (succChild != NULL)
                    succChild->last = temp;
            }
            else
            {
                // do not have a prevChild, then refer next directly
                // updated: the very first record on B+tree, and will not come to this case
                temp->next = Cur->child[1];
                printf("this happens\n");
            }
        }
    }
    if (Cur->key_num == MaxChildNumber) // children is full
        Split(Cur);
}

/** Resort(Give, Get) make their no. of children average */
void Resort(BPlusTreeNode *Left, BPlusTreeNode *Right)
{
    int total = Left->key_num + Right->key_num;
    BPlusTreeNode *temp;
    if (Left->key_num < Right->key_num)
    {
        int leftSize = total >> 1;
        int i = 0, j = 0;
        while (Left->key_num < leftSize)
        {
            Left->key[Left->key_num] = Right->key[i];
            Left->child[Left->key_num] = Right->child[i];
            if (Left->isLeaf)
            {
                Left->pos[Left->key_num] = Right->pos[i];
            }
            else
            {
                temp = (BPlusTreeNode *)(Right->child[i]);
                temp->father = Left;
            }
            Left->key_num++;
            i++;
        }
        while (i < Right->key_num)
        {
            Right->key[j] = Right->key[i];
            Right->child[j] = Right->child[i];
            if (Right->isLeaf)
                Right->pos[j] = Right->pos[i];
            i++;
            j++;
        }
        Right->key_num = j;
    }
    else
    {
        int leftSize = total >> 1;
        int i, move = Left->key_num - leftSize, j = 0;
        for (i = Right->key_num - 1; i >= 0; i--)
        {
            Right->key[i + move] = Right->key[i];
            Right->child[i + move] = Right->child[i];
            if (Right->isLeaf)
                Right->pos[i + move] = Right->pos[i];
        }
        for (i = leftSize; i < Left->key_num; i++)
        {
            Right->key[j] = Left->key[i];
            Right->child[j] = Left->child[i];
            if (Right->isLeaf)
            {
                Right->pos[j] = Left->pos[i];
            }
            else
            {
                temp = (BPlusTreeNode *)Left->child[i];
                temp->father = Right;
            }
            j++;
        }
        Left->key_num = leftSize;
        Right->key_num = total - leftSize;
    }
}

/**
 * Redistribute Cur, using following strategy:
 * (1) resort with right brother
 * (2) resort with left brother
 * (3) merge with right brother
 * (4) merge with left brother
 * in that case root has only one child, set this chil to be root
 */


//void Delete(BPlusTreeNode *, int);
void Delete(BPlusTreeNode *Cur, int key)
{
    int i, del = Binary_Search(Cur, key);
    void *delChild = Cur->child[del];
    for (i = del; i < Cur->key_num - 1; i++)
    {
        Cur->key[i] = Cur->key[i + 1];
        Cur->child[i] = Cur->child[i + 1];
        if (Cur->isLeaf)
            Cur->pos[i] = Cur->pos[i + 1];
    }
    Cur->key_num--;
    if (Cur->isLeaf == false)
    { // make links on leaves
        BPlusTreeNode *firstChild = (BPlusTreeNode *)(Cur->child[0]);
        if (firstChild->isLeaf == true)
        { // which means delChild is also a leaf
            BPlusTreeNode *temp = (BPlusTreeNode *)delChild;
            BPlusTreeNode *prevChild = temp->last;
            BPlusTreeNode *succChild = temp->next;
            if (prevChild != NULL)
                prevChild->next = succChild;
            if (succChild != NULL)
                succChild->last = prevChild;
        }
    }
    if (del == 0 && !Cur->isRoot)
    { // some fathers' key should be changed
        BPlusTreeNode *temp = Cur;
        while (!temp->isRoot && temp == temp->father->child[0])
        {
            temp->father->key[0] = Cur->key[0];
            temp = temp->father;
        }
        if (!temp->isRoot)
        {
            temp = temp->father;
            int i = Binary_Search(temp, key);
            temp->key[i] = Cur->key[0];
        }
    }
    free(delChild);
    if (Cur->key_num * 2 < MaxChildNumber)
        Redistribute(Cur);
}

void Redistribute(BPlusTreeNode *Cur)
{
    if (Cur->isRoot)
    {
        if (Cur->key_num == 1 && !Cur->isLeaf)
        {
            Root = Cur->child[0];
            Root->isRoot = true;
            free(Cur);
        }
        return;
    }
    BPlusTreeNode *Father = Cur->father;
    BPlusTreeNode *prevChild;
    BPlusTreeNode *succChild;
    BPlusTreeNode *temp;
    int my_index = Binary_Search(Father, Cur->key[0]);
    
    if (my_index + 1 < Father->key_num)
    {
        succChild = Father->child[my_index + 1];
        if ((succChild->key_num - 1) * 2 >= MaxChildNumber)
        {                           // at least can move one child to Cur
            Resort(Cur, succChild); // (1) resort with right child
            Father->key[my_index + 1] = succChild->key[0];
            return;
        }
    }
    if (my_index - 1 >= 0)
    {
        prevChild = Father->child[my_index - 1];
        if ((prevChild->key_num - 1) * 2 >= MaxChildNumber)
        {
            Resort(prevChild, Cur); // (2) resort with left child
            Father->key[my_index] = Cur->key[0];
            return;
        }
    }
    if (my_index + 1 < Father->key_num)
    { // (3) merge with right child
        int i = 0;
        while (i < succChild->key_num)
        {
            Cur->key[Cur->key_num] = succChild->key[i];
            Cur->child[Cur->key_num] = succChild->child[i];
            if (Cur->isLeaf)
            {
                Cur->pos[Cur->key_num] = succChild->pos[i];
            }
            else
            {
                temp = (BPlusTreeNode *)(succChild->child[i]);
                temp->father = Cur;
            }
            Cur->key_num++;
            i++;
        }
        Delete(Father, succChild->key[0]); // delete right child
        return;
    }
    if (my_index - 1 >= 0)
    { // (4) merge with left child
        int i = 0;
        while (i < Cur->key_num)
        {
            prevChild->key[prevChild->key_num] = Cur->key[i];
            prevChild->child[prevChild->key_num] = Cur->child[i];
            if (Cur->isLeaf)
            {
                prevChild->pos[prevChild->key_num] = Cur->pos[i];
            }
            else
            {
                temp = (BPlusTreeNode *)(Cur->child[i]);
                temp->father = prevChild;
            }
            prevChild->key_num++;
            i++;
        }
        Delete(Father, Cur->key[0]); // delete left child
        return;
    }
    printf("What?! you're the only child???\n"); // this won't happen
}

/** Find a leaf node that key lays in it
 *	modify indicates whether key should affect the tree
 */
BPlusTreeNode *Find(int key, int modify)
{
    BPlusTreeNode *Cur = Root;
    while (1)
    {
        if (Cur->isLeaf == true)
            break;
        if (key < Cur->key[0])
        {
            if (modify == true)
                Cur->key[0] = key;
            Cur = Cur->child[0];
        }
        else
        {
            int i = Binary_Search(Cur, key);
            Cur = Cur->child[i];
        }
    }
    return Cur;
}

/** Print subtree whose root is Cur */
void Print(BPlusTreeNode *Cur)
{
    int i;
    for (i = 0; i < Cur->key_num; i++)
        printf("%d ", Cur->key[i]);
    printf("\n");
    if (!Cur->isLeaf)
    {
        for (i = 0; i < Cur->key_num; i++)
            Print(Cur->child[i]);
    }
}

/** Interface: Insert (key, value) into B+tree */
int BPlusTree_Insert(int key, int pos, void *value)
{
    BPlusTreeNode *Leaf = Find(key, true);
    int i = Binary_Search(Leaf, key);
    if (Leaf->key[i] == key)
        return false;
    Insert(Leaf, key, pos, value);
    return true;
}

/** Interface: query all record whose key satisfy that key = query_key */
void BPlusTree_Query_Key(int key)
{
    BPlusTreeNode *Leaf = Find(key, false);
    QueryAnsNum = 0;
    int i;
    for (i = 0; i < Leaf->key_num; i++)
    {
        // printf("%d ", Leaf->key[i]);
        if (Leaf->key[i] == key)
        {
            QueryAnsNum++;
            if (QueryAnsNum < 20)
                printf("[no.%d	key = %d, value = %s]\n", QueryAnsNum, Leaf->key[i], (char *)Leaf->child[i]);
        }
    }
    printf("Total number of answers is: %d\n", QueryAnsNum);
}

/** Interface: query all record whose key satisfy that query_l <= key <= query_r */
void BPlusTree_Query_Range(int l, int r)
{
    BPlusTreeNode *Leaf = Find(l, false);
    QueryAnsNum = 0;
    int i;
    for (i = 0; i < Leaf->key_num; i++)
    {
        // printf("%d ", Leaf->key[i]);
        if (Leaf->key[i] >= l)
            break;
    }
    int finish = false;
    while (!finish)
    {
        while (i < Leaf->key_num)
        {
            if (Leaf->key[i] > r)
            {
                finish = true;
                break;
            }
            QueryAnsNum++;
            if (QueryAnsNum == 20)
                printf("...\n");
            if (QueryAnsNum < 20)
                printf("[no.%d	key = %d, value = %s]\n", QueryAnsNum, Leaf->key[i], (char *)Leaf->child[i]);
            i++;
        }
        if (finish || Leaf->next == NULL)
            break;
        Leaf = Leaf->next;
        i = 0;
    }
    printf("Total number of answers is: %d\n", QueryAnsNum);
}

/** Interface: Find the position of given key */
int BPlusTree_Find(int key)
{
    BPlusTreeNode *Leaf = Find(key, false);
    int i = Binary_Search(Leaf, key);
    if (Leaf->key[i] != key)
        return -1; // don't have this key
    return Leaf->pos[i];
}

/** Interface: modify value on the given key */
void BPlusTree_Modify(int key, void *value)
{
    BPlusTreeNode *Leaf = Find(key, false);
    int i = Binary_Search(Leaf, key);
    if (Leaf->key[i] != key)
        return; // don't have this key
    printf("Modify: key = %d, original value = %s, new value = %s\n", key, (char *)(Leaf->child[i]), (char *)(value));
    free(Leaf->child[i]);
    Leaf->child[i] = value;
}

/** Interface: delete value on the given key */
void BPlusTree_Delete(int key)
{
    BPlusTreeNode *Leaf = Find(key, false);
    int i = Binary_Search(Leaf, key);
    if (Leaf->key[i] != key)
        return; // don't have this key
    printf("Delete: key = %d, original value = %s\n", key, (char *)(Leaf->child[i]));
    Delete(Leaf, key);
}

/** Interface: Called to destroy the B+tree */
void BPlusTree_Destroy()
{
    if (Root == NULL)
        return;
    printf("Now destroying B+tree ..\n");
    //Destroy(Root);
    Root = NULL;
    printf("Done.\n");
}

/** Interface: Initialize */
void BPlusTree_Init()
{
    //BPlusTree_Destroy();
    Root = New_BPlusTreeNode();
    Root->isRoot = true;
    Root->isLeaf = true;
    TotalNodes = 0;
}

/**
 * Interface: setting MaxChildNumber in your program
 * A suggest value is cube root of the no. of records
 */
void BPlusTree_SetMaxChildNumber(int number)
{
    MaxChildNumber = number + 1;
}

/** Interface: print the tree (DEBUG use)*/
void BPlusTree_Print()
{
    struct BPlusTreeNode *Leaf = Find(1000000000, false);
    int cnt = 0;
    while (Leaf != NULL)
    {
        int i;
        for (i = Leaf->key_num - 1; i >= 0; i--)
        {
            printf("%4d ", Leaf->key[i]);
            if (++cnt % 20 == 0)
                printf("\n");
        }
        Leaf = Leaf->last;
    }
}

/** Interface: Total Nodes */
int BPlusTree_GetTotalNodes()
{
    return TotalNodes;
}






















int main(){


BPlusTree_Init();
BPlusTree_SetMaxChildNumber(4);
BPlusTree_Insert(5,Root,100);
BPlusTree_Insert(8, Root, 100);
BPlusTree_Insert(18, Root, 100);
BPlusTree_Insert(12, Root, 100);
BPlusTree_Insert(6, Root, 100);

FILE *fppri, *fpsec, *fpdados; // Ponteiro pro indice primario, secundarios e dados
indicePrim *raiz = NULL;
indiceSec *head = NULL;
int op = 0, flag = 0, flagDados = 0;
char code[5], lixo, titulo[65];
int rrn = 0, i = 0;

// Verificação se existe um arquivo de dados.
if (!(fpdados = fopen("./movies.dat", "r+")))
{ // Se nao existe ele entra
    fpdados = fopen("./movies.dat", "w+");
    flagDados = 1;
    }

    // Verificação se existem os arquivos de índice.
    if (!(fppri = fopen("./iprimary.idx", "r+"))){ // Se nao existe ele entra
        fppri = fopen("./iprimary.idx", "w+");
        fseek(fppri, 0, SEEK_SET);
        fprintf(fppri, "0");

        // Passar Codigo e RRN dos dados para o indice primario
        fseek(fpdados, 0, SEEK_SET);
        if(flagDados==0){
            while ((fread(code, sizeof(char), 5, fpdados) == 5))
            {                                                 // Busca os dados
                fscanf(fpdados, "%5[^@]@", code);             // Le do arquivo de dados
                raiz = inserir(raiz, criarNo(code, i * 192)); // Gravar indices na RAM
                fseek(fpdados, 192 - 5, SEEK_CUR);
            }
            // Printa no indice primario
            imprimirEmOrdem(fppri, raiz);
        }
    }else{//Se existe
        fseek(fppri, 0, SEEK_SET);
        fscanf(fppri, "%d", &flag);

        if (flag == 0)
        { // Verificar cabeçalho se estiver consistente
            // Carregar indices pra RAM
            fseek(fppri, 1, SEEK_SET);
            while (fscanf(fppri, "%c", &lixo) == 1){
                fscanf(fppri, "%5[^@]@", code); // Ler codigo do filme
                fscanf(fppri, "%c%d", &lixo, &rrn);
                raiz = inserir(raiz, criarNo(code, rrn));
            }
        }
        else if (flag == 1)
        {// Coloca flag
            fseek(fppri, 0, SEEK_SET);
            fseek(fpdados, 0, SEEK_SET);

            while (fscanf(fpdados, "%5[^@]@", &code) == 1){ // Busca os dados e le do arquivo
                raiz = inserir(raiz, criarNo(code, i * 192)); // Gravar indices na RAM
                i++;
                fseek(fpdados, i * 192, SEEK_SET);
            }
            // Altera a flag
            fseek(fppri, 0, SEEK_SET);
            fprintf(fppri, "0");

            // Printa no indice primario
            imprimirEmOrdem(fppri, raiz); 
        }
    }
i=0;
    // Verificação se existe um indice secundario
    if (!(fpsec = fopen("./ititles.idx", "r+"))){ // Se nao existe
        fpsec = fopen("./ititles.idx", "w+");
        
        fseek(fpsec, 0, SEEK_SET);
        fprintf(fpsec, "0");

        // Passar Codigo e RRN dos dados para o indice primario
        fseek(fpdados, 0, SEEK_SET);
        if(flagDados==0){
            while ((fread(code, sizeof(char), 5, fpdados) == 5))   {
                fscanf(fpdados, "%5[^@]@", code);
                fscanf(fpdados, "%c", &lixo);  // Le do arquivo de dados
                fscanf(fpdados, "%[^@]@", titulo); // Busca os dados
                head = inserir(head, criarNovoNo(titulo, code)); // Gravar indices na RAM
                fseek(fpdados, 192 - (5 + strlen(titulo)), SEEK_CUR);
            }
        }
            // Printa no indice secundario
            imprimirEmOrdemSec(fpsec, head);
    }else{
        fseek(fpsec, 0, SEEK_SET);
        fscanf(fpsec, "%d", &flag);
        if (flag == 0) { // Verificar cabeçalho se estiver consistente
            // Carregar indices pra RAM
            fseek(fpsec, 1, SEEK_SET);
            while (fscanf(fpsec, "%c", &lixo) == 1){
                fscanf(fpsec, "%[^@]@", titulo); // Busca os dados
                fscanf(fpsec, "%d", &lixo);
                fscanf(fpsec, "%5[^@]@", code);  // Le do arquivo de dados
                head = inserir(head, criarNovoNo(titulo,code));
            }
        }
        else if (flag == 1){
            // Coloca flag
            fseek(fpsec, 0, SEEK_SET);
            fseek(fpdados, 0, SEEK_SET);

            while (fscanf(fpdados, "%5[^@]@", &code) == 1){// Busca os dados e le do arquivo
                fscanf(fpsec, "%c", &lixo);
                fscanf(fpsec, "%[^@]@", titulo);                // Busca os dados
                head = inserir(head, criarNovoNo(titulo,code)); // Gravar indices na RAM
                i++;
                fseek(fpdados, i * 192, SEEK_SET);
            }
            // Altera a flag
            fseek(fpsec, 0, SEEK_SET);
            fprintf(fpsec, "0");

            // Printa no indice primario
            imprimirEmOrdemSec(fpsec, head); // PRECISAORDENAR?
            // CRIAR INDICE SECUNDARIO
        }
    }

    while (op != 6)
    {
        printf("\n\nBem vindo ao Catalogo de Filmes da UNESP! Oque deseja fazer?\n");
        printf("1-Inserir Filme\n");
        printf("2-Remover Filme\n");
        printf("3-Buscar Filme\n");
        printf("4-Mudar Nota do Filme\n");
        printf("5-Listar Filmes\n");
        printf("6-Finalizar\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            inserirFilme(fppri, fpsec, fpdados, raiz);
            break;
        case 2:
            removerFilme(fppri, fpsec, fpdados);
            break;
        case 3:
            buscarFilme(fppri, fpsec, fpdados);
            break;
        case 4:
            mudarNota(fppri, fpdados);
            break;
        case 5:
            listarFilmes(fppri, fpsec, fpdados, raiz);
            break;
        case 6:
            finalizar(fppri, fpsec, fpdados, raiz, head);
            break;
        }
        if (flag = 0 && (op == 1 || op == 2 | op == 3 | op == 4)){
            flag = 1; // FLAG 1 = ALTERADO
            fseek(fppri, 0, SEEK_SET);
            fseek(fpsec, 0, SEEK_SET);
            fprintf(fppri, "1");
            fprintf(fpsec, "1");
        }
    }



    return 0;
}