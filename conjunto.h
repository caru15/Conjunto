#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <stdio.h>
#include <string.h>


typedef int Item;

typedef struct nodo{
	Item elemento;
	struct nodo * siguiente;//este tipo de dato apunta a otro nodo
               }NODO;


void Inicia(NODO **);//inicializa la cabeza de la lista
void Cargar_nodo(Item,NODO **);
void Eliminar_nodo_enpos(NODO **, int);
void Mostrar_elem(NODO *);
#endif
