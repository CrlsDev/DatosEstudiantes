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
      if (puntero==NULL)
        {
          cout<<"Elija un modo."<<endl;
          system("pause");
          break;
        }
        
        system ("CLS");
        
        
        Mostrar(*puntero);
        system("pause");
      break;

      case 5: // BUSCAR
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
      	break;
      case 9: // respaldo
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
      break;
      case 10:
        break; 
      default:PosicionarCursor(0,20); cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa \n";
    }
    

  }while(op1!=10);
}


			
		

