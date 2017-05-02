#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

int main(void)
{
	CONJUNTO a,b,c;
	Inicia(&a);
	Inicia(&b);
	Inicia(&c);
	a = a + "a1" + "a2" + "a3" + "1" + "5";
	b = b + "b1" + "b2" + "5";	
	printf("A: ");
	Mostrar(a);
	printf("B: ");
	Mostrar(b);
	printf("C=A+B: ");
	Mostrar(a+b);
	printf("A*B: ");
	Mostrar(a*b);
	printf("B-A: ");
	Mostrar(b-a);
	printf("A==B: ");
	if (a==b) printf("TRUE");
	else printf("FALSE");
	return(0);
}
