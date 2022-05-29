#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Conector.h"
#include "Persona.h"


using namespace std;

class Cliente : Persona {
private: string nit; int buscador = 0, idcliente = 0;
	   
public:
	Cliente() {
	}
	Cliente(int idc, string nom, string ape, string gen, string tel, string ce, string fi, string n) : Persona(nom, ape, gen, tel, ce, fi) {
		nit = n;
		idcliente = idc;
	}

	void setidcliente(int idc ) { idcliente = idc; }
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setGenero(string gen) { genero = gen; }
	void setTelefono(string tel) { telefono = tel; }
	void setCorreo_Electronico(string ce) { correo_electronico = ce; }
	void setFecha_Ingreso(string fi) { fecha_ingreso = fi; }
	
	
        int getidcliente() { return idcliente; }
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getGenero() { return genero; }
	string getCorreo_Electronico() { return correo_electronico; }
	string getTelefono() { return telefono; }
	string getFecha_Ingreso() { return fecha_ingreso; }

	void crear() {

		int q_estado;
		Conector cn = Conector();
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string insertar = "INSERT INTO empresa_c.clientes(nombres, apellidos, NIT, genero, telefono, correo_electronico, fechaingreso) VALUES(" + nombres + ",'" + apellidos + "','" + nit + "', " + genero + ", '" + telefono + "', '" + correo_electronico + "', current_time() )";
			
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESADO CON EXITO .... \n";

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

	void leer() {
		int q_estado;
		Conector cn = Conector();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "SELECT * FROM empresa_c.clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << " ID   |  Nombre  |  Apellido     |   NIT      |  Genero | Telefono | Correo Electronico | FECHA INGRESO" << endl;
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
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
			cout << " 1. Nombre" << endl;
			cout << " 2. Apellido" << endl;
			cout << " 3. NIT" << endl;
			cout << " 4. Genero" << endl;
			cout << " 5. Telefono" << endl;
			cout << " 6. Correo Electronico" << endl;
			cout << " 7. FECHA DE INGRESO" << endl;
			cout << " 8. TODOS LOS CAMPOS" << endl;
			cout << " QUE CAMPO DESEA MODIFICAR:  ";
			cin >> men;
			cin.ignore();

			if (men == 1) {

				cout << endl << " INGRESE LOS NOMBRES CORRECTOS:   ";
				getline(cin, nombres);
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.cliente SET nombres = '" + nombres + "' WHERE(idcliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}

			else if (men == 2) {

				cout << endl << " INGRESE LOS APELLIDOS CORRECTOS:   ";
				getline(cin, apellidos);
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.cliente SET apellidos = '" + apellidos + "' WHERE(idcliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}

			else if (men == 3) {

				cout << endl << " INGRESE NIT CORRECTO:   ";
				cin >> nit;
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.cliente SET NIT = '" + nit + "' WHERE(idcliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}

			else if (men == 4) {

				cout << endl << " INGRESE EL GENERO CORRECTO:   ";
				getline(cin, genero);
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.cliente SET genero = " + genero + " WHERE(idcliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}
			else if (men == 5) {

				cout << endl << " INGRESE TELEFONO CORRECTO:   ";
				cin >> telefono;
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.cliente SET telefono = '" + telefono + "' WHERE(idcliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}
			else if (men == 6) {

				cout << endl << " INGRESE CORREO ELECTRONICO CORRECTO:   ";
				getline(cin, correo_electronico);
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.cliente SET correo_electronico = '" + correo_electronico + "' WHERE(idcliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}


			else if (men == 7) {
				cout << endl;

				cout << " INGRESE NOMBRES:                ";
				getline(cin, nombres);
				cout << " INGRESE APELLIDOS:         ";
				getline(cin, apellidos);
				cout << "INGRESE NIT:   ";
				cin >> nit;
				cout << " INGRESE GENERO:   ";
				getline(cin, genero);
				cout << " INGRESE telefono:   ";
				cin >> telefono;
				cout << "INGRESE CORREO ELECTRONICO:        ";
				getline(cin, correo_electronico);
				cout << "INGRESE FECHA DE INGRESO:        ";
				getline(cin, fecha_ingreso);

				string id = to_string(idcliente);

				string update = "UPDATE empresa_c.cliente SET nombres = '" + nombres + "', apellidos = '" + apellidos + "', NIT = '" + nit + "', genero = " + genero + ", teledono = '" + telefono + "', correo_electronico = '" + correo_electronico + "' WHERE(idcliente = " + id + ")"; const char* i = update.c_str();
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
		string id = to_string(idcliente);
		if (cn.getConectar()) {

			string delite = "DELETE FROM empresa_c.cliente WHERE idcliente = " + id + "";
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
