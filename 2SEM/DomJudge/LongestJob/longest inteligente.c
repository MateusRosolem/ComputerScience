#include <stdio.h>
#include <stdlib.h>

int num_programas;

typedef struct list{
    int ts;
    int te;
}Programa;

void ordenar(Programa *programas){
int i=0,j=0;




}






int main() {
int i;


    printf("Informe o numero de programas: ");
    scanf("%d", &num_programas);
       Programa *programas = malloc(num_programas * sizeof(Programa));
    // aloca memória para armazenar os dados de cada programa


    // lê os dados de cada programa
    for ( i = 0; i < num_programas; i++) {
        printf("Informe o tempo solicitado e o tempo de execucao do programa %d: ", i + 1);
        scanf("%d%d", &programas[i].ts, &programas[i].te);
    }

    ordenar(&programas);




    // imprime os tempos de execução dos programas, na ordem em que serão executados
    printf("Lista de cargas dos programas: ");
    for ( i = 0; i < num_programas; i++) {
        printf("%d ", programas[i].te);
    }
    printf("\n");

    // libera a memória alocada
    free(programas);
    return 0;
}
