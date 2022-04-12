#pragma once

struct Estudiante{
	long id;
  float nota;
	int edad;
	const char* nombre, *apellido, *correo;
	long long telefono;
	
};

struct Nodo{
  Estudiante estudiante;
  Nodo* sig;
};

