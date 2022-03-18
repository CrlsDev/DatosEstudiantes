#pragma once
#include ".\Nodo.hpp"
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
	else
		while(aux!=NULL){
			cout<<"\nSu id es: "<<aux->id;
				cout<<"\nSu nota es de: "<<aux->nota;
			aux=aux->sig;
			
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
	
Nodo* sacar(Nodo *&cab){
	if(cab==NULL)
		return NULL;
	int id=cab->id;
	Nodo *aux=cab->sig;
	delete cab;
//	cab=aux;
	return cab;
}


