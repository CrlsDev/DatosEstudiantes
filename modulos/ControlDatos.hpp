#pragma once
#include <fstream>
#include <string>
#include ".\funciones.hpp"
#include ".\Nodo.hpp"
bool Guardar(Nodo* cab,const char* nombre){
  std::ofstream archivo(".\\Datos\\"+std::string(nombre));
  if (!archivo) return false;

  while (cab!=NULL){
    archivo<<cab->id<<";"<<cab->nota<<std::endl;
    cab = cab->sig;
  }
  archivo.close();
  return true;
}
Nodo* Cargar(const char* nombre){
  std::ifstream archivo(".\\Datos\\"+std::string(nombre));
  if (!archivo) return NULL;
}
