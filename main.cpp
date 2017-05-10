#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"
#include "conjunto_d.h"
#include "automata.h"

void ejemplo1()
{
	CONJUNTO Q,Z,F;
	Inicia(&Q);
	Inicia(&Z);
	Inicia(&F);
	Q = Q + "q0" + "q1";
	Z = Z + "0" + "1";
	F = F + "q1";
	AUTOMATA A ;
	Inicia(&A,Q,Z,"q0",F);	
	d(&A,"q0","0","q1");
	d(&A,"q0","1","q0");
	d(&A,"q1","0","q1");
	d(&A,"q1","1","q0");
	//
	printf("\n\tAUTOMATA 1\n");
	Mostrar(A);
	Item cad= "101101";
	if (procesar(A,cad))
		printf("\nLa cadena: %s a sido Aceptada  por el AUTOMATA",cad);
	else
		printf("\nLa cadena: %s a sido Rechazada por el AUTOMATA",cad);
	cad= "101100";
	if (procesar(A,cad))
		printf("\nLa cadena: %s a sido Aceptada  por el AUTOMATA",cad);
	else
		printf("\nLa cadena: %s a sido Rechazada por el AUTOMATA",cad);
}

void ejemplo2()
{
	CONJUNTO Q,Z,F;
	Inicia(&Q);
	Inicia(&Z);
	Inicia(&F);
	Q = Q + "r0" + "E1" + "E2" + "x" + "y" + "xy" + "yx";
	Z = Z + "x" + "y";
	F = F + "xy" + "yx";
	AUTOMATA A ;
	Inicia(&A,Q,Z,"r0",F);
	//r0
	d(&A,"r0","x","x");
	d(&A,"r0","x","E2");
	d(&A,"r0","y","E1");
	d(&A,"r0","y","y");
	//E1
	d(&A,"E1","x","x");
	d(&A,"E1","y","E1");
	//E2
	d(&A,"E2","x","E2");
	d(&A,"E2","y","y");
	//x
	d(&A,"x","x","x");
	d(&A,"x","y","xy");
	//y
	d(&A,"y","x","yx");
	d(&A,"y","y","y");
	//xy
	d(&A,"xy","x","xy");
	d(&A,"xy","y","xy");
	//yx
	d(&A,"yx","x","yx");
	d(&A,"yx","y","yx");
	//
	printf("\n\tAUTOMATA 2\n");
	Mostrar(A);
	Item cad= "xyyyx";
	if (procesar(A,cad))
		printf("\nLa cadena: %s a sido Aceptada  por el AUTOMATA",cad);
	else
		printf("\nLa cadena: %s a sido Rechazada por el AUTOMATA",cad);
	cad= "yxxxy";
	if (procesar(A,cad))
		printf("\nLa cadena: %s a sido Aceptada  por el AUTOMATA",cad);
	else
		printf("\nLa cadena: %s a sido Rechazada por el AUTOMATA",cad);
}

int main(void)
{
	ejemplo1();	//determinista
	printf("\n");
	ejemplo2(); //no determinista
	return(0);
}
