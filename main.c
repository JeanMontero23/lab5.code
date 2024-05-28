#include <stdio.h>
#include "double_list.h"

/*
 * Primeramente declara una variable list de tipo doublelist, para luego inicializar la lista enlazada
 * Luego se llaman a las inserciones de la lista con valores predeterminados para probar la funcionalidad de las listas
 * Continua con la impresion de los valores de la lista una vez que se llevaron a cabo las inserciones
 * Se elige borrar el nodo de valor igual a 20
 * Seguidamente se hace la busqueda de un nodo con valor de 30
 * Despues se imprime la lista en ambas direcciones como fue solicitado
 * Finalmente, se libera la memoria de la lista
 */
int main() {
    DoubleList list;
    init_list(&list);

    insert_at_beginning(&list, 10);
    insert_at_beginning(&list, 20);
    insert_at_end(&list, 30);
    insert_at_end(&list, 40);
    insert_at_index(&list, 25, 2);

    printf("Lista despues de las inserciones:\n");
    print_list_forward(&list);

    delete_by_value(&list, 20);
    printf("Lista despues de borrar el valor 20:\n");
    print_list_forward(&list);

    Node* found = search(&list, 30);
    if (found != NULL) {
        printf("Encontrado con exito: %d\n", found->data);
    } else {
        printf("No pudo ser encontrado\n");
    }

    printf("Lista impresa hacia adelante:\n");
    print_list_forward(&list);
    printf("Lista impresa hacia atras:\n");
    print_list_backward(&list);

    free_list(&list);
    return 0;
}

