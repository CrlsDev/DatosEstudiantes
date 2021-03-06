#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include ".\funciones.hpp"
#include ".\Nodo.hpp"

#define SEPARADOR ";"
#define C_DATOS 3
#define DIR_ARCHIVO "./Datos/notas_estudiantes"
using namespace std;
bool Guardar(Nodo* cab,const char* dir = DIR_ARCHIVO){
  ofstream archivo(dir);
  if (!archivo) return false;

  while (cab!=NULL){
    archivo<<cab->estudiante->id<<SEPARADOR<<cab->estudiante->nota<<SEPARADOR<<cab->estudiante->nombre<<SEPARADOR<<endl;
    cab = cab->sig;
  }
  archivo.close();
  return true;
}
Nodo* Cargar(Nodo* no_valido=NULL,const char* dir = DIR_ARCHIVO){
  ifstream archivo(dir);
  if (!archivo) return NULL;
  Nodo* cab = NULL;
  string linea;
  Estudiante *e;
  stringstream * conversion;
  bool saltar=false;
  while(!archivo.eof()){
    getline(archivo,linea);
    string datos[C_DATOS];
    int i=0,num_c=0;
    for (int j=0;j<C_DATOS;j++){
      if (j==0) num_c = linea.find(SEPARADOR);
      else {
        i=num_c+1;
        num_c=linea.find(SEPARADOR,i);
      }
      if (num_c==string::npos) {saltar=true;break;}
      datos[j]=linea.substr(i,num_c-i);
    }
    if (!saltar) {
      e=new Estudiante;
      conversion = new stringstream();
      *conversion<<datos[0]; *conversion>>e->id;
      
      conversion = new stringstream();
      *conversion<<datos[1]; *conversion>>e->nota;
      e->nombre=datos[2];
      if (!Buscar(no_valido,e->id))colaMeter(cab,e);
    }
  }
  archivo.close();
  return cab; 
}
