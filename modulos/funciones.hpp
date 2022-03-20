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
	if(cabp==NULL)
	return;
	if(cabc==NULL){
	cabc==cabp;
	cabp=cabp->sig;
	cabc->sig=NULL;	//revisar
	}
	else{
	Nodo*ult=cabc;
	while(ult->sig!=NULL){
	ult=ult->sig;}
	ult->sig=cabp;
	cabp=cabp->sig;
	ult->sig->sig=NULL; //revisar
}}
void colaSacarPilaMeter(Nodo*&cabc,Nodo*&cabp){
	if(cabc==NULL)
	return;
	if(cabp==NULL){
	cabp=cabc;
	cabc=cabc->sig;
	cabp->sig=NULL; //revisar
	}
	else{
		
		Nodo*aux=cabp;
		cabp=cabc;
		cabc=cabc->sig;
		cabp->sig=aux; //revisar
	}
} 
