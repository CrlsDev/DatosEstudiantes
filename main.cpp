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

      case 3: // Sacar dato
                    Menu_sacar();
      break;

      case 4: //mostrar
                  Menu_mostrar();
        break;

      case 5: // BUSCAR
                   Buscar();
        break;

      case 6: //Intercambio de datos
               Intercambiar_datos();
        break;

      case 7: // operar
                Operar_datos();
        break;

      case 8:{
      	        Cambiar_minima();
      	break;

      case 9: // respaldo
                  Respaldo();
      break;

      case 10:
        break; 
      default:PosicionarCursor(0,20); cout<<" No se ha digitado una opcion valido. Puede que sea necesario reiniciar el programa \n";
      }
    }
    

  }while(op1!=10);
}


			
		

