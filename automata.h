#include "conjunto.h"
#include "conjunto_d.h"

typedef struct{
	CONJUNTO 	alfabeto;
	CONJUNTO 	estados;
	Item	 	e_ini;
	CONJUNTO 	c_final;
	CONJUNTO_D	d;
}AUTOMATA;

//basicos
void Inicia(AUTOMATA *, CONJUNTO, CONJUNTO, Item, CONJUNTO);
void d(AUTOMATA *,Item,Item,Item);	

//delta

bool procesar(AUTOMATA, Item);//devuelve si una cadena es aceptada o no
CONJUNTO verifica(AUTOMATA, Item, Item);//devuelve si una cadena es aceptada o no
Item leePrimero(Item); // devuelve primer caracter de la cadena
Item sacaPrimero(Item); // saca el primer caracter de la cadena
CONJUNTO_D subQ(Item, CONJUNTO_D);//devuelve un sub CONJUNTO_D de todas las transiciones para un estado
CONJUNTO Qfinal(Item, CONJUNTO_D);//devuelve un conjunto de estados para un determindado simbolo


//salida
void Mostrar(DELTA *);
void Mostrar(AUTOMATA);
