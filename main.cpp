#include <iostream>
#include <fstream>
#include ".\modulos\funciones.hpp" //se incluyo el archivo de funciones

using namespace std;
int main(int argc, char** argv) {
  Nodo* cabeza=NULL;

  long id = 4212;
  float nota = 3.5;
  colaMeter(cabeza, id, nota);
  Mostrar(cabeza);
}
