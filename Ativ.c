#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista ligada
struct Node {
    int data;
    struct Node* next;
};

// Função para inverter a lista
void reverse(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;  // Armazena o próximo nó
        current->next = prev;  // Inverte o ponteiro
        prev = current;        // Avança prev e current
        current = next;
    }
    *head_ref = prev;  // Atualiza o head para o novo primeiro nó
}

// Função para adicionar um nó no final da lista
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Função para imprimir a lista
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("None\n");
}

// Função principal para executar o programa
int main() {
    struct Node* head = NULL;

    // Adiciona os valores 100, 60, 40, 10
    append(&head, 100);
    append(&head, 60);
    append(&head, 40);
    append(&head, 10);

    // Imprime a lista original
    printf("Lista Original:\n");
    printList(head);

    // Inverte a lista
    reverse(&head);

    // Imprime a lista invertida
    printf("Lista Invertida:\n");
    printList(head);

    return 0;
}
