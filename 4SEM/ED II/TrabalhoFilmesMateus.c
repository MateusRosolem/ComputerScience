#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int rrn = 0;
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
    printf("\nDigite o ano de lancamento:");
    scanf("%d", &filme.ano);
    printf("\nDigite o pais do filme:");
    scanf(" %[^\n]", filme.pais);
    fflush(stdin);
    printf("\nDigite a nota do filme:[0 a 9]");
    scanf("%d", &filme.nota);

    
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
    fseek(fppri,0,SEEK_END);
    imprimirEmOrdem(fppri, raiz);

    // Fecha os aqruivos
    fclose(fpdados);
    fclose(fpsec);
    fclose(fppri);

    // Liberar memoria alocada
    freeTree(raiz);
    return;
}




int main(){
    FILE *fppri, *fpsec, *fpdados; // Ponteiro pro indice primario, secundarios e dados
    indicePrim *raiz = NULL;
    indiceSec *head = NULL;
    int op = 0, flag = 0,flagDados=0;
    char code[5], lixo,titulo[65];
    int rrn = 0, i = 0;

    // Verificação se existe um arquivo de dados.
    if (!(fpdados = fopen("./movies.dat", "r+"))){ // Se nao existe ele entra
        fpdados = fopen("./movies.dat", "w+");
        flagDados=1;
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