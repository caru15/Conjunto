#define LEN 100
#define MAX 100
#include <stdbool.h>

typedef struct Conjunto
{
   char elementos[MAX];    
   int numElem;
} t_conjunto ; 


//metodos

void inicializa(t_conjunto *);

bool estaVacio(t_conjunto);
bool estaLleno(t_conjunto);
int pertenece(t_conjunto,char [MAX]);

t_conjunto op_u(t_conjunto,t_conjunto);			// union de conjuntos 
t_conjunto op_i(t_conjunto,t_conjunto);			// interseccion de t_conjuntos
t_conjunto op_d(t_conjunto,t_conjunto);			// A-B, diferencia de t_conjuntos
t_conjunto op_add(t_conjunto,char [MAX]);		// agregar un elemento
t_conjunto op_del(t_conjunto,char [MAX]);		// retirar un elemento
bool op_comp(t_conjunto,t_conjunto B);			// operador de comparador

void mostrar(t_conjunto);
//ostream& operator <<(ostream& co,const t_conjunto c);	//cout
