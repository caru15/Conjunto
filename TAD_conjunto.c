#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_conjunto.h"

void inicializa(t_conjunto *c)
{
	t_conjunto n;
	n.numElem = 0;
	*c=n;
}

bool estaVacio(t_conjunto c)
{
    return (c.numElem==0);
}

bool estaLleno(t_conjunto c)
{
    return (c.numElem==MAX);
}

int pertenece(t_conjunto c,char valor [MAX])
{
   int i,pos=-1;
   if(!estaVacio(c))
   {
        for(i=0;i<c.numElem && pos==-1;i++)
        {
              if(c.elementos[i]==*valor)
                   pos=i;
        }
   }
   return pos;
}

t_conjunto op_u(t_conjunto A,t_conjunto B)
{
  t_conjunto C;
 
  int i=0,j=0;
  while(i<A.numElem)
  {
       C.elementos[i]=A.elementos[i];
       i++;
  }
  while(j<B.numElem)
  {
       if(pertenece(A,&B.elementos[j])==-1)
       {
          C.elementos[i]=B.elementos[j];
          i++;
       }
       j++;
  }
  C.numElem=i;     
  return C;
}

t_conjunto op_i(t_conjunto A,t_conjunto B)
{
  t_conjunto C;
 
  int i,j=0;
  for(i=0;i<A.numElem;i++)
  {
     if(pertenece(B,&A.elementos[i])!=-1)
        C.elementos[j++]=A.elementos[i];
  }
  C.numElem=j;
  return C;
}

t_conjunto op_d(t_conjunto A,t_conjunto B)
{
  t_conjunto C;
 
  int j=0;
  for(int i=0;i<A.numElem;i++)
  {
      if(pertenece(B,&A.elementos[i])==-1)
         C.elementos[j++]=A.elementos[i];   
  }
  C.numElem=j;
  return C;
}
t_conjunto op_add(t_conjunto c,char valor[MAX])//esta pasando un parametro de estructura y una cadena de caracteres
{
	printf("valor=%s\n",valor);//aqui muestra bien
    if(!estaLleno(c))
    {
        if(pertenece(c,valor)==-1)
         {
			//strcpy(c.elementos,valor);
			 c.elementos [c.numElem]= * valor;//CONTROLAR AKI QUE GUARDA
             c.numElem++;
         }  
        else
	     {
	         printf ("ya existe el elemento");
			 getchar();
	     }		 
    }
	else
	{
		printf ("conjunto lleno");
		getchar();
	}
    return c; 
}


t_conjunto op_del(t_conjunto c,char valor [MAX])
{
    int i,pos;
    if(!estaVacio(c))
    {
       pos=pertenece(c,valor);
       if(pos!=-1)
       {
           for(i=pos;i<c.numElem-1;i++)
               c.elementos[i]= c.elementos[i+1];
           c.numElem--;   
       }
	   else
	   {
		   printf ("no existe el elemento");
		   getchar();
	   }
     }
	else
	{
		printf ("conjunto vacio");
		getchar();
	}
     return c; 
}

bool op_comp(t_conjunto A,t_conjunto B)
{
    bool igual=true;
    if(A.numElem!=B.numElem) return false;
    for(int i=0;i<A.numElem && igual;i++)
    {
        if(pertenece(B,&A.elementos[i])==-1)
           igual=false;   
    }
    return igual;    
}

void mostrar(t_conjunto c)
{
	printf ("{ ");           
	for(int i=0;i<c.numElem-1;i++)
	{
		printf("%i:%c;",i,c.elementos[i]);//aqui muestra mal
	}  
	if(c.numElem>0)
	{
		printf("%i:%c;",c.numElem-1,c.elementos[c.numElem-1]);
	}
	printf(" }");
}
/*
ostream& operator <<(ostream& co,t_conjunto c)
{
    co<<"{ ";           
    for(int i=0;i<c.numElem-1;i++)
    {
        co<<i<<":"<<c.elementos[i].etiqueta<<",";
    }  
    if(c.numElem>0)
    {
       co<<c.elementos[c.numElem-1];
    }
    co<<" }";
}
*/
