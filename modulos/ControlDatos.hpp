#pragma once
#include <fstream>
#include <string>
#include ".\funciones.hpp"
#include ".\Nodo.hpp"
#define SEPARADOR ";"
bool Guardar(Nodo* cab,const char* nombre){
  std::ofstream archivo(".\\Datos\\"+std::string(nombre));
  if (!archivo) return false;

  while (cab!=NULL){
    archivo<<cab->id<<SEPARADOR<<cab->nota<<std::endl;
    cab = cab->sig;
  }
  archivo.close();
  return true;
}
Nodo* Cargar(const char* nombre){
  std::ifstream archivo(".\\Datos\\"+std::string(nombre));
  if (!archivo) return NULL;
  Nodo* cab = NULL;
  std::string linea;
  long id;
  float nota;
  while(!archivo.eof()){
    std::getline(archivo,linea);
    
    colaMeter(cab,id,nota);
  }
}
