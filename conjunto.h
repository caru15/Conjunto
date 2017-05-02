
typedef char* Item;

typedef struct nodo{
	Item elemento;
	struct nodo *siguiente;//este tipo de dato apunta a otro nodo
}NODO;

typedef struct{
	struct nodo *primero;
	struct nodo *ultimo;
}CONJUNTO;

//basicos
void Inicia(CONJUNTO *);					// inicializa conjunto
CONJUNTO operator+(CONJUNTO,Item);			// agregar un elemento
CONJUNTO operator-(CONJUNTO,Item);			// retirar un elemento

//operaciones
CONJUNTO operator+(CONJUNTO,CONJUNTO);		// union de conjuntos 
CONJUNTO operator*(CONJUNTO,CONJUNTO);		// interseccion de conjuntos
CONJUNTO operator-(CONJUNTO,CONJUNTO);		// A-B, diferencia de conjuntos

//logicos
bool Pertenece(Item,CONJUNTO);	
bool operator==(CONJUNTO,CONJUNTO);

//salida
void Mostrar(CONJUNTO);
