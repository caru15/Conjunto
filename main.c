#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "TAD_conjunto.h"

int opcion(); //funcion para que el usuario elija una opcion

int main() { //funcion principal
	
	int opcionSeleccionada;
	t_conjunto A,B;
	char * aux;
	aux="";
	do{
		fflush(stdin);
		printf("\nPresione Enter para mostrar el menu de Opciones.");
		getchar();
		system("cls");
		opcionSeleccionada = opcion();
		switch(opcionSeleccionada) {
		case 1: {
			printf("\nInicializando.\n");
			inicializa(&A);
			inicializa(&B);
			printf("A=");
			mostrar(A);
			printf(" B=");
			mostrar(B);
			break;
		} 
		case 2: {
			printf("\n--Conjunto A-- Agregar.\n");
			printf("Ingrese Elemento...");
			scanf("%s",&aux);
			//A = A + e;
			mostrar(A=op_add(A,&aux));
			break;
		}
		case 3: {
			printf("\n--Conjunto A-- Eliminar.\n");
			printf("\nIngrese Elemento...");
			scanf("%s", &aux);
			//A = A - e;
			mostrar(A=op_del(A,&aux));
			break;
		}
		case 4: {
			printf("\n--Conjunto B-- Agregar.\n");
			printf("\nIngrese Elemento...");
			scanf("%s", &aux);
			//B = B + e;
			mostrar(B=op_add(B,&aux));//el metodo mostrar le mando un t_conjunto es una estructura
			break;
		}
		case 5: {
			printf("\n--Conjunto b-- Eliminar.\n");
			printf("\nIngrese Elemento...");
			scanf("%s", &aux);
			//B = B - e;
			mostrar(B=op_del(B,&aux));
			break;
		}
		case 6: {
			printf("\n A + B .\n");
			mostrar(op_u(A,B));
			break;
		}
		case 7: {
			printf("\n A * B .\n");
			mostrar(op_i(A,B));
			break;
		}
		case 8: {
			printf("\n A - B .\n");
			mostrar(op_d(A,B));
			break;
		}
		case 9: {
			printf("\n A == B .\n");
			printf("%b",op_comp(A,B));
			break;
		}
		case 0: {
			break;
		}
		default: {
			break;
		}
		}
	}while(opcionSeleccionada != 0);
	
	return 0;
}

int opcion() {
	int op;
	printf("\n----------------------------\n");
	printf("1. Inicializar conjuntos.\n");
	printf("--Conjunto A-- \n");
	printf("2. Agregar elemento.\n");
	printf("3. Quitar  elemento.\n");
	printf("--Conjunto B-- \n");
	printf("4. Agregar elemento.\n");
	printf("5. Quitar  elemento.\n");
	printf("--Operaciones-- \n");
	printf("6. Union		 A + B .\n");
	printf("7. Interseccion  A * B .\n");
	printf("8. Diferencia.	 A - B .\n");
	printf("9. Comparar.	 A == B .\n");
	printf("0. Salir.\n");
	printf("Seleccione una opcion: ");
	scanf("%i", &op);
	fflush(stdin);
	return op;
}
