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
  ofstream archivo(string(dir).c_str());
  if (!archivo) return false;

  while (cab!=NULL){
    archivo<<cab->estudiante->id<<SEPARADOR<<cab->estudiante->nota<<SEPARADOR<<cab->estudiante->nombre<<SEPARADOR<<endl;
    cab = cab->sig;
  }
  archivo.close();
  return true;
}
Nodo* Cargar(const char* dir = DIR_ARCHIVO){
  ifstream archivo(string(dir).c_str());
  if (!archivo) return NULL;
  Nodo* cab = NULL;
  string linea;
  Estudiante *e=new Estudiante;
  stringstream * conversion;
  bool saltar=false;
  while(!archivo.eof()){
    getline(archivo,linea);
    string datos[C_DATOS];
    int i=0,num_c=0;
    cout<<endl<<"En prueba: "<<linea<<endl;  
    for (int j=0;j<C_DATOS;j++){
      if (j==0) num_c = linea.find(SEPARADOR);
      else {
        i=i+num_c+1;
        num_c=linea.find(SEPARADOR,i)-i;
      }
      if (num_c==string::npos) {saltar=true;break;}
      datos[j]=linea.substr(i,num_c);
    }
    if (saltar) {cout<<"No se puede cargar"<<endl;break;}
    cout<<"Se puede cargar"<<endl;
    conversion = new stringstream();
    *conversion<<datos[0]; *conversion>>e->id;
    conversion = new stringstream();
    *conversion<<datos[1]; *conversion>>e->nota;
    e->nombre=datos[2];
    colaMeter(cab,e);
  }
  return cab; 
}
