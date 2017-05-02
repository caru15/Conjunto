#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

void Inicia(CONJUNTO *c)
{
	c->cant	   = 0;
	c->primero = NULL;
	c->ultimo  = NULL;
}

bool Pertenece(Item e,CONJUNTO c)
{
	NODO *i = c.primero;
	while (i != NULL)
	{
		if (i->elemento == e)
			return true;
		i=i->siguiente;
	}
	return false;
}

CONJUNTO operator + (CONJUNTO c,Item e)
{
	if (Pertenece(e,c)) return c; //si existe no lo Agrega
	NODO *n = (NODO *) malloc(sizeof(NODO));
	n->elemento = e;
	n->siguiente = NULL;
	
	if (c.primero == NULL) //vacio
	{
		c.primero = n;
		c.ultimo = n;
	}
	else
	{
		c.ultimo->siguiente = n;
		c.ultimo = n;		
	}
	c.cant++;
	
	return c;
}

CONJUNTO operator - (CONJUNTO c,Item e)
{
	if (!Pertenece(e,c)) return c; //si no existe sale
	
	if (c.primero->elemento == e) //si es el primero
	{
		c.primero = c.primero->siguiente;
		return c;
	}
	
	NODO *anterior = NULL;
	NODO *actual   = c.primero;
	
	while (actual != NULL)
	{
		if (actual->elemento == e)
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

CONJUNTO operator+(CONJUNTO a,CONJUNTO b)
{
	CONJUNTO c;
	Inicia(&c);
	NODO *i = a.primero;
	while (i != NULL)
	{
		c = c + i->elemento;
		i=i->siguiente;
	}
	i = b.primero;
	while (i != NULL)
	{
		c = c + i->elemento;
		i=i->siguiente;
	}
	return c;
}

CONJUNTO operator*(CONJUNTO a,CONJUNTO b)
{
	CONJUNTO c;
	Inicia(&c);
	NODO *i = a.primero;
	while (i != NULL)
	{
		if (Pertenece(i->elemento,b)) //pertenece a A y B
			c = c + i->elemento;
		i=i->siguiente;
	}
	return c;
}

CONJUNTO operator-(CONJUNTO a,CONJUNTO b)
{
	CONJUNTO c;
	Inicia(&c);
	NODO *i = a.primero;
	while (i != NULL)
	{
		if (!Pertenece(i->elemento,b)) //no pertenece a B
			c = c + i->elemento;
		i=i->siguiente;
	}	
	return c;
}

bool operator==(CONJUNTO a,CONJUNTO b)
{
	NODO *i;
	if (a.cant >= b.cant) 
		i = a.primero;
	else
		i = b.primero;	
	while (i != NULL)
	{
		if (!Pertenece(i->elemento,b)) //no pertenece a B
			return false;
		i=i->siguiente;
	}
	return true;
}

void Mostrar(CONJUNTO c)
{
	printf("{");
	NODO *i = c.primero;
	while (i != NULL)
	{
		printf("%s",i->elemento);
		if (i->siguiente !=NULL)//si quedan elementos poner coma
			printf(",");		
		i=i->siguiente;
	}
	printf("} %d elementos\n",c.cant);
}
