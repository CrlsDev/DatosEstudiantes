#pragma once
#include ".\Nodo.hpp"
#include<windows.h>
#include <iostream>
//CONFIGURACIONES DE CURSOR
static HANDLE cur; 
static COORD pos;
using namespace std;
void pilaMeter(Nodo *&cab,long id,float nota){
	Nodo *aux=new Nodo;
	aux->id=id;
	aux->nota=nota;
	aux->sig=cab;
	cab=aux;
}
void colaMeter(Nodo *&cab,long id,float nota){
	Nodo *aux=new Nodo;
	aux->id=id;
	aux->nota=nota;
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
void Mostrar(Nodo *aux){
	if(aux==NULL)
		cout<<"Vacia";
	else{
		while(aux!=NULL){
			cout<<"\nid: "<<aux->id;
				cout<<",nota: "<<aux->nota;
			aux=aux->sig;
			
		}
		cout<<endl;
	}		
}

bool Buscar(Nodo *aux,long id){
	while(aux!=NULL){
		if(id==aux->id)
			return true;
		aux=aux->sig;
	}
	return false;
}
 Nodo*BuscarId(Nodo*cab,long id){
	 while(cab!=NULL){
		if(id==cab->id){
			Nodo* aux = new Nodo;
			aux->id=cab->id;
			aux->nota = cab->nota;
			return aux;

		}
		cab=cab->sig;
	}
	return NULL;

 }
 Nodo*BuscarNota(Nodo*cab,float nota){
	 Nodo*aux=NULL;
	 while(cab!=NULL){
		if(nota==cab->nota){
			pilaMeter(aux,cab->id,nota);
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
	suma=suma+aux->nota;
	aux=aux->sig;
	conteo++;
	}
 return suma/conteo;}
	
	
Nodo* sacar(Nodo *&cab){
	if(cab==NULL)
		return NULL;
	Nodo *aux=cab;
    cab=cab->sig;
	return aux;
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
		if (!Buscar(Union,cab2->id)){
			pilaMeter(Union,cab2->id, cab2->nota);
		}
		cab2=cab2->sig;
	}
	return Union;
}

void PosicionarCursor(int x, int y){
   
	cur = GetStdHandle(STD_OUTPUT_HANDLE);
  pos.Y  =  y;  pos.X  =  x;  SetConsoleCursorPosition(cur,pos);
}
