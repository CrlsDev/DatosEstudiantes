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
  PosicionarCursor(40,7); cout<<"2.............Meter dato\n";
  PosicionarCursor(40,8); cout<<"3.............Sacar dato\n";
  PosicionarCursor(40,9); cout<<"4.............Mostrar";
  PosicionarCursor(40,10); cout<<"5.............Buscar\n";
  PosicionarCursor(40,11); cout<<"6.............Intercambiar datos\n";
  PosicionarCursor(40,12); cout<<"7.............Operar\n";
  PosicionarCursor(40,13); cout<<"8.............Cambiar nota minima\n";
  PosicionarCursor(40,14); cout<<"9.............Respaldo de datos\n";
  PosicionarCursor(40,15); cout<<"10............Salir\n";
  PosicionarCursor(40,17);cout<<"Opcion: \n";
  PosicionarCursor(48,17);cin>>op1;
}

void Escoger_modo(){
  do{
    system ("CLS");
    PosicionarCursor(45,10); cout<<"ESCOJA UNA OPCION\n";
    PosicionarCursor(45,12); cout<<"1.............Pila\n";
    PosicionarCursor(45,13); cout<<"2.............Cola\n";
    PosicionarCursor(45,14); cout<<"opcion:";
    PosicionarCursor(52,14);cin>>modo;
  }while(modo!=1 && modo!=2);
  if (modo==1){
    texto_modo = "PILA";
    puntero=&pila;
  }else if (modo==2){
    texto_modo = "COLA";
    puntero=&cola;
  }
}

void Meter_dato()

    {
        if (puntero==NULL)
    {
      PosicionarCursor(40,17);cout<<"Elija un modo.";
      PosicionarCursor(40,18);system("pause");
      return;
    }
      //long id; float nota; const char* nombre;
      Estudiante* e=new Estudiante;
      bool valido, copiado=false;
    do{
      valido = true;
    system ("CLS");
    PosicionarCursor(44,11); cout<<"INGRESANDO DATO EN: "<<texto_modo;
    PosicionarCursor(45,15); cout<<"Digite id:";cin>>e->id;
    if (modo==1)
    {
      if (Buscar(pila,e->id)){
        PosicionarCursor(45,17); cout<<"Esta id ya existe"<<endl;
        system("pause");
        valido=false;
        continue;
      }
      Estudiante* coincidencia = BuscarId(cola,e->id);
      if (coincidencia!=NULL){
        valido=false;
        int pregunta;
        do{
          cout<<"La id que intente ingresar ya existe en el otro modo, Desea copiar el dato a la pila?\n 1. Si | 2. No\n";
          cin>>pregunta;

        }while(pregunta!=1 && pregunta!=2);
        if ((valido=pregunta==1)){pilaMeter(pila, coincidencia);copiado=true;}
      }

    }else if (modo==2){
      if (Buscar(cola,e->id)){
        PosicionarCursor(45,17); cout<<"Esta id ya existe"<<endl;
        system("pause");
        valido=false;
        continue;
      }
      Estudiante* coincidencia = BuscarId(pila,e->id);
      if (coincidencia!=NULL){
        valido=false;
        int pregunta;
        do{
          cout<<"La id que intente ingresar ya existe en el otro modo, Desea copiar el dato a la cola?\n 1. Si | 2. No\n";
          cin>>pregunta;

        }while(pregunta!=1 && pregunta!=2);
        if ((valido=pregunta==1)){colaMeter(cola, coincidencia);copiado=true;}
      }
    
    }
    
    } while ((e->id<=0) || !valido);
    if (!copiado){
    do{
    system ("CLS");
    PosicionarCursor(44,11); cout<<"INGRESANDO DATO EN: "<<texto_modo;
    PosicionarCursor(45,15); cout<<"Digite id:"<<e->id;
    PosicionarCursor(45,16); cout<<"Digite nota (de 0 a 5):";cin>>e->nota;
    } while (!(e->nota<=5 && e->nota>=0));
    
  
    system ("CLS");
    PosicionarCursor(44,11); cout<<"INGRESANDO DATO EN: "<<texto_modo;
    PosicionarCursor(45,15); cout<<"Digite id:"<<e->id;
    PosicionarCursor(45,16); cout<<"Digite nota (de 0 a 5):"<<e->nota;
    
    PosicionarCursor(45,17); cout<<"Digite el nombre del estudiante:";cin>>e->nombre;


    if (modo==1)
    {
      pilaMeter(pila,e);
    }else if (modo==2)
    {
      colaMeter(cola,e);
    }}
  }

