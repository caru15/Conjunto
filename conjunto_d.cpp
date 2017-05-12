#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "conjunto_d.h"

void Inicia(CONJUNTO_D *c)
{
	c->cant	   = 0;
	c->primero = NULL;
	c->ultimo  = NULL;
}

bool Pertenece(delta *d,CONJUNTO_D c)
{
	DELTA *i = c.primero;
	while (i != NULL)
	{
		if ((strcmp(i->estadoI, d->estadoI)==0) and
			(strcmp(i->simbolo, d->simbolo)==0) and
			(strcmp(i->estadoF, d->estadoF)==0))
			return true;
		i=i->siguiente;
	}
	return false;
}

CONJUNTO_D operator + (CONJUNTO_D c,delta *e)
{
	if (Pertenece(e,c)) return c; //si existe no lo Agrega
	delta *aux = (delta *) malloc(sizeof(delta));
	aux->estadoI = e->estadoI;
	aux->simbolo = e->simbolo;
	aux->estadoF = e->estadoF;
	aux->siguiente = NULL;
	
	if (c.primero == NULL) //vacio
	{
		c.primero = aux;
		c.ultimo  = aux;
	}
	else
	{
		c.ultimo->siguiente = aux;
		c.ultimo = aux;		
	}
	c.cant++;
	
	return c;
}

CONJUNTO_D operator - (CONJUNTO_D c,delta *e)
{
	if (!Pertenece(e,c)) return c; //si no existe sale
	
	if ((c.primero->estadoI == e->estadoI) and
		(c.primero->simbolo == e->simbolo) and
		(c.primero->estadoF == e->estadoF)) //si es el primero
	{
		c.primero = c.primero->siguiente;
		return c;
	}
	
	DELTA *anterior = NULL;
	DELTA *actual   = c.primero;
	
	while (actual != NULL)
	{
		if ((actual->estadoI == e->estadoI) and
			(actual->simbolo == e->simbolo) and
			(actual->estadoF == e->estadoF))
		{
			anterior->siguiente = actual->siguiente;
			return c;
		}
		anterior = actual;
		actual   = actual->siguiente;
	}
	c.cant--;
	
	return c; //en terio no llega aca
}

CONJUNTO_D operator+(CONJUNTO_D a,CONJUNTO_D b)
{
	CONJUNTO_D c;
	Inicia(&c);
	DELTA *i = a.primero;
	while (i != NULL)
	{
		c = c + i;
		i=i->siguiente;
	}
	i = b.primero;
	while (i != NULL)
	{
		c = c + i;
		i=i->siguiente;
	}
	return c;
}

CONJUNTO_D operator*(CONJUNTO_D a,CONJUNTO_D b)
{
	CONJUNTO_D c;
	Inicia(&c);
	DELTA *i = a.primero;
	while (i != NULL)
	{
		if (Pertenece(i,b)) //pertenece a A y B
			c = c + i;
		i=i->siguiente;
	}
	return c;
}

CONJUNTO_D operator-(CONJUNTO_D a,CONJUNTO_D b)
{
	CONJUNTO_D c;
	Inicia(&c);
	DELTA *i = a.primero;
	while (i != NULL)
	{
		if (!Pertenece(i,b)) //no pertenece a B
			c = c + i;
		i=i->siguiente;
	}	
	return c;
}

bool operator==(CONJUNTO_D a,CONJUNTO_D b)
{
	DELTA *i;
	if (a.cant >= b.cant) 
		i = a.primero;
	else
		i = b.primero;	
	while (i != NULL)
	{
		if (!Pertenece(i,b)) //no pertenece a B
			return false;
		i=i->siguiente;
	}
	return true;
}

bool Contiene(CONJUNTO_D a,CONJUNTO_D b)
{
	DELTA *i;
	i = a.primero;
	while (i != NULL)
	{
		if (!Pertenece(i,b)) //no pertenece a B
			return false;
		i=i->siguiente;
	}
	return true;
}

void Mostrar(CONJUNTO_D c)
{
	printf("(%d transiciones)\n",c.cant);
	DELTA *i = c.primero;
	while (i != NULL)
	{
		printf("d(%s,%s)=%s\n",i->estadoI ,i->simbolo, i->estadoF);
		i=i->siguiente;
	}
	
}
