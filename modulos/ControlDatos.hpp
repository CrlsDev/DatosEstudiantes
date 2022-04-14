#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include ".\funciones.hpp"
#include ".\Nodo.hpp"

#define SEPARADOR ";"

#define DIR_ARCHIVO "./Datos/notas_estudiantes"

bool Guardar(Nodo* cab,const char* dir = DIR_ARCHIVO){
  std::ofstream archivo(std::string(dir).c_str());
  if (!archivo) return false;

  while (cab!=NULL){
    archivo<<cab->estudiante->id<<SEPARADOR<<cab->estudiante->nota<<SEPARADOR<<cab->estudiante->nombre<<std::endl;
    cab = cab->sig;
  }
  archivo.close();
  return true;
}
Nodo* Cargar(const char* dir = DIR_ARCHIVO){
  std::ifstream archivo(std::string(dir).c_str());
  if (!archivo) return NULL;
  Nodo* cab = NULL;
  std::string linea;
  Estudiante e;
  std::stringstream * conversion;
  while(!archivo.eof()){
    std::getline(archivo,linea);
    int sep = linea.find_first_of(SEPARADOR);
    if (sep != std::string::npos){
      conversion = new std::stringstream();
      *conversion<<linea.substr(0,sep); *conversion>>e.id;
      conversion = new std::stringstream();
      *conversion<<linea.substr(sep+1,linea.substr(sep+1, linea.length()-sep).find_first_of(SEPARADOR)); *conversion>>e.nota;
      e.nombre=linea.substr(linea.substr(sep+1, linea.length()-sep).find_first_of(SEPARADOR)+1,linea.length()-linea.substr(sep+1, linea.length()-sep).find_first_of(SEPARADOR));
      colaMeter(cab,&e);
    }
  }
  return cab; 
}
