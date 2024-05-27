#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

/*
 *Se arma la estructura del nodo
 *Se crea un dato que se almacena en el nodo
 *Se hacen dos punteros, el primero apunta al siguiente nodo y el otro apunta al anterior 
 */
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


/*
 *Se hace una estructura para la lista que es doblemente enlazada
 *Hay dos punteros, el primero apunta al primer nodo y el segundo apunta al ultimo nodo
 */
typedef struct {
    Node* head;
    Node* tail;
} DoubleList;

//Se declaran todas las funciones que se van a utilizar en double_list.c
void init_list(DoubleList* list);
void insert_at_beginning(DoubleList* list, int data);
void insert_at_end(DoubleList* list, int data);
void insert_at_index(DoubleList* list, int data, int index);
void delete_by_value(DoubleList* list, int data);
Node* search(DoubleList* list, int data);
void print_list_forward(DoubleList* list);
void print_list_backward(DoubleList* list);
void free_list(DoubleList* list);

#endif
