#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Se invoca a la lista doblemente enlazada
void init_list(DoubleList* list) {
    list->head = NULL;
    list->tail = NULL;
}

/*
 * Se inserta el nodo que corresponde al inicio de la lista
 * Se utiliza malloc para crear memoria para el nuevo nodo
 * En caso de que la lista estuviera vacia, este nuevo nodo es tambien el ultimo
 */
void insert_at_beginning(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node;
    }
    list->head = new_node;
}

/*
 * Lo siguiente corresponde a la insercion del nodo al final de la lista
 * Tambien se reserva la memoria con malloc
 * Si en la lista no habia nada, este nuevo nodo tambien es el primero
 */
void insert_at_end(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    list->tail = new_node;
}

/*
 * Este nodo hace que se inserte en una posicion especifica
 * Se toma en cuenta la posibilidad que el nuevo nodo sea el primero en la lista
 * Se hace la navegacion hasta el indice que se desea
 * Se considera si el indice especificado esta por fuera de los limites
 * Tambien se reserva la memoria usando malloc
 * En caso de que se llegue a insertar al final del todo, se actualiza la "cola" de la lista
 */
void insert_at_index(DoubleList* list, int data, int index) {
    if (index == 0) {
        insert_at_beginning(list, data);
        return;
    }

    Node* current = list->head;
    for (int i = 0; current != NULL && i < index - 1; ++i) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Index fuera de los limites\n");
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = current->next;
    new_node->prev = current;

    if (current->next != NULL) {
        current->next->prev = new_node;
    } else {
        list->tail = new_node;
    }

    current->next = new_node;
}

/*
 * En la siguiente funcion se elimina un nodo en base al contenido de data
 * Se considera que en caso de estar repetido, se va a eliminar solo en primero
 * Adicionalmente se considera en caso de que el valor no este en la lista
 * Puede ser que sea el primer nodo, en caso de que ocurra se ocupa actualizar el "head"
 * En contra parte de lo anterior, si es el ultimo nodo se actualiza el "tail"
 * Por ultimo se libera la memoria del nodo que se borro
 */
void delete_by_value(DoubleList* list, int data) {
    Node* current = list->head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Valor no encontrado\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    free(current);
}

// Esta funcion busca un elemento por medio de su valor
Node* search(DoubleList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Se hace la impresion de la lista hacia adelante
void print_list_forward(DoubleList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Se hace la impresion de la lista hacia atras
void print_list_backward(DoubleList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Por ultimo, se va a liberar toda la memoria de lista
void free_list(DoubleList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}
