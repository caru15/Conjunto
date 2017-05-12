#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "conjunto.h"
#include "conjunto_d.h"
#include "automata.h"

void Inicia(AUTOMATA *A)
{
	Inicia(&A->alfabeto);
	Inicia(&A->estados);
	Inicia(&A->c_final);
	Inicia(&A->d);
	A->e_ini="";
}

bool Inicia(AUTOMATA *A, CONJUNTO Q, CONJUNTO Z, Item q, CONJUNTO F)
{
	A->estados  = Q;		
	A->alfabeto = Z;		
	A->e_ini    = q;		
	A->c_final  = F;
	Inicia(&A->d);
	if ( Q.cant > 0 and //conjunto no vacio de estado
		 Z.cant > 0 and //conjunto no vacio de simbolos
		 Pertenece(q,Q) and //estado inicial pertenece al conjunto de estados
		 Contiene(F,Q) //conjunto de estados finales contenido en conjunto de estados
		)
		return true;
	printf("AUTOMATA CON ERRORES \n");
	return false;
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

bool procesar(AUTOMATA A,Item z)
{
	//inicio conjunto de estados a los q se llega con la cadena
	CONJUNTO e;
	Inicia(&e);
	
	//devuelve el conjunto de estados para la cadena
	e=verifica(A,z,A.e_ini);	
	
	//creo un conjunto para la interseccion 
	CONJUNTO fin;
	Inicia(&fin);
	
	//interseccion estados obtenidos y estados finales
	fin = e*A.c_final;
	
	if (fin.cant !=0) // si no es vacio
		return true;
	return false;
}

CONJUNTO verifica(AUTOMATA A,Item z, Item e_actual)
{	
	// inicializa conjunto de salida
	CONJUNTO e;
	Inicia(&e);
	
	//longitud de la cadena
	int n=strlen(z);
	
	if (n == 0) //si ya termino la cadena
		e = e + e_actual;
	else
	{
		//defino conjunto de transiciones
		CONJUNTO_D d;
		Inicia(&d);
		
		//sub conjunto de las transiciones que parten del estado actual
		d=subQ(e_actual,A.d);
		
		//leo el primer caracter y actualizo z
		Item simbolo =  leePrimero(z);
		//actualizo z
		z = sacaPrimero(z);		
		
		//defino conjunto de estados finales
		CONJUNTO ef;
		Inicia(&ef);
		
		//conjunto de estados para el simbolo 
		ef = Qfinal(simbolo,d);
		
		//recorro todos los estados
		nodo *estado;
		estado = ef.primero;
		while (estado != NULL)
		{
			//verifico cada estado
			e = e + verifica(A, z, estado->elemento);
			estado=estado->siguiente;
		}
	}
	return e;
}

Item leePrimero(Item a)
{
	char *aux = (char *)malloc(sizeof(char));
	aux[0]=a[0];
	aux[1]='\0';	
	return aux;
}

Item sacaPrimero(Item a)
{
	char *aux2 = (char *)malloc(sizeof(char));
	int i;
	for(i=0;i<strlen(a)-1;i++)
		aux2[i]=a[i+1];
	aux2[i]='\0';
	a=aux2;
	return aux2;
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

CONJUNTO Qfinal(Item z, CONJUNTO_D d)
{	
	CONJUNTO c;
	Inicia(&c);	
	DELTA *i = d.primero;
	while (i != NULL)
	{		
		if ( strcmp(i->simbolo,z)==0)
			c = c + i->estadoF;
		i=i->siguiente;
	}
	return c;
}

void Mostrar(AUTOMATA A)
{
	if ( A.estados.cant > 0 and //conjunto no vacio de estado
		 A.alfabeto.cant > 0 and //conjunto no vacio de simbolos
		 Pertenece(A.e_ini, A.estados) and //estado inicial pertenece al conjunto de estados
		 Contiene(A.c_final, A.estados) and//conjunto de estados finales contenido en conjunto de estados
		 A.d.cant > 0 //conjunto no vacio de transiciones
		)
		printf("\n\t AUTOMATA \n");
	else
		printf("\n\t AUTOMATA CON ERRORES \n");
	
	printf("\n ESTADOS: \n\t"); Mostrar(A.estados);	
	printf("\n ALFABETO: \n\t"); Mostrar(A.alfabeto);
	printf("\n ESTADO INICIAL: %s\n",A.e_ini);
	printf("\n CONJUNTO DE ACEPTACION: \n\t"); Mostrar(A.c_final);
	printf("\n FUNCION DE TRANSICION: \n"); Mostrar(A.d);
}
