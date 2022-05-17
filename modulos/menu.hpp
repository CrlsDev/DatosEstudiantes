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

void Intercambiar_datos(){
  do{
    system ("CLS");
  
    PosicionarCursor(45,2); cout<<"INTERCAMBIAR DATOS\n";
    PosicionarCursor(40,6); cout<<"1.............Mover datos de Cola a Pila\n";
    PosicionarCursor(40,7); cout<<"2.............Mover datos de Pila a Cola\n";
    PosicionarCursor(40,8); cout<<"3.............Regresar\n";
    PosicionarCursor(40,10);cout<<"Opcion: \n";
    PosicionarCursor(48,10);cin>>opr;
  
    switch (opr){
        
      case 1:
      colaSacarPilaMeter(cola,pila);
      cout<<"COLA: ";
      Mostrar(cola);
      cout<<endl<<"\nPILA: ";
      Mostrar(pila);
      system("pause");
      break;
      case 2:
      pilaSacarColaMeter(pila,cola);
      cout<<"PILA: ";
      Mostrar(pila);
      cout<<endl<<"\nCOLA: ";
      Mostrar(cola);
      system("pause");
      break;
      case 3:
      break;
    
      default: cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa \n";
    }
  } while (opr!=3);
}
void Operar_datos(){
  if (puntero==NULL){
    cout<<"Elija un modo."<<endl;
    system("pause");
    return;
  }
  do
  {
    system ("CLS");

    PosicionarCursor(45,2); cout<<"OPERAR\n";
    PosicionarCursor(40,6); cout<<"1.............Contar Estudiantes\n";
    PosicionarCursor(40,7); cout<<"2.............Promediar Notas\n";
    PosicionarCursor(40,8); cout<<"3.............Aprobado o reprobado\n";
    PosicionarCursor(40,9); cout<<"4.............Regresar\n";
    PosicionarCursor(40,10);cout<<"Opcion: \n";
    PosicionarCursor(48,10);cin>>opr;
    
    switch (opr){
        
      case 1:
      {
      int conteo=contar(*puntero);
      PosicionarCursor(40,12);cout<<"El total de las notas guardas es: "<<conteo<<endl;
      PosicionarCursor(40,14);system("pause");}
      break;
      case 2:{
      float prom=promedio(*puntero);
      PosicionarCursor(40,12);cout<<"El promedio de las notas es: "<<prom<<endl;}
      PosicionarCursor(40,14);system("pause");
      break;
      case 3:{
        
        cout<<endl<<"Estudiantes aprobados: "<<endl;
        Mostrar(BuscarNotaArribaDe(*puntero,nota_minima,true));
        cout<<"Estudiantes no aprobados "<<endl;
        Mostrar(BuscarNotaDebajoDe(*puntero,nota_minima));}
        system("pause");
      break;
      case 4:
      break;
  
      default: cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa \n"; break;
    }
  } while (opr!=4);
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
