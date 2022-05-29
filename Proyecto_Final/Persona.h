#pragma once
#include <iostream>
using namespace std;
class Persona
{
	
protected: string nombres, apellidos, genero, correo_electronico, fecha_ingreso;
		 int telefono = 0;

protected:
	Persona() {
	}
	Persona(string nom, string ape, string gen, string tel, string ce, string fi) {
		nombres = nom;
		apellidos = ape;
		genero = gen;
		telefono = tel;
		correo_electronico = ce;
		fecha_ingreso = fi;
	}
};
