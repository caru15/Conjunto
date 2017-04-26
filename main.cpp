#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"
#define NULLO

/*solo carga elementos enteros habria que ver que me cargue cadena de caracteres
o solo un caracter es ese ccaso cambio en el tipo Item por char*/

int main(void)
{NODO * c;

	Inicia(&c);
	Cargar_nodo(5,&c);
	Cargar_nodo(4,&c);
	Cargar_nodo(7,&c);
	Mostrar_elem(c);
	Eliminar_nodo_enpos(&c,1);
	Mostrar_elem(c);
	return(0);
}
