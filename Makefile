#Se define el compilador y las revisiones que se haran al compilador (al buscar acerca de esto ultimo, se llega a la conclusion de que es buena practica implementar el "-g" ya que depura cierta informacion)
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

#Sirve para especificar el objetivo predeterminado cuando el make no tiene argumentos, el cual seria construir el main
all: main

#Se definen las reglas de como construir el main a partir del main.o y double_list.o; ademas de como compilar estos dos ultimos
main: main.o double_list.o
	$(CC) $(CFLAGS) -o main main.o double_list.o

main.o: main.c double_list.h
	$(CC) $(CFLAGS) -c main.c

double_list.o: double_list.c double_list.h
	$(CC) $(CFLAGS) -c double_list.c

#Esta seccion sirve para poder borrar los archivos que tengan como "patron" *.o; tambien se agrega el "-f para que no se muestre algun error si el archivo ya fue borrado"
clean:
	rm -f *.o main