void Menu_sacar()
  { 
  if (puntero==NULL)
  {
    PosicionarCursor(40,17);cout<<"Elija un modo.";
    PosicionarCursor(40,18);system("pause");
    return;
  }
    Estudiante*datoSacar=sacar(*puntero); 
    PosicionarCursor(40,18);
    if (datoSacar!=NULL){
    cout<<"Se saco: ";
    mostrarEstudiante(datoSacar);
    }else
    {
      cout<<"la estructura esta vacia."<<endl;
    }
    
    PosicionarCursor(40,20);system("pause");
  }

    
void Menu_mostrar(){
  if (puntero==NULL){
    PosicionarCursor(40,17);cout<<"Elija un modo.";
    PosicionarCursor(40,18);system("pause");
    return;
  }

  system ("CLS");
  PosicionarCursor(40,3);cout<<"Estudiantes guardados: ";
  int y=5;
  MostrarEn(*puntero,40,y,1);
  PosicionarCursor(40,y);system("pause");
}

void Menu_buscar(){
  if (puntero==NULL){
    PosicionarCursor(40,17);cout<<"Elija un modo.";
    PosicionarCursor(40,18);system("pause");
    return;
  }
  do
  {
    system ("CLS");
    
    PosicionarCursor(45,2); cout<<"BUSCAR\n";
    PosicionarCursor(40,6); cout<<"1.............Buscar por ID\n";
    PosicionarCursor(40,7); cout<<"2.............Buscar por Nota\n";
    PosicionarCursor(40,8); cout<<"3.............Buscar por Nombre\n";
    PosicionarCursor(40,9); cout<<"4.............Regresar\n";
    PosicionarCursor(40,11);cout<<"Opcion: \n";
    PosicionarCursor(48,11);cin>>opr;
    
    switch (opr)
    {
      case 1:
      {
        long id;
        do
        {
          system("cls");
          PosicionarCursor(40,6);cout<<"Ingrese la id que quiere buscar: ";cin>>id;
        } while (id<=0);
        Estudiante*iden=BuscarId(*puntero,id);
        if (iden!=NULL)
        {
          PosicionarCursor(40,8);cout<<"Se encontro: ",mostrarEstudiante(iden); 
        }else{
          PosicionarCursor(40,8);cout<<"No se encontro la id: "<<id;
        }
        PosicionarCursor(40,10);system("pause");
      }
      break;
      case 2:
      {
        float nota;
        do{
          system("cls");
          PosicionarCursor(40,6);cout<<"Ingrese la nota que quiere buscar: ",cin>>nota;
        } while (!(nota>=0 && nota<=5));
        Nodo*resultados=BuscarNota(*puntero,nota);

        if (resultados!=NULL)
        {
          int n_r=Contar(resultados);
          PosicionarCursor(40,8);cout<<"Se encontraron ("<<n_r<<") resultados: ";
          MostrarEn(resultados,40,n_r,1);
          PosicionarCursor(40,n_r);
        }else{
          PosicionarCursor(40,8);cout<<"No se encontro la nota: "<<nota;
          PosicionarCursor(40,10);
        }
        system("pause");
      }
      break;

      case 3:
      {
        string nombre;
      
        system("cls");
        PosicionarCursor(40,6);cout<<"Ingrese el nombre que quiere buscar: ";cin>>nombre;
      
        Nodo*resultados=BuscarNombre(*puntero,nombre);
        if (resultados!=NULL)
        {
          int n_r=Contar(resultados);
          PosicionarCursor(40,8);cout<<"Se encontraron ("<<n_r<<") resultados: ";
          MostrarEn(resultados,40,n_r,1);
          PosicionarCursor(40,n_r);
        }else{
          PosicionarCursor(40,8);cout<<"No se encontro el nombre: "<<nombre;
          PosicionarCursor(40,10);
        }
        system("pause");
      }
      break;

      case 4:
      break;

      default: cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa";
    }
  } while (opr!=4);
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
      {
        colaSacarPilaMeter(cola,pila);
        PosicionarCursor(40,12);cout<<"COLA: ";
        int y = 14;
        MostrarEn(cola,40,y,1);
        PosicionarCursor(40,y);cout<<"PILA: ";
        MostrarEn(pila,40,y,1);
        PosicionarCursor(40,y);
      }
      break;
      case 2:
      {
        pilaSacarColaMeter(pila,cola);
        PosicionarCursor(40,12);cout<<"PILA: ";
        int y=14;
        MostrarEn(pila,40,y,1);
        PosicionarCursor(40,y);cout<<"COLA: ";
        MostrarEn(cola,40,y,1);
        PosicionarCursor(40,y);
      }
      break;
      case 3:
        PosicionarCursor(40,12);
        break;
    
      default: cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa \n";
    }
    system("pause");
  } while (opr!=3);
}
void Operar_datos(){
  if (puntero==NULL){
    PosicionarCursor(40,18);system("pause");
    PosicionarCursor(40,18);system("pause");
    return;
  }
  do
  {
    system ("CLS");

    PosicionarCursor(45,2); cout<<"OPERAR\n";
    PosicionarCursor(40,6); cout<<"1.............Contar estudiantes en "<<texto_modo;
    PosicionarCursor(40,7); cout<<"2.............Promediar notas\n";
    PosicionarCursor(40,8); cout<<"3.............Ver aprobados y reprobados\n";
    PosicionarCursor(40,9); cout<<"4.............Editar notas\n";
    PosicionarCursor(40,10); cout<<"5.............Regresar\n";
    PosicionarCursor(40,11);cout<<"Opcion: \n";
    PosicionarCursor(48,11);cin>>opr;
    
    switch (opr){
        
      case 1:
      {
        int conteo=Contar(*puntero);
        PosicionarCursor(40,13);cout<<"Hay "<<conteo<<" estudiantes";
        PosicionarCursor(40,15);system("pause");
      }
      break;
      case 2:
      {
        float prom=Promedio(*puntero);
        PosicionarCursor(40,13);cout<<"El promedio de las notas es: "<<prom<<endl;
      }
      PosicionarCursor(40,15);system("pause");
      break;
      case 3:
      {        
        PosicionarCursor(40,13);cout<<"Estudiantes aprobados: ";
        int y=14;
        MostrarEn(BuscarNotaArribaDe(*puntero,nota_minima,true),40,y,1);
        PosicionarCursor(40,y);cout<<"Estudiantes no aprobados ";
        MostrarEn(BuscarNotaDebajoDe(*puntero,nota_minima),40,y,2);
        PosicionarCursor(40,y+1);system("pause");
      }
        
      break;
      case 4:
        {
          int opcion;
          do{
            system("cls");
            float aux;
            PosicionarCursor(40,14);cout<<"Digite la id que desea editar: ",cin>>aux;
            Estudiante* e = BuscarId(*puntero,aux);
            if (e!=NULL){
              do{
                system("cls");
                PosicionarCursor(40,14);cout<<"Editando: ";mostrarEstudiante(e);
                PosicionarCursor(40,16);cout<<"Digite la nueva nota: ",cin>>aux;
              }while(aux<0 || aux>5);
              e->nota=aux;
              system("cls");
              PosicionarCursor(40,14);cout<<"Nueva nota establecida: ";
              mostrarEstudiante(e);
              PosicionarCursor(40,16);
              break;
            }else {
              
              do{
                system("cls");
                PosicionarCursor(40,14);cout<<"Digite la id que desea editar: "<<aux;;
                PosicionarCursor(40,15);cout<<"No existe esa ID en "<<texto_modo;
                PosicionarCursor(40,17);cout<<"¿Desea intentar de nuevo? 1. Si | 2. No";
                PosicionarCursor(40,18);cout<<"Su respuesta: ",cin>>opcion;

              }while(opcion!=1 && opcion!=2);                            
            }
            
          }while(opcion!=2);
        }
        PosicionarCursor(40,20);system("pause");
        break;
      case 5:
      break;
  
      default: cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa \n"; break;
    }
  } while (opr!=5);
}
void Cambiar_minima(){
  int opcion;
  bool cambio=false;
  do{
    
    system ("CLS");
    
    PosicionarCursor(40,12);cout<<"1. Cambiar nota minima";
    PosicionarCursor(40,13);cout<<"2. Regresar";
    PosicionarCursor(40,14);cout<<"Opcion: ",cin>>opcion;
    if (opcion==1){
      cambio=true;
      do{
        system ("CLS");
        PosicionarCursor(40,10);cout<<"NOTA MINIMA: "<<nota_minima;
        PosicionarCursor(40,12);cout<<"Escriba la nueva nota minima: ",cin>>nota_minima;
      }while((nota_minima>5 || nota_minima<0));
    }
  }while(opcion!=2 && opcion!=1);
  
  if (cambio){system ("CLS");PosicionarCursor(40,13);cout<<"NOTA MINIMA CAMBIADA A: "<<nota_minima;}
  PosicionarCursor(40,16);system("pause");

}


