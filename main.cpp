#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "conjunto.h"
#include "conjunto_d.h"
#include "automata.h"

using namespace std;

void pausa()

{
	
	cout << "Pulsa una tecla para continuar...";
	
	getwchar();
	
	getwchar();
	
}

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
	char tecla;
	do
		
	{
		system("cls");
		cin.clear();
		printf("\n");
		printf("\n");
		
		cout << " \t    AUTOMATA" << endl;
		
		cout << "\t --------------" << endl << endl;
		
		cout << "\t1 .- Crear nuevo Automata" << endl;
		
		cout <<"\t2 .- Ingrese Cadena de caracteres par ser procesadas por el Automata" <<endl;
		
		cout << "\t3 .- Borrar Automata" << endl;
		
		cout << "\t4 .- Salir" << endl;
		
		cout << "Elije una opcion: ";
		
		cin >> tecla;
		
		switch(tecla)
			
		{
			
		case '1':
			{
			system("cls");
			
			cout << "CREAR NUEVO AUTOMATA.\n";
			CONJUNTO Q,Z,F;
			Inicia(&Q);
			Inicia(&Z);
			Inicia(&F);
			cout << "\t1 .- Ingrese los estados de a uno seguida de la tecla enter \n" << endl;
			cout<<"\t Para finalizar presione 0...\n"<<endl;
			cin >> tecla;
			
			while(tecla!='0')
			
			{
				Q = Q + (Item)tecla;
			}
			
			cout << "\t2 .- Ingrese los estados de aceptacion " << endl;
			cout<<"\t Para finalizar presione 0...\n"<<endl;
				cin>> tecla;
			while(tecla!='0')
			{
				F = F + (Item)tecla;
			}
			cout << "\t3 .- Ingrese el alfabeto, para finalizar presione 0...\n" << endl;
			cin>> tecla;
			while(tecla!='0')
			{
				Z = Z+(Item)tecla;
			}
			AUTOMATA A ;
			cout <<"\t4.-Ingrese el estado Inicial...\n "<<endl;
			cin>> tecla;
			Item inicial=(Item)tecla;
			Inicia(&A,Q,Z,inicial,F);
			cout <<"\t5 .- Ingrese las funciones de transiciones del Automata..\n"<<endl;
			cin>>tecla;
			pausa();
			break;
		}
			
		case '2':
			
			system("cls");
			
			cout << "PROCESAR CADENA.\n";
			
			pausa();
			
			break;
			
		case '3':
			
			system("cls");
			
			cout << "BORRAR AUTOMATA.\n";
			
			pausa();
			
			break;
			
			
		case '4':
			
			bandera=true;
			
			
			break;
			
			
		default:
			
			system("cls");
			
			cout << "Opcion no valida.\a\n";
			
			pausa();
			
			break;
			
		}
		
	}while(bandera!=true);
	
	
	
	return (0);
	
}

