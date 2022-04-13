#pragma once
#include <string>
using namespace std;
struct Estudiante{
	long id;
  float nota;
	string nombre;
};
struct Nodo{
  Estudiante* estudiante;
  Nodo* sig;
};

