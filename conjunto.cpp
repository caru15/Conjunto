#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "conjunto.h"
#define NULLO


void Inicia(NODO ** cabeza)
{
	*cabeza= NULL;
	//ultimo= NULL;
}
void Cargar_nodo(Item entrada,NODO ** cab)
{
	NODO * nodo;
    
	nodo=(NODO *) malloc(sizeof(NODO));
	//strcpy(nodo->siguiente,entrada);
	nodo->elemento = entrada;
	nodo->siguiente=*cab;
	*cab=nodo;
}

void Eliminar_nodo_enpos(NODO ** ca, int i)
	
{
	int k=0;
	NODO * ptr,*ult;
	ptr=*ca;
	ult=NULL;
	while((k<i)&&(ptr!=NULL))
	{
		k++;
		ult=ptr;
		ptr=ptr->siguiente;
	}
	if (k==i)
	{
		if (ult==NULL)
		*ca=ptr->siguiente;
	else
		{
		ult->siguiente=ptr->siguiente;
		free(ptr);
		return;}
	}
	else printf("No se encontro la posicion %i ",i);
}

void Mostrar_elem(NODO* ca)
{
	
	NODO * auxiliar; /* lo usamos para recorrer la lista */
	int i;
	
	i=0;
	auxiliar = ca;
	printf("\nMostrando la lista completa:\n");
	
	while((auxiliar)!=NULL){   //for(i==0;i<3;i++) {  //
		printf( "Elemento: %i,",auxiliar->elemento);
		auxiliar = auxiliar->siguiente;
		i++;
	}
	if (i==0) printf( "\nLa lista está vacía!!\n" );
	else printf("\n La lista tiene %i elementos.",i);
}

