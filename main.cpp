#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"
#include "conjunto_d.h"
#include "automata.h"

int main(void)
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
	printf("\n\tAUTOMATA\n");
	Mostrar(A);
	Item cad= "101101";
	if (procesar(cad,A))
		printf("\nLa cadena: %s a sido Aceptada  por el AUTOMATA",cad);
	else
		printf("\nLa cadena: %s a sido Rechazada por el AUTOMATA",cad);
	cad= "101100";
	if (procesar(cad,A))
		printf("\nLa cadena: %s a sido Aceptada  por el AUTOMATA",cad);
	else
		printf("\nLa cadena: %s a sido Rechazada por el AUTOMATA",cad);
	
	return(0);
}
