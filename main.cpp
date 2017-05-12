#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "conjunto.h"
#include "conjunto_d.h"
#include "automata.h"

using namespace std;

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
//	ejemplo1();	//determinista
//	printf("\n");
//	ejemplo2(); //no determinista
//	return(0);
	bool bandera=false;
	char op;
	Item tecla;
	AUTOMATA A ;		
	Inicia(&A);
	do
	{
		system("cls");
		cin.clear();
		printf("\n");
		
		cout << "\t    AUTOMATA" << endl;
		cout << "\t --------------" << endl;
		cout << "\t 1 .- Crear nuevo Automata" << endl;
		cout << "\t 2 .- Mostrar Automata" << endl;
		cout << "\t 3 .- Procesar Cadena" << endl;
		cout << "\t 4 .- Borrar Automata" << endl;
		cout << "\t 5 .- Salir" << endl;
		cout << "Elije una opcion: ";
		
		cin >> op;
		switch(op)
		{
			case '1':
			{
				system("cls");
				cout << "\t CREAR NUEVO AUTOMATA." << endl;;
				
				CONJUNTO Z,Q,F;
				Inicia(&Z);
				Inicia(&Q);				
				Inicia(&F);
				
				cout << "\t 1 .- Ingrese el ALFABETO (de a uno seguido de la tecla enter)" << endl;
				cout << "\t Para finalizar ingrese *" << endl;
				cin >> tecla;
				while(strcmp(tecla,"*")!=0)
				{					
					Z = Z + tecla;
					tecla = (char *) malloc(sizeof(char));
					cin >> tecla;
				}
				
				cout << "\t 2 .- Ingrese los ESTADOS (de a uno seguido de la tecla enter)" << endl;
				cout << "\t Para finalizar ingrese *" << endl;
				cin >> tecla;
				while(strcmp(tecla,"*")!=0)
				{
					Q = Q +  tecla;
					tecla = (char *) malloc(sizeof(char));
					cin >> tecla;
				}
				
				cout << "\t 3 .- Ingrese los ESTADOS DE ACEPTACION"  << endl;
				cout << "\t (de a uno seguido de la tecla enter)" << endl;
				cout << "\t Para finalizar ingrese *" << endl;
				cin >> tecla;
				while(strcmp(tecla,"*")!=0)
				{
					F = F +  tecla;
					tecla = (char *) malloc(sizeof(char));
					cin >> tecla;
				}											
				
				cout <<"\t 4.-Ingrese el ESTADO INICIAL (seguido de la tecla enter)" << endl;
				Item q = (char *) malloc(sizeof(char));
				cin >> q;
				if (Inicia(&A,Q,Z,q,F))
				{
					cout <<"\t FUNCION DE TRANSICION\n" << endl;
					cout <<"-1)Ingrese ESTADO-ORIGEN (seguido de la tecla enter)" << endl;
					cout << "(Para finalizar ingrese *): ";
					cin >> tecla;
					while(strcmp(tecla,"*")!=0)
					{
						cout <<"-2)Ingrese SIGNO (seguido de la tecla enter): ";
						Item signo = (Item) malloc(sizeof(Item));
						cin >> signo;
						cout <<"-3)Ingrese ESTADO-DESTINO (seguido de la tecla enter): ";
						Item destino = (Item) malloc(sizeof(Item));
						cin >> destino;
						d(&A,tecla,signo,destino);
						tecla = (char *) malloc(sizeof(char));
						cout <<"-1)Ingrese ESTADO-ORIGEN (seguido de la tecla enter)" << endl;
						cout << "(Para finalizar ingrese *): ";
						cin >> tecla;
					}
				}
				else
					system("pause");
				break;
			}
			case '2':
			{
				system("cls");			
				Mostrar(A);
				system("pause");
				break;
			}
			case '3':
			{
				system("cls");			
				cout << "\t PROCESAR CADENA." << endl;
				cout << "Ingrese una cadena (seguido de la tecla enter): ";
				cin >> tecla;
				if (procesar(A,tecla))
					printf("\nLa cadena: %s a sido Aceptada  por el AUTOMATA\n",tecla);
				else
					printf("\nLa cadena: %s a sido Rechazada por el AUTOMATA\n",tecla);
				system("pause");
				break;
			}
			case '4':
			{
				system("cls");
				cout << "\t BORRAR AUTOMATA." << endl;
				cout << "Esta seguro de borrar el automata? (S/N): ";
				cin >> tecla;
				if(strcmp(tecla,"S")==0)
				{
					Inicia(&A);
					cout << "El automata se a borrado\n";
				}
				else
				   cout << "Cancelado\n\a";
				system("pause");
				break;
			}
			case '5':
			{
				bandera=true;
				break;
			}
			default:
			{
				system("cls");			
				cout << "Opcion no valida.\a" << endl;
				system("pause");
				break;
			}
		}

	} while(bandera!=true);
	
	return (0);	
}
