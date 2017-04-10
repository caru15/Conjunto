#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "conjunto.h"


void Inicia(Nodo * cabeza, Nodo * ultimo)
{
	cabeza= NULL;
	ultimo= NULL;
}
void Cargar_nodo(cadena entrada,Nodo** cab)
{
	Nodo * nodo;
	nodo=(Nodo*) malloc(sizeof(Nodo));
	//strcpy(nodo->siguiente,entrada);
	nodo->elemento =entrada;
	nodo->siguiente=*cab;
	*cab=nodo;

}
void Mostrar_elem(Nodo n)
{
	printf("%s ",n.elemento);
}
