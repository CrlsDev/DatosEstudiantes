#include <iostream>
#include <fstream>
#include "modulos/funciones.hpp"
#include ".\modulos\ControlDatos.hpp" //se incluyo el archivo de funciones
#include "modulos/menu.hpp"
using namespace std;



int main(int argc, char** argv) {
  

  do{

    Menu_principal();
          
    switch (op1)
    {
      case 1: //SELECCIONAR OPCION PILA O COLA.
         Escoger_Modo();
        break;
      case 2: //METER DATO
        
         Meter_dato();
      
        break;
      case 3: // prueba sacar
      
       
      break;

      case 4: //mostrar
        Menu_mostrar();
        break;

      case 5: // BUSCAR
        
        Buscar();
        break;

      case 6: //Intercambio de datos
        do
          {
          system ("CLS");
        
          PosicionarCursor(45,2); cout<<"INTERCAMBIAR DATOS\n";
          PosicionarCursor(40,6); cout<<"1.............Mover datos de Cola a Pila\n";
          PosicionarCursor(40,7); cout<<"2.............Mover datos de Pila a Cola\n";
          PosicionarCursor(40,8); cout<<"3.............Regresar\n";
          PosicionarCursor(40,10);cout<<"Opcion: \n";
          PosicionarCursor(48,10);cin>>opr;
        
          switch (opr)
        {
          
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
        break;
      case 7: // operar
      if (puntero==NULL)
        {
          cout<<"Elija un modo."<<endl;
          system("pause");
          break;
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
        
        switch (opr)
        {
          
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
        
        break;
      case 8:{
      	Cambiar_minima();
      	break;
      case 9: // respaldo
      
      break;
      case 10:
        break; 
      default:PosicionarCursor(0,20); cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa \n";
      }
    }
    

  }while(op1!=10);
}


			
		

