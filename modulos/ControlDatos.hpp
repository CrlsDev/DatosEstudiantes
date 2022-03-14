#pragma once
#include <fstream>
#include <string>
#include ".\funciones.hpp"
#include ".\Nodo.hpp"
bool Guardar(Nodo* cab,const char* nombre){
  std::ofstream archivo(".\\Datos\\"+std::string(nombre));
  if (!archivo) return false;

  while (cab!=NULL){
    archivo<<cab->dato<<std::endl;
    cab = cab->sig;
  }
  archivo.close();
  return true;
}
Nodo* Cargar(){

}
