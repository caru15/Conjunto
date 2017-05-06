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
CONJUNTO_D subQ(Item, CONJUNTO_D);//devuelve un sub CONJUNTO_D de todas las transiciones para un estado
Item Qfinal(Item, CONJUNTO_D);//devuelve un estado para un determindado simbolo
bool procesar(char *, AUTOMATA);//devuelve si una cadena es aceptada o no

//salida
void Mostrar(DELTA *);
void Mostrar(AUTOMATA);
