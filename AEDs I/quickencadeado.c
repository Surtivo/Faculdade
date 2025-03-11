#include <stdio.h>
#include <stdlib.h>
//BY CHATGPT
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para adicionar um novo nó ao final da lista
void push(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref; // Usado para percorrer a lista
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Função para dividir a lista com base no pivô
Node* partition(Node* head, Node** front, Node** back) {
    Node* pivot = head;
    Node* current = head->next;

    Node* less_head = NULL;
    Node* less_tail = NULL;
    Node* equal_head = NULL;
    Node* equal_tail = NULL;
    Node* greater_head = NULL;
    Node* greater_tail = NULL;

    push(&equal_head, pivot->data); // Adiciona o pivô na lista de iguais
    equal_tail = equal_head;

    while (current != NULL) {
        if (current->data < pivot->data) {
            if (less_head == NULL) {
                less_head = current;
                less_tail = less_head;
            } else {
                less_tail->next = current;
                less_tail = less_tail->next;
            }
        } else if (current->data > pivot->data) {
            if (greater_head == NULL) {
                greater_head = current;
                greater_tail = greater_head;
            } else {
                greater_tail->next = current;
                greater_tail = greater_tail->next;
            }
        } else {
            equal_tail->next = current;
            equal_tail = equal_tail->next;
        }
        current = current->next;
    }

    if (less_tail != NULL)
        less_tail->next = NULL;
    if (greater_tail != NULL)
        greater_tail->next = NULL;
    equal_tail->next = NULL;

    *front = less_head;
    *back = greater_head;

    return equal_head;
}

// Função que faz a concatenação das listas
Node* concatenate(Node* left, Node* middle, Node* right) {
    Node* result = NULL;

    if (left == NULL)
        result = middle;
    else {
        result = left;
        Node* temp = left;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = middle;
    }

    if (middle != NULL) {
        Node* temp = middle;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = right;
    } else {
        Node* temp = left;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = right;
    }

    return result;
}

// Função principal de QuickSort para listas encadeadas
Node* quickSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* front = NULL;
    Node* back = NULL;
    Node* middle = partition(head, &front, &back);

    front = quickSort(front);
    back = quickSort(back);

    return concatenate(front, middle, back);
}

// Função para imprimir a lista
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Função principal para testar o QuickSort
int main() {
    Node* a = NULL;
    push(&a, 10);
    push(&a, 7);
    push(&a, 8);
    push(&a, 3);
    push(&a, 1);
    push(&a, 4);
    push(&a, 9);

    printf("Lista antes do QuickSort:\n");
    printList(a);

    a = quickSort(a);

    printf("Lista depois do QuickSort:\n");
    printList(a);

    return 0;
}
