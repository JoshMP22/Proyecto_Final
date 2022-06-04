#pragma once
#include <iostream>
using namespace std;
class Persona
{
	
protected: string nombres, apellidos, telefono, correo_electronico, fecha_ingreso;
		 int genero;

protected:
	Persona() {
	}
	Persona(string nom, string ape, int gen, string tel, string ce, string fi) {
		nombres = nom;
		apellidos = ape;
		genero = gen;
		telefono = tel;
		correo_electronico = ce;
		fecha_ingreso = fi;
	}
};
