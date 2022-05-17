#pragma once
#include ".\Nodo.hpp"
#include<windows.h>
#include <iostream>
//CONFIGURACIONES DE CURSOR
static HANDLE cur; 
static COORD pos;
using namespace std;
void PosicionarCursor(int x, int y){
   
	cur = GetStdHandle(STD_OUTPUT_HANDLE);
  pos.Y  =  y;  pos.X  =  x;  SetConsoleCursorPosition(cur,pos);
}
void pilaMeter(Nodo *&cab,Estudiante* e){
	Nodo *aux=new Nodo;

	aux->estudiante=e;
	aux->sig=cab;
	cab=aux;

}
void colaMeter(Nodo *&cab,Estudiante* e){
	Nodo *aux=new Nodo;
	aux->estudiante=e;
	aux->sig=NULL;
	if(cab==NULL)
		cab=aux;
	else{
		Nodo *ult=cab;
		while(ult->sig!=NULL)
			ult=ult->sig;
		ult->sig=aux;
	}
}

bool vacia(Nodo *cab){
	return cab==NULL;
}

void mostrarEstudiante(Estudiante* e, int x, int y){
	PosicionarCursor(x,y);cout<<"id: "<<e->id;
				cout<<",nota: "<<e->nota;
       cout<<",nombre: "<<e->nombre;
}
void Mostrar(Nodo *aux,int x=0,int y_i=0){
	if(aux==NULL)
		cout<<"Vacia"<<endl;
	else{
		while(aux!=NULL){
			mostrarEstudiante(aux->estudiante,x,y_i);
			y_i++;
			aux=aux->sig;
			
		}
		cout<<endl;
	}		
}

bool Buscar(Nodo *aux,long id){
	
	while(aux!=NULL){
		if(id==aux->estudiante->id)
			return true;
		aux=aux->sig;
	}
	return false;
}
 Estudiante*BuscarId(Nodo*cab,long id){
	 while(cab!=NULL){
		if(id==cab->estudiante->id){
	Estudiante* aux=cab->estudiante;
			return aux;

		}
		cab=cab->sig;
	}
	return NULL;

 }
 Nodo*BuscarNota(Nodo*cab,float nota){
	 Nodo*aux=NULL;
	 while(cab!=NULL){
		if(nota==cab->estudiante->nota){
			pilaMeter(aux,cab->estudiante);
		}
		cab=cab->sig;
	}

	return aux;

 }
Nodo*BuscarNombre(Nodo*cab,string Nombre){
	 Nodo*aux=NULL;
	 while(cab!=NULL){
		if(Nombre==cab->estudiante->nombre){
			pilaMeter(aux,cab->estudiante);
		}
		cab=cab->sig;
	}

	return aux;

 }
 Nodo*BuscarNotaDebajoDe(Nodo*cab,float nota, bool igual=false){
	 Nodo*aux=NULL;
	 while(cab!=NULL){
		if((nota==cab->estudiante->nota && igual) || nota>cab->estudiante->nota){
			pilaMeter(aux,cab->estudiante);
		}
		cab=cab->sig;
	}

	return aux;

 }
 Nodo*BuscarNotaArribaDe(Nodo*cab,float nota, bool igual=false){
	 Nodo*aux=NULL;
	 while(cab!=NULL){
		if((nota==cab->estudiante->nota && igual) || nota<cab->estudiante->nota){
			pilaMeter(aux,cab->estudiante);
		}
		cab=cab->sig;
	}

	return aux;

 }
int contar(Nodo *aux){
	int c=0;
	while(aux!=NULL){
		c++;
		aux=aux->sig;
	}return c;
	}
float promedio(Nodo*aux){
	float suma=0;
	int conteo=0;
	while(aux!=NULL){
	suma=suma+aux->estudiante->nota;
	aux=aux->sig;
	conteo++;
	}
 return suma/conteo;}
	
	
Estudiante* sacar(Nodo *&cab){
	if(cab==NULL)
		return NULL;
	
	Nodo *aux=cab;
    cab=cab->sig;
	Estudiante* saca=aux->estudiante;
	delete aux;
	return saca;
}

void pilaSacarColaMeter(Nodo*&cabp,Nodo*&cabc){
	if(cabp==NULL) return;
	if(cabc==NULL){
		cabc=cabp;
		cabp=cabp->sig;
		cabc->sig=NULL;
	}
	else{
		Nodo*ult=cabc;
		while(ult->sig!=NULL){
		ult=ult->sig;}
		ult->sig=cabp;
		cabp=cabp->sig;
		ult->sig->sig=NULL;
	}
}
void colaSacarPilaMeter(Nodo*&cabc,Nodo*&cabp){
	if(cabc==NULL) return;
	Nodo*aux=cabp;
	cabp=cabc;
	cabc=cabc->sig;
	cabp->sig=aux;
} 

Nodo* UnirEstructuras(Nodo* cab1, Nodo* cab2){
	Nodo* Union = cab1;
	if (cab1==NULL && cab2!=NULL){
		return cab2;
	}
	while(cab2!=NULL){
		if (!Buscar(Union,cab2->estudiante->id)){
			pilaMeter(Union,cab2->estudiante);
		}
		cab2=cab2->sig;
	}
	return Union;
}


