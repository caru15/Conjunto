#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <stdio.h>

typedef char cadena[50];

typedef struct Nodo{
	cadena elemento;
	struct Nodo * siguiente;//este tipo de dato apunta a otro nodo
               }Nodo;


void Inicia(Nodo *, Nodo*);//inicializa la cabeza de la lista
void Cargar_nodo(cadena,Nodo **);
void Mostrar_elem(Nodo);
#endif
