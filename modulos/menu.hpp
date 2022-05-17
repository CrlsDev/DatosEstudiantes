#pragma once
#include <iostream>
#include ".\funciones.hpp"
#include ".\ControlDatos.hpp"

int op1,mov,opr, modo;
Nodo*pila=NULL,*cola=NULL;

Nodo**puntero=NULL;
const char* texto_modo = "(NO SE HA ELEGIDO MODO)"; 
float nota_minima =3.0;

void Menu_principal(){
	system ("CLS");
    PosicionarCursor(45,2); cout<<"MENU PRINCIPAL "<<texto_modo<<"\n";
    PosicionarCursor(40,6); cout<<"1.............Elegir modo\n";
    PosicionarCursor(40,7); cout<<"2.............Meter Dato\n";
    PosicionarCursor(40,8); cout<<"3.............Sacar Dato\n";
    PosicionarCursor(40,9); cout<<"4.............Mostrar";
    PosicionarCursor(40,10); cout<<"5.............Buscar\n";
    PosicionarCursor(40,11); cout<<"6.............Intercambiar Datos\n";
    PosicionarCursor(40,12); cout<<"7.............Operar\n";
    PosicionarCursor(40,13); cout<<"8.............Cambiar nota minima\n";
    PosicionarCursor(40,14); cout<<"9.............Respaldo de Datos\n";
    PosicionarCursor(40,15); cout<<"10.............Salir\n";
    PosicionarCursor(40,17);cout<<"Opcion: \n";
    PosicionarCursor(48,17);cin>>op1;
}

void Menu_mostrar(){
    if (puntero==NULL){
    cout<<"Elija un modo."<<endl;
    system("pause");
    return;
  }
    
  system ("CLS");
  
  
  Mostrar(*puntero);
  system("pause");
}

void Cambiar_minima(){
  int opcion;
  do{
    
    system ("CLS");
    
    PosicionarCursor(40,12);cout<<"1. Cambiar nota minima";
    PosicionarCursor(40,13);cout<<"2. Regresar";
    PosicionarCursor(40,14);cout<<"Opcion: ",cin>>opcion;
    if (opcion==1){
      do{
        system ("CLS");
        PosicionarCursor(40,10);cout<<"NOTA MINIMA: "<<nota_minima;
        PosicionarCursor(40,12);cout<<"Escriba la nueva nota minima: ",cin>>nota_minima;
      }while((nota_minima>5 || nota_minima<0));
    }
  }while(opcion!=2 && opcion!=1);
  system ("CLS");
  PosicionarCursor(40,13);cout<<"NOTA MINIMA CAMBIADA A: "<<nota_minima;
  PosicionarCursor(40,16);system("pause");
}