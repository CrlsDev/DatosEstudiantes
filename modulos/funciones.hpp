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

void PosicionarCursor(int x, int y){
   
	cur = GetStdHandle(STD_OUTPUT_HANDLE);
  pos.Y  =  y;  pos.X  =  x;  SetConsoleCursorPosition(cur,pos);
}