void Respaldo(){
  if (puntero==NULL)
  {
    cout<<"Elija un modo."<<endl;
    system("pause");
    return;
  }
  do
  {
      
    
    system ("CLS");
    
    PosicionarCursor(45,2); cout<<"RESPALDO DE DATOS\n";
    PosicionarCursor(40,6); cout<<"1.............Cargar en "<<texto_modo;
    PosicionarCursor(40,7); cout<<"2.............Guardar "<<texto_modo;
    PosicionarCursor(40,8); cout<<"3.............Guardar todo \n";
    PosicionarCursor(40,9); cout<<"4.............Regresar\n";
    PosicionarCursor(40,10);cout<<"Opcion: \n";
    PosicionarCursor(48,10);cin>>opr;
    
    switch (opr)
    {
      
      case 1:
        {
          Nodo*auxiliar_carga=Cargar(modo==1? cola:pila);
          int pregunta;
          if (auxiliar_carga==NULL)
          {
            PosicionarCursor(40,12);cout<<"Parece que no hay nada para cargar";
          }else{
            if(vacia(*puntero)){
              pregunta=1;
              

            }else{
              do{
                system("cls");
                PosicionarCursor(40,8);cout<<"Es posible que pierda datos que metio, Desea continuar? 1. Si | 2. No";
                PosicionarCursor(40,10);cout<<"Su respuesta: ",cin>>pregunta;
              }while(pregunta!=1 && pregunta!=2);
            }
            if (pregunta==1) {
              *puntero = auxiliar_carga;
              PosicionarCursor(40,12);cout<<"Se cargaron datos con exito";
            }
            PosicionarCursor(40,13);
          } 
          
          
        }
        break;
      case 2:
        if (Guardar(*puntero))
        {
          PosicionarCursor(40,12);cout<<"Se guardo con exito.";
        }else{
          PosicionarCursor(40,12);cout<<"No se pudo guardar. Puede que tenga que crear una carpeta llamada 'Datos' o que el programa no tenga permisos.";
        }
        PosicionarCursor(40,13);
        break;
      case 3:
        {
          Nodo* U = UnirEstructuras(pila,cola);
          if (Guardar(U))
          {
            PosicionarCursor(40,12);cout<<"Se guardo con exito.";
          }else{
            PosicionarCursor(40,12);cout<<"No se pudo guardar.";
          }
          PosicionarCursor(40,13);
        }
        break;
      case 4:
        PosicionarCursor(40,12);
        break;
    
      default: PosicionarCursor(40,12);cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa";PosicionarCursor(40,13);
    }
    system("pause");
  } while (opr!=4);
}