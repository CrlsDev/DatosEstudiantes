#include <iostream>
#include <fstream>
#include<windows.h>
//#include ".\modulos\ControlDatos.hpp" //se incluyo el archivo de funciones

using namespace std;

int main(int argc, char** argv) {
	
	HANDLE cur; 
	COORD pos; 
	cur = GetStdHandle(STD_OUTPUT_HANDLE);
	
		int op,op1,bsc,mov,opr;
		
		pos.Y  =  10;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"ESCOJA UNA OPCION\n";
   		pos.Y  =  12;  pos.X  = 45;  SetConsoleCursorPosition(cur,pos); cout<<"1.............Pila\n";
   		pos.Y  =  13;  pos.X  = 45;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Cola\n";
   		pos.Y  =  14;  pos.X  = 45;  SetConsoleCursorPosition(cur,pos); cout<<"opcion:";
   		pos.Y  =  14;  pos.X  =  52;  SetConsoleCursorPosition(cur,pos);cin>>op;
   		
   		
   			switch (op)
			{
				
			case 01: 
			
				system ("CLS");

				pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"MENU PRINCIPAL PILA\n";
				pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............Meter Dato\n";
				pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Sacar Dato\n";
				pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Mostrar";
				pos.Y  =  9;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"4.............Buscar\n";
				pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"5.............Intercambiar Datos\n";
				pos.Y  =  11;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"6.............Operar\n";
				pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"7.............Respaldo de Datos\n";
				pos.Y  =  14;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
				pos.Y  =  14;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>op1;	
										
					switch (op1)
					{
					
						case 1:
							pos.Y  =  16;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"Ingrese prueba meter \n";
							
						break;
						case 2:
							pos.Y  =  16;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<" prueba sacar \n";

						break;
						case 3:
							pos.Y  =  16;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"Prueba mostrar \n";

						break;
						case 4:
							
							system ("CLS");
							
							pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"BUSCAR\n";
							pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............Buscar por ID\n";
							pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Buscar por Nota\n";
							pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Regresar\n";
							pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
							pos.Y  =  10;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>bsc;
							
							switch (bsc)
							{
								system ("CLS");
								
								case 1:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"prueba id \n";
							
								break;
								case 2:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<" prueba nota \n";

								break;
							
							default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
							}
						case 5:
								
							system ("CLS");
							
							pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"INTERCAMBIAR DATOS\n";
							pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............Mover datos de Cola a Fila\n";
							pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Mover datos de Fila a Cola\n";
							pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Regresar\n";
							pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
							pos.Y  =  10;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>mov;
							
							switch (mov)
							{
								system ("CLS");
								
								case 1:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"cola a fila prueba\n";
							
								break;
								case 2:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"fila a cola prueba\n";

								break;
							
							default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
							}
						case 6:
								
							system ("CLS");
							
							pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"OPERAR\n";
							pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............Contar Estudiantes\n";
							pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Promediar Notas\n";
							pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Regresar\n";
							pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
							pos.Y  =  10;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>opr;
							
							switch (opr)
							{
								system ("CLS");
								
								case 1:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"Contar prueba\n";
							
								break;
								case 2:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"promediar prueba \n";

								break;
							
							default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
							}
						case 7:
								
							system ("CLS");
							
							pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"RESPALDO DE DATOS\n";
							pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............cargar en <MODO>\n";
							pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Guardar en <modo>\n";
							pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Guardar todo \n";
							pos.Y  =  9;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"4.............Regresar\n";
							pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
							pos.Y  =  10;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>opr;
							
							switch (opr)
							{
								system ("CLS");
								
								case 1:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"cargar prueba\n";
							
								break;
								case 2:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"guardar prueba \n";

								break;
								case 3:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"guardar todo prueba \n";

								break;
							
							default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
							}
							
						default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
				}
				
					
			break;
			
				case 2: 
			
				system ("CLS");

				pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"MENU PRINCIPAL COLA\n";
				pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............Meter Dato\n";
				pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Sacar Dato\n";
				pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Mostrar";
				pos.Y  =  9;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"4.............Buscar\n";
				pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"5.............Intercambiar Datos\n";
				pos.Y  =  11;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"6.............Operar\n";
				pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"7.............Respaldo de Datos\n";
				pos.Y  =  14;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
				pos.Y  =  14;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>op1;	
										
					switch (op1)
					{
					
						case 1:
							pos.Y  =  16;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"Ingrese prueba meter \n";
							
						break;
						case 2:
							pos.Y  =  16;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<" prueba sacar \n";

						break;
						case 3:
							pos.Y  =  16;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"Prueba mostrar \n";

						break;
						case 4:
							
							system ("CLS");
							
							pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"BUSCAR\n";
							pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............Buscar por ID\n";
							pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Buscar por Nota\n";
							pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Regresar\n";
							pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
							pos.Y  =  10;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>bsc;
							
							switch (bsc)
							{
								system ("CLS");
								
								case 1:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"prueba id \n";
							
								break;
								case 2:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<" prueba nota \n";

								break;
							
							default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
							}
						case 5:
								
							system ("CLS");
							
							pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"INTERCAMBIAR DATOS\n";
							pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............Mover datos de Cola a Fila\n";
							pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Mover datos de FIla a Cola\n";
							pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Regresar\n";
							pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
							pos.Y  =  10;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>mov;
							
							switch (mov)
							{
								system ("CLS");
								
								case 1:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"cola a fila prueba\n";
							
								break;
								case 2:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"fila a cola prueba\n";

								break;
							
							default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
							}
						case 6:
								
							system ("CLS");
							
							pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"OPERAR\n";
							pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............Contar Estudiantes\n";
							pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Promediar Notas\n";
							pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Regresar\n";
							pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
							pos.Y  =  10;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>opr;
							
							switch (opr)
							{
								system ("CLS");
								
								case 1:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"Contar prueba\n";
							
								break;
								case 2:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"promediar prueba \n";

								break;
							
							default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
							}
						case 7:
								
							system ("CLS");
							
							pos.Y  =  2;  pos.X  =  45;  SetConsoleCursorPosition(cur,pos); cout<<"RESPALDO DE DATOS\n";
							pos.Y  =  6;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"1.............cargar en <MODO>\n";
							pos.Y  =  7;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"2.............Guardar en <modo>\n";
							pos.Y  =  8;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"3.............Guardar todo \n";
							pos.Y  =  9;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"4.............Regresar\n";
							pos.Y  =  10;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos);cout<<"Opcion: \n";
							pos.Y  =  10;  pos.X  =  48;  SetConsoleCursorPosition(cur,pos);cin>>opr;
							
							switch (opr)
							{
								system ("CLS");
								
								case 1:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"cargar prueba\n";
							
								break;
								case 2:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"guardar prueba \n";

								break;
								case 3:
								pos.Y  =  12;  pos.X  =  40;  SetConsoleCursorPosition(cur,pos); cout<<"guardar todo prueba \n";

								break;
							
							default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
							}
							
						default: pos.Y  =  15;  pos.X  =  39;  SetConsoleCursorPosition(cur,pos); cout<<" No se ha digitado una opcion valido \n";
				}
				
					
			break;
}
}


			
		

