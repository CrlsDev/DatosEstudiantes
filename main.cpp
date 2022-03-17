#include <iostream>
#include <fstream>
#include ".\modulos\funciones.hpp" //se incluyo el archivo de funciones

using namespace std;
int main(int argc, char** argv) {
  Nodo* cabeza=NULL;

  long id=1212;
  float nota=1.5;
  //cout<<"meter id:"<<id;
 // cout<<"meter nota;"<<nota;
  colaMeter(cabeza, id, nota);
  colaMeter(cabeza, 12 , 1213);
  Mostrar(cabeza);
}
