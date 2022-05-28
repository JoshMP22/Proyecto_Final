#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Conector.h"
using namespace  std;
class Puesto {

private: string puesto; int buscador = 0, idpuesto = 0;

public:
	Puesto() {}
	Puesto(string p) {
		puesto = p;
	}
	void setPuesto(string p) { puesto = p; }
	string getPuesto() { return puesto; }

	void crear() {
		int q_estado;
		Conector cn = Conector();

		cn.abrir_coneccion();

		if (cn.getConectar()) {
			string  insertar = "INSERT INTO puestos(puesto) VALUES ('" + puesto + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_coneccion();
	}

	void leer() {
		int q_estado;
		Conector cn = Conector();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			cout << "------------ Datos de los Puestos ------------" << endl;
			string consulta = "select * from puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_coneccion();


	}

	void actualizar() {

		int q_estado;
		int men = 0;
		Conector cn = Conector();
		cn.abrir_coneccion();
		string bus = to_string(buscador);

		if (cn.getConectar()) {
			system("cls");
			cout << "   ********** MENU ACTUALIZAR ********** " << endl;
			cout << " 1. Puesto" << endl;
			cout << " COLOQUE 1 PARA MODIFICAR:  ";
			cin >> men;
			cin.ignore();

			if (men == 1) {

				cout << endl << " INGRESE EL PUESTO CORRECTO:   ";
				getline(cin, puesto);
				string id = to_string(idpuesto);
				string update = "UPDATE empresa_c.puesto SET puesto = " + puesto + " WHERE(idpuesto = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		system("pause");
		cn.cerrar_coneccion();

	}

	void eliminar() {

		int q_estado, q_stado;
		/*int c = 1, r = 0, im = 0;
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;*/

		Conector cn = Conector();
		cn.abrir_coneccion();
		string id = to_string(idpuesto);
		if (cn.getConectar()) {

			string delite = "DELETE FROM empresa_c.puesto WHERE idpuesto = " + id + "";
			const char* i = delite.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				cout << "ELIMINADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}

		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccion();


	}
};
