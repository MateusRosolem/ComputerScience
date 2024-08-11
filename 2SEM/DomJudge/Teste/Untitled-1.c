#include <stdio.h>
#include <stdlib.h>

int num_programas;
    

// estrutura para armazenar dados de um programa
typedef struct {
    int tempo_solicitado;
    int tempo_execucao;
} Programa;




// função para comparar dois programas pelo tempo de execução
int comparar_programas(const void *a, const void *b) {
    const Programa *programa1 = (const Programa *)a;
    const Programa *programa2 = (const Programa *)b;

    // se o tempo de execução de dois programas for igual,
    // ordena pelo tempo solicitado (do menor para o maior)
    if (programa1->tempo_execucao == programa2->tempo_execucao) {
        if(programa1->tempo_solicitado < programa2->tempo_solicitado)
        return programa2->tempo_solicitado;
    }

    if((programa1->tempo_solicitado+programa1->tempo_execucao) == programa2->tempo_solicitado)
        return programa2->tempo_solicitado;

    // caso contrário, ordena pelo tempo de execução
    return programa1->tempo_solicitado - programa2->tempo_solicitado;
}




int main() {
    // número de programas a serem executados

    printf("Informe o numero de programas: ");
    scanf("%d", &num_programas);
       Programa *programas = malloc(num_programas * sizeof(Programa));

    // aloca memória para armazenar os dados de cada programa

    if (programas == NULL) {
        // trata erro de alocação de memória
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    // lê os dados de cada programa
    for (int i = 0; i < num_programas; i++) {
        printf("Informe o tempo solicitado e o tempo de execucao do programa %d: ", i + 1);
        scanf("%d%d", &programas[i].tempo_solicitado, &programas[i].tempo_execucao);
    }

    // ordena os programas pelo tempo de execução (do maior para o menor)
    qsort(programas, num_programas, sizeof(Programa), comparar_programas);


    // imprime os tempos de execução dos programas, na ordem em que serão executados
    printf("Lista de cargas dos programas: ");
    for (int i = 0; i < num_programas; i++) {
        printf("%d ", programas[i].tempo_execucao);
    }
    printf("\n");

    // libera a memória alocada
    free(programas);
    return 0;
}
