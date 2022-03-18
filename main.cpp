#include <iostream>
#include <fstream>
#include ".\modulos\funciones.hpp" //se incluyo el archivo de funciones

using namespace std;
 Nodo* BuscarTraer(Nodo *aux,long id);
int main(int argc, char** argv) {
<<<<<<< HEAD
  Nodo* cabeza=NULL;
  
//  long id=1212;
//  float nota=1.5;
  //cout<<"meter id:"<<id;
 // cout<<"meter nota;"<<nota;
  colaMeter(cabeza, 1212, 1.5);
  colaMeter(cabeza, 12 , 1213);
  Mostrar(cabeza);
  
  Nodo*hallar=BuscarTraer(cabeza,12);
  cout<<"\n"<<hallar;
  if(hallar!=NULL)
  cout<<"\n"<<hallar->id<<": "<<hallar->nota;
  else{
  	cout<<"\nvacio";
	}
  
}
Nodo * BuscarTraer(Nodo *aux,long id){
	while(aux!=NULL){
		if(id==aux->id)break;
		aux=aux->sig;
	}
	return aux;
=======
	
	//hola
>>>>>>> ff7564de2f1fe0048d814020af77f13c2e314c11
}
