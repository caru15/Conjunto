#ifndef MY_HEADER_FILE_2_
#define MY_HEADER_FILE_2_
#include "conjunto.h"

typedef struct delta{
	Item 	 estadoI;
	Item 	 simbolo;
	Item	 estadoF;
	struct delta *siguiente; //este tipo de dato apunta a otro delta
}DELTA;

typedef struct{
	int cant;
	struct delta *primero;
	struct delta *ultimo;
}CONJUNTO_D;

//basicos
void Inicia(CONJUNTO_D *);					    // inicializa conjunto
CONJUNTO_D operator+(CONJUNTO_D,delta *);			// agregar un elemento
CONJUNTO_D operator-(CONJUNTO_D,delta *);			// retirar un elemento

//operaciones
CONJUNTO_D operator+(CONJUNTO_D,CONJUNTO_D);		// union de conjuntos 
CONJUNTO_D operator*(CONJUNTO_D,CONJUNTO_D);		// interseccion de conjuntos
CONJUNTO_D operator-(CONJUNTO_D,CONJUNTO_D);		// A-B, diferencia de conjuntos

//logicos
bool Pertenece(delta,CONJUNTO_D);	
bool operator==(CONJUNTO_D,CONJUNTO_D);
bool Contiene(CONJUNTO_D,CONJUNTO_D);

//salida
void Mostrar(CONJUNTO_D);

#endif
