#include <stdio.h>
#include <stdlib.h>

/* Define a estrutura do nó da lista duplamente encadeada */
struct node {
    int job_id;  // ID do trabalho
    int duration;  // Duração do trabalho
    struct node *next;  // Ponteiro para o próximo nó
    struct node *prev;  // Ponteiro para o nó anterior
};

/* Cria um novo nó com os dados especificados e o retorna */
struct node *create_node(int job_id, int duration) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->job_id = job_id;
    new_node->duration = duration;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

/* Insere um novo nó na lista ordenando-o pelo tempo de duração do trabalho */
void insert_node(struct node **head, int job_id, int duration, int current_time) {
    // Cria um novo nó com os dados especificados
    struct node *new_node = create_node(job_id, duration);

    // Se a lista está vazia, o novo nó é o primeiro e último da lista
    if (*head == NULL) {
        *head = new_node;
        return;
    }
        struct node *atual = *head;
    while (atual->next != NULL) {
        // Se o próximo nó tem a mesma duração que o novo nó, mas um ID maior, insere o novo nó antes desse
        if (atual->job_id == current_time) {
            new_node->next = atual->next;
            new_node->prev = atual;
            atual->next->prev = new_node;
            atual->next = new_node;
            return;
        }

        atual = atual->next;
    }

    // Procura a posição correta para inserir o novo nó
    struct node *current = *head;
    while (current->next != NULL) {
        // Se o próximo nó tem uma duração maior que a do novo nó, insere o novo nó antes desse
        if (current->next->duration > new_node->duration) {
            new_node->next = current->next;
            new_node->prev = current;
            current->next->prev = new_node;
            current->next = new_node;
            return;
        }

        // Se o próximo nó tem a mesma duração que o novo nó, mas um ID maior, insere o novo nó antes desse
        if (current->next->duration == new_node->duration && current->next->job_id > new_node->job_id) {
            new_node->next = current->next;
            new_node->prev = current;
            current->next->prev = new_node;
            current->next = new_node;
            return;
        }

        current = current->next;
    }

    // Se chegou aqui, é porque o novo nó deve ser
}

/* Remove um nó específico da lista */
void remove_node(struct node **head, struct node *node) {
    // Se o nó a ser removido é o primeiro da lista, atualiza o ponteiro para o primeiro nó
    if (*head == node) {
        *head = node->next;
    }

    // Se o nó a ser removido tem um nó anterior, atualiza o ponteiro do nó anterior para o próximo nó
}
   
/* Imprime a duração dos trabalhos em ordem */
void print_jobs(struct node *head) {
    // Percorre a lista encadeada imprimindo a duração de cada trabalho
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->duration);
        current = current->next;
    }
}


int main() {
    struct node *head = NULL;
    int n;
    int n1, n2;
    int tempo=0;

    scanf("%d", &n);
    // Insere alguns trabalhos na lista
    for(int i=0;i<n;i++){
        scanf("%d %d", &n1, &n2);
        insert_node(&head, n1, n2, tempo);
    }


    // Imprime as durações dos trabalhos em ordem
    print_jobs(head);

    return 0;
}
