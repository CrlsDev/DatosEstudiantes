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

    void Escoger_Modo(){
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
          cout<<"Elija un modo."<<endl;
          system("pause");
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

     void prueba_sacar()
      { 
         if (puntero==NULL)
        {
          cout<<"Elija un modo."<<endl;
          system("pause");
          return;
        }
          Estudiante*datoSacar=sacar(*puntero); 
          PosicionarCursor(45,18);
          if (datoSacar!=NULL){
          cout<<"Saco : ";
          PosicionarCursor(45,20);
          mostrarEstudiante(datoSacar);
          }else
          {
            cout<<"la estructura esta vacia."<<endl;
          }
          
          system("pause");
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

void Buscar(){
  if (puntero==NULL)
        {
          cout<<"Elija un modo."<<endl;
          system("pause");
          break;
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
            cout<<"Ingrese la id que quiere buscar: ";cin>>id;
            } while (id<=0);
            Estudiante*iden=BuscarId(*puntero,id);
            if (iden!=NULL)
            {
              cout<<"se encontro: "<<endl;mostrarEstudiante(iden); 
            }else{
              cout<<"no se encontro la id: "<<id;
            }
            system("pause");
          }
          break;
          case 2:
          {
            float nota;
            do{
              system("cls");
              cout<<"Ingrese la nota que quiere buscar: ";cin>>nota;
            } while (!(nota>=0 && nota<=5));
            Nodo*resultados=BuscarNota(*puntero,nota);
            if (resultados!=NULL)
            {
              cout<<"se encontro: "<<endl;
              Mostrar(resultados);
            }else{
              cout<<"no se encontro la nota: "<<nota;
            }
            system("pause");
          }
          break;

          case 3:
          {
            string nombre;
         
              system("cls");
              cout<<"Ingrese el nombre que quiere buscar: ";cin>>nombre;
          
            Nodo*resultados=BuscarNombre(*puntero,nombre);
            if (resultados!=NULL)
            {
              cout<<"se encontro: "<<endl;
              Mostrar(resultados);
            }else{
              cout<<"no se encontro el nombre: "<<nombre;
            }
            system("pause");
          }
          break;

          case 4:
          break;

          default: cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa \n";
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


void Respaldo(){
if (puntero==NULL)
        {
          cout<<"Elija un modo."<<endl;
          system("pause");
          break;
        }
        do
        {
          
        
        system ("CLS");
        
        PosicionarCursor(45,2); cout<<"RESPALDO DE DATOS\n";
        PosicionarCursor(40,6); cout<<"1.............Cargar en "<<texto_modo;
        PosicionarCursor(40,7); cout<<"2.............Guardar en "<<texto_modo;
        PosicionarCursor(40,8); cout<<"3.............Guardar todo \n";
        PosicionarCursor(40,9); cout<<"4.............Regresar\n";
        PosicionarCursor(40,10);cout<<"Opcion: \n";
        PosicionarCursor(48,10);cin>>opr;
        
        switch (opr)
        {
          
          case 1:
            {Nodo*auxiliar_carga=Cargar();
              int pregunta;
            if (auxiliar_carga==NULL)
            {
              cout<<"No hay nada que cargar"<<endl;
            }else{
              if(vacia(*puntero)){
                pregunta=1;
                cout<<"Se cargaron datos con exito"<<endl;

              }
              else{
                do{
                  system("cls");
                  cout<<"Es posible que pierda datos que metio, Desea continuar?\n 1. Si | 2. No\n";
                  cin>>pregunta;
                }while(pregunta!=1 && pregunta!=2);
              }
              if (pregunta==1) *puntero = auxiliar_carga;
            }
              system("pause");}
            break;
          case 2:
            if (Guardar(*puntero))
            {
              cout<<"Se guardo con exito."<<endl;
            }else{
              cout<<"No se pudo guardar. Puede que tenga que crear una carpeta llamada 'Datos' o que el programa no tenga permisos."<<endl;
            }
            system("pause");
            break;
          case 3:
            {Nodo* U = UnirEstructuras(pila,cola);
            if (Guardar(U))
            {
              cout<<"Se guardo con exito."<<endl;
            }else{
              cout<<"No se pudo guardar."<<endl;
            }
            
            system("pause");}
            break;
          case 4:
          break;
        
        default: cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa \n";
        }
        } while (opr!=4);
}
