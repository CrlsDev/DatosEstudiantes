#pragma once
#include <fstream>
#include <string>
#include ".\funciones.hpp"
#include ".\Nodo.hpp"
#define SEPARADOR ";"

#define ARCHIVO_PILA "estudiantes_pila"
#define ARCHIVO_COLA "estudiantes_cola"
bool Guardar(Nodo* cab,const char* nombre){
  std::ofstream archivo(std::string(".\\Datos\\"+std::string(nombre)).c_str());
  if (!archivo) return false;

  while (cab!=NULL){
    archivo<<cab->id<<SEPARADOR<<cab->nota<<std::endl;
    cab = cab->sig;
  }
  archivo.close();
  return true;
}
Nodo* Cargar(const char* nombre){
  std::ifstream archivo(std::string(".\\Datos\\"+std::string(nombre)).c_str());
  if (!archivo) return NULL;
  Nodo* cab = NULL;
  std::string linea;
  long id;
  float nota;
  while(!archivo.eof()){
    std::getline(archivo,linea);
    int sep = linea.find_first_of(SEPARADOR);
    
    if (sep != std::string::npos){
      id = std::stoi(linea.substr(0,sep));
      nota = std::stoi(linea.substr(sep+1, linea.length()-sep));
      colaMeter(cab,id,nota);
    }
  }
  return cab; 
}

bool GuardarPila(Nodo* cab){
  return Guardar(cab, ARCHIVO_PILA);
}
bool GuardarCola(Nodo* cab){
  return Guardar(cab, ARCHIVO_COLA);
}
Nodo* CargarPila(){
  return Cargar(ARCHIVO_PILA);
}
Nodo* CargarCola(){
  return Cargar(ARCHIVO_COLA);
}