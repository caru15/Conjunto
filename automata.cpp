#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "conjunto.h"
#include "conjunto_d.h"
#include "automata.h"

void Inicia(AUTOMATA *A, CONJUNTO Q, CONJUNTO Z, Item q, CONJUNTO F)
{
	if ( Pertenece(q,Q) and
		 Contiene(F,Q)
		)
	{
		A->estados  = Q;		
		A->alfabeto = Z;		
		A->e_ini    = q;		
		A->c_final  = F;
		Inicia(&A->d);
	}
	else
		printf("ERROR AUTOMATA \n");
}

void d(AUTOMATA *A,Item p,Item z,Item q)
{
	if ( Pertenece(p,A->estados) and
		 Pertenece(z,A->alfabeto) and
		 Pertenece(q,A->estados)
		)
	{
		DELTA *aux = (DELTA *) malloc(sizeof(DELTA));
		aux->estadoI = p;
		aux->simbolo = z;
		aux->estadoF = q;
		A->d  = A->d + aux; // agrega d(p,z)=q al CONJUNTO_D
	}
	else
		printf("ERROR d(%s,%s)=%s \n",p,z,q);
}

CONJUNTO_D subQ(Item q, CONJUNTO_D d)
{
	CONJUNTO_D c;
	Inicia(&c);	
	DELTA *i = d.primero;
	while (i != NULL)
	{
		if (i->estadoI == q) 
			c = c + i;
		i=i->siguiente;
	}
	return c;		
}

Item Qfinal(Item z, CONJUNTO_D d)
{	
	DELTA *i = d.primero;
	while (i != NULL)
	{		
		if ( strcmp(i->simbolo,z)==0)
			return i->estadoF;
		i=i->siguiente;
	}
	return NULL;
}

bool procesar(char * z, AUTOMATA A)
{
	
	Item e_actual= A.e_ini;
	CONJUNTO_D d;
	Inicia(&d);
	int n=strlen(z);
	
	for (int i=0; i<n; i++)
	{		
		char *aux = (char *)malloc(sizeof(char));
		aux[0]=z[i];
		aux[1]='\0';
		d=subQ(e_actual,A.d);
		e_actual = Qfinal(aux,d);	
	}	
	if (Pertenece(e_actual,A.c_final))
		return true;
	return false;
}

void Mostrar(AUTOMATA A)
{
	printf("\n ESTADOS: "); Mostrar(A.estados);
	printf("\n ALFABETO: "); Mostrar(A.alfabeto);
	printf("\n ESTADO INICIAL: %s\n",A.e_ini);
	printf("\n CONJUNTO DE ACEPTACION: "); Mostrar(A.c_final);
	printf("\n FUNCION DE TRANSICION: "); Mostrar(A.d);
}
