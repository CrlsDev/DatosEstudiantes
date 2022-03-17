#pragma once
#include ".\Nodo.hpp"

void pilaMeter(Nodo *&cab,int d){
	Nodo *aux=new Nodo;
	aux->dato=d;
	aux->sig=cab;
	cab=aux;
}
void colaMeter(Nodo *&cab,int d){
	Nodo *aux=new Nodo;
	aux->dato=d;
	aux->sig=NULL;
	if(cab==NULL)
		cab=aux;
	else{
		Nodo *ult=cab;
		while(ult->sig!=NULL)
			ult=ult->sig;
		ult->sig=aux;
	}
	bool vacia(NODO *cab){
	return cab==NULL;
}
	void mostrar(NODO *aux){
	if(aux==NULL)
		cout<<"Vacia";
	else
		while(aux!=NULL){
			cout<<" "<<aux->dato;
			aux=aux->sig;
		}
}
bool Buscar(int p[],int t,int d){
	for(int i=0;i<t;i++)
		if(d==p[i])
			return true;
	return false;	
}
bool pilaVacia(Nodo *cab){
	return cab==NULL;
}
bool buscar(NODO *aux,int d){
	while(aux!=NULL){
		if(d==aux->dato)
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
	}
	int sacar(NODO *&cab){
	if(cab==NULL)
		return 0;
	int d=cab->dato;
	NODO *aux=cab->sig;
	delete cab;
	cab=aux;
	return d;
}
	return c;
}

