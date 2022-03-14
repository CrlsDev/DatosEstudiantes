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
	void Mostrar(int p[],int t){
	if(t==0)
		cout<<"vacia";
	else
		for(int i=0;i<t;i++)
			cout<<p[i]<<" ";	
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
int contar(Nodo *aux){
	int c=0;
	while(aux!=NULL){
		c++;
		aux=aux->sig;
	}
	return c;
}

