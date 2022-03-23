#include <iostream>
#include <fstream>
#include "modulos/funciones.hpp"
//#include ".\modulos\ControlDatos.hpp" //se incluyo el archivo de funciones

using namespace std;



int main(int argc, char** argv) {
  int op,op1,bsc,mov,opr, modo;
  Nodo*pila=NULL,*cola=NULL,*puntero=NULL;
  const char* texto_modo = "(NO SE HA ELEGIDO MODO)"; 
    

  do{
    
    system ("CLS");
    PosicionarCursor(45,2); cout<<"MENU PRINCIPAL "<<texto_modo<<"\n";
    PosicionarCursor(40,6); cout<<"1.............Elegir modo\n";
    PosicionarCursor(40,7); cout<<"2.............Meter Dato\n";
    PosicionarCursor(40,8); cout<<"3.............Sacar Dato\n";
    PosicionarCursor(40,9); cout<<"4.............Mostrar";
    PosicionarCursor(40,10); cout<<"5.............Buscar\n";
    PosicionarCursor(40,11); cout<<"6.............Intercambiar Datos\n";
    PosicionarCursor(40,12); cout<<"7.............Operar\n";
    PosicionarCursor(40,13); cout<<"8.............Respaldo de Datos\n";
    PosicionarCursor(40,14); cout<<"9.............Salir\n";
    PosicionarCursor(40,16);cout<<"Opcion: \n";
    PosicionarCursor(48,16);cin>>op1;	
          
    switch (op1)
    {
      case 1: //SELECCIONAR OPCION PILA O COLA.
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
		  puntero=pila;
        }else if (modo==2){
          texto_modo = "COLA";
		  puntero=cola;
		}
        break;
      case 2: //METER DATO
        cout<<"Ingrese prueba meter \n";
        long id; float nota;
		do{
		PosicionarCursor(45,15); cout<<"Digite id:",cin>>id;
		PosicionarCursor(45,16); cout<<"Digite nota:",cin>>nota;
	//bool prueba=(!(nota<=5 && nota>=0)||(id<=0));
	//	  cout<<"\n"<<prueba;
		  system("pause");
		} while (!(nota<=5 && nota>=0)||(id<=0));
      break;
      case 3:
        cout<<" prueba sacar \n";

      break;
      case 4:
        cout<<"Prueba mostrar \n";

      break;
      case 5:
        
        system ("CLS");
        
        PosicionarCursor(45,2); cout<<"BUSCAR\n";
        PosicionarCursor(40,6); cout<<"1.............Buscar por ID\n";
        PosicionarCursor(40,7); cout<<"2.............Buscar por Nota\n";
        PosicionarCursor(40,8); cout<<"3.............Regresar\n";
        PosicionarCursor(40,10);cout<<"Opcion: \n";
        PosicionarCursor(48,10);cin>>bsc;
        
        switch (bsc)
        {
          system ("CLS");
          
          case 1:
          cout<<"prueba id \n";
        
          break;
          case 2:
          cout<<" prueba nota \n";

          break;
        
          default: cout<<" No se ha digitado una opcion valido \n";
        }
      case 6:
          
        system ("CLS");
        
        PosicionarCursor(45,2); cout<<"INTERCAMBIAR DATOS\n";
        PosicionarCursor(40,6); cout<<"1.............Mover datos de Cola a Fila\n";
        PosicionarCursor(40,7); cout<<"2.............Mover datos de Fila a Cola\n";
        PosicionarCursor(40,8); cout<<"3.............Regresar\n";
        PosicionarCursor(40,10);cout<<"Opcion: \n";
        PosicionarCursor(48,10);cin>>mov;
        
        switch (mov)
        {
          system ("CLS");
          
          case 1:
          cout<<"cola a fila prueba\n";
        
          break;
          case 2:
          cout<<"fila a cola prueba\n";

          break;
        
        default: cout<<" No se ha digitado una opcion valido \n";
        }
      case 7:
          
        system ("CLS");
        
        PosicionarCursor(45,2); cout<<"OPERAR\n";
        PosicionarCursor(40,6); cout<<"1.............Contar Estudiantes\n";
        PosicionarCursor(40,7); cout<<"2.............Promediar Notas\n";
        PosicionarCursor(40,8); cout<<"3.............Regresar\n";
        PosicionarCursor(40,10);cout<<"Opcion: \n";
        PosicionarCursor(48,10);cin>>opr;
        
        switch (opr)
        {
          system ("CLS");
          
          case 1:
          cout<<"Contar prueba\n";
        
          break;
          case 2:
          cout<<"promediar prueba \n";

          break;
        
        default: cout<<" No se ha digitado una opcion valido \n";
        }
      case 8:
          
        system ("CLS");
        
        PosicionarCursor(45,2); cout<<"RESPALDO DE DATOS\n";
        PosicionarCursor(40,6); cout<<"1.............Cargar en <MODO>\n";
        PosicionarCursor(40,7); cout<<"2.............Guardar en <modo>\n";
        PosicionarCursor(40,8); cout<<"3.............Guardar todo \n";
        PosicionarCursor(40,9); cout<<"4.............Regresar\n";
        PosicionarCursor(40,10);cout<<"Opcion: \n";
        PosicionarCursor(48,10);cin>>opr;
        
        switch (opr)
        {
          system ("CLS");
          
          case 1:
          cout<<"cargar prueba\n";
        
          break;
          case 2:
          cout<<"guardar prueba \n";

          break;
          case 3:
          cout<<"guardar todo prueba \n";

          break;
        
        default: cout<<" No se ha digitado una opcion valido \n";
        }
      case 9:
        break; 
      default: cout<<" No se ha digitado una opcion valido \n";
    }
    

  }while(op1!=9);
}


			
		

