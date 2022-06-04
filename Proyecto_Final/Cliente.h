#include <mysql.h>
#include <iostream>
#include <string>
#include "Conector.h"
#include "Persona.h"
#include<sstream>

using namespace std;

class Cliente : Persona {
private: string nit; 
	     int idcliente = 0;
	   
public:
	Cliente() {
	}
	Cliente(int idc, string nom, string ape, int gen, string tel, string ce, string fi, string n) : Persona(nom, ape, gen, tel, ce, fi) {
		nit = n;
		idcliente = idc;
	}

	void setidcliente(int idc ) { idcliente = idc; }
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setGenero(int gen) { genero = gen; }
	void setTelefono(string tel) { telefono = tel; }
	void setCorreo_Electronico(string ce) { correo_electronico = ce; }
	void setFecha_Ingreso(string fi) { fecha_ingreso = fi; }
	
	
    int getidcliente() { return idcliente; }
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	int getGenero() { return genero; }
	string getCorreo_Electronico() { return correo_electronico; }
	string getTelefono() { return telefono; }
	string getFecha_Ingreso() { return fecha_ingreso; }

	void gotoxy(int x, int y) {
		HANDLE hCon;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);

		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hCon, dwPos);
	}

	void crear() {

		int q_estado;
		Conector cn = Conector();
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string gen = to_string(genero);
			string insertar = "INSERT INTO empresa_c.clientes(nombres, apellidos, NIT, genero, telefono, correo_electronico, fechaingreso) VALUES('" + nombres + "','" + apellidos + "','" + nit + "', " + gen + ", '" + telefono + "', '" + correo_electronico + "', current_time() )";
			
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				gotoxy(0, 12); cout << "|                **** INGRESADO CON EXITO ****               |" << endl;
				cout << "|____________________________________________________________|" << endl;

			}
			else {
				gotoxy(0, 12); cout << "|                ***** ERROR AL INGRESAR *****               |" << endl;
				cout << "|____________________________________________________________|" << endl;
			}
		}
		else {

			system("cls");
			cout << "                  ____________________________________________________________ " << endl;
			cout << "                 |                                                            |" << endl;
			cout << "                 |                ***** ERROR DE CONECCION *****              |" << endl;
			cout << "                 |____________________________________________________________|" << endl;
			
		}
		cn.cerrar_coneccion();

	}

	void leer() {
		int q_estado, i=0;
		Conector cn = Conector();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM empresa_c.clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				system("cls");
				cout << " ______________________________________________________________________________________________________________________ " << endl;
				cout << "|                                            BASE DE DATOS DE CLIENTES                                                 |" << endl;
				cout << "|______________________________________________________________________________________________________________________|" << endl;
				cout << "|ID|     NOMBRES    |     APELLIDOS     |    NIT     |GEN| TELEFONO |     CORREO ELECTRONICO    |    FECHA INGRESO     |" << endl;
				cout << "|__|________________|___________________|____________|___|__________|___________________________|______________________|" << endl;
				while (fila = mysql_fetch_row(resultado)) {
				gotoxy(0, 5 + i); cout << "|  |                |                   |            |   |          |                           |                      |" << endl;
				gotoxy(1, 5 + i); cout << fila[0]; gotoxy(5, 5 + i); cout << fila[1]; gotoxy(22, 5 + i); cout << fila[2]; gotoxy(41, 5 + i); cout << fila[3]; gotoxy(54, 5 + i); cout << fila[4];
				gotoxy(58, 5 + i); cout << fila[5]; gotoxy(69, 5 + i); cout << fila[6]; gotoxy(98, 5 + i); cout << fila[7];
				i++;
				}
				cout << "\n|__|________________|___________________|____________|___|__________|___________________________|______________________|" << endl;
			}
			else {
				system("cls");
				cout << "                  ____________________________________________________________ " << endl;
				cout << "                 |                                                            |" << endl;
				cout << "                 |                ***** ERROR AL CONSULTAR *****              |" << endl;
				cout << "                 |____________________________________________________________|" << endl;
			}

		}
		else {

			system("cls");
			cout << "                  ____________________________________________________________ " << endl;
			cout << "                 |                                                            |" << endl;
			cout << "                 |                ***** ERROR DE CONECCION *****              |" << endl;
			cout << "                 |____________________________________________________________|" << endl;
		}
		cn.cerrar_coneccion();
	}

	void actualizar() {

		int q_estado;
		int men = 0;
		Conector cn = Conector();
		cn.abrir_coneccion();
		string bus = to_string(idcliente);

		if (cn.getConectar()) {
			system("cls");
			cout << " __________________________________________________________ " << endl;
			cout << "|           ********** MENU ACTUALIZAR **********          |" << endl;
			cout << "|__________________________________________________________|" << endl;
			cout << "|                                                          |" << endl;
			cout << "|   1. NOMBRES                                             |" << endl;
			cout << "|   2. APELLIDOS                                           |" << endl;
			cout << "|   3. NIT                                                 |" << endl;
			cout << "|   4. GENERO                                              |" << endl;
			cout << "|   5. TELEFONO                                            |" << endl;
			cout << "|   6. CORREO ELECTRONICO                                  |" << endl;
			cout << "|   7. TODOS LOS CAMPOS                                    |" << endl;
			cout << "|                                                          |" << endl;
			cout << "|   QUE CAMPO DESEA MODIFICAR:                             |" << endl;
			cout << "|__________________________________________________________|" << endl;
			cout << "|                                                          |" << endl;
			cout << "|                                                          |" << endl;
			cout << "|__________________________________________________________|" << endl;
			gotoxy(32,12); cin >> men;
			cin.ignore();

			if (men == 1) {

				gotoxy(4,15); cout << "NOMBRE: ";
				getline(cin, nombres);

				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.clientes SET nombres = '" + nombres + "' WHERE(idCliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 2) {

				gotoxy(4, 15); cout << " APELLIDOS:   ";
				getline(cin, apellidos);
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.clientes SET apellidos = '" + apellidos + "' WHERE(idCliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 3) {

				gotoxy(4, 15); cout << "    NIT:   ";
				cin >> nit;
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.clientes SET NIT = '" + nit + "' WHERE(idCliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 4) {

				gotoxy(4, 15); cout << "         GENERO:   ";
				cin >> genero;
				cin.ignore();

				string gen = to_string(genero);
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.clientes SET genero = " + gen + " WHERE(idCliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}
			else if (men == 5) {

				gotoxy(4, 15); cout << "       TELEFONO:   ";
				cin >> telefono;
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.clientes SET telefono = '" + telefono + "' WHERE(idCliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}
			else if (men == 6) {

			gotoxy(4, 15); cout << " CORREO ELECTRONICO:   "; 
				getline(cin, correo_electronico);
				string id = to_string(idcliente);
				string update = "UPDATE empresa_c.clientes SET correo_electronico = '" + correo_electronico + "' WHERE(idCliente = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 17); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}


			else if (men == 7) {
				cout << endl;
				system("cls");
				cout << " ____________________________________________________________ " << endl;
				cout << "|               **** INGRESAR NUEVO CLIENTE ****             |" << endl;
				cout << "|____________________________________________________________|" << endl;
				cout << "|                                                            |" << endl;
				cout << "|   NOMBRES:                                                 |" << endl;
				cout << "|   APELLIDOS:                                               |" << endl;
				cout << "|   NIT:                                                     |" << endl;
				cout << "|   GENERO:                                                  |" << endl;
				cout << "|   TELEFONO:                                                |" << endl;
				cout << "|   CORREO ELECTRONICO:									  |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|____________________________________________________________|" << endl;
				

				gotoxy(28, 4); getline(cin, nombres);
				gotoxy(28, 5); getline(cin, apellidos);
				gotoxy(28, 6); getline(cin, nit);
				gotoxy(28, 7); cin >> genero; cin.ignore();
				gotoxy(28, 8); getline(cin, telefono);
				gotoxy(28, 9); getline(cin, correo_electronico);

				string id = to_string(idcliente);
				string gen = to_string(genero);

				string update = "UPDATE empresa_c.clientes SET nombres = '" + nombres + "', apellidos = '" + apellidos + "', NIT = '" + nit + "', genero = " + gen + ", telefono = '" + telefono + "', correo_electronico = '" + correo_electronico + "' WHERE(idCliente = " + id + ")"; 
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 12); cout << "|                                                            |" << endl;
					cout << "|                *** MODIFICADO CON EXITO ***                |" << endl;
					cout << "|____________________________________________________________|" << endl;
				}
				else {
					gotoxy(0, 12); cout << "|                                                            |" << endl;
					cout << "|                 **** ERROR AL MODIFICAR ****               |" << endl;
					cout << "|____________________________________________________________|" << endl;
				}
			}
		}
		else {
		system("cls");
		cout << "                  ____________________________________________________________ " << endl;
		cout << "                 |                                                            |" << endl;
		cout << "                 |                ***** ERROR DE CONECCION *****              |" << endl;
		cout << "                 |____________________________________________________________|" << endl;
		}
		system("pause");
		cn.cerrar_coneccion();

	}

	void eliminar() {

		int q_estado, q_stado, con = 1, ic = 1;
		char d = 'z';
		string imm = to_string(ic);

		Conector cn = Conector();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_coneccion();
		string id = to_string(idcliente);

		if (cn.getConectar()) {
			
			string consulta = "SELECT * FROM empresa_c.clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)){

					imm = fila[0];
				istringstream(imm) >> con;
				

				if (idcliente == con) {
					gotoxy(64, 4); cout << " _____________________________________________________ " << endl;
					gotoxy(64, 5); cout << "|                   DATOS DE CLIENTES                 |" << endl;
					gotoxy(64, 6); cout << "|_____________________________________________________|" << endl;
					gotoxy(64, 7); cout << "|ID|     NOMBRES    |     APELLIDOS      |    NIT     |" << endl;
					gotoxy(64, 8); cout << "|__|________________|____________________|____________|" << endl;
					gotoxy(64, 9); cout << "|  |                |                    |            |" << endl;
					gotoxy(65, 9); cout << fila[0]; gotoxy(69, 9); cout << fila[1]; gotoxy(86, 9); cout << fila[2]; gotoxy(106, 9); cout << fila[3];
					gotoxy(64, 10); cout << "|__|________________|____________________|____________|" << endl; gotoxy(64, 12); cout << "|                                                    |" << endl;
					gotoxy(64, 11); cout << "|  SEGURO QUE DESEA ELIMINAR ESTE CLIENTE:            |" << endl;
					gotoxy(64, 12); cout << "|_____________________________________________________|" << endl;
					gotoxy(113, 11); cin >> d; cin.ignore();
				}
				}
			}

		if (d == 's' || d == 'S') {
			string delite = "DELETE FROM empresa_c.clientes WHERE idCliente = " + id + "";
			const char* i = delite.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				gotoxy(0, 15); cout << "|                                                           |" << endl;
				cout << "|              ***** ELIMINADO CON EXITO *****              |" << endl;
				cout << "|___________________________________________________________|" << endl;

			}
			else {
				gotoxy(0, 13); cout << "|                                                           |" << endl;
				cout << "|               ***** ERROR AL ELIMINAR *****               |" << endl;
				cout << "|___________________________________________________________|" << endl;
			}
		}
		else if (d == 'n' || d == 'N') {
			gotoxy(0, 15); cout << "|                                                           |" << endl;
			cout << "|              ***** CANCELADO CON EXITO *****              |" << endl;
			cout << "|___________________________________________________________|" << endl;
		}
		else {
			gotoxy(64, 4); cout << " ______________________________________________________ " << endl;
			gotoxy(64, 5); cout << "|                                                      |" << endl;
			gotoxy(64, 6); cout << "|           **** USUARIO NO ENCONTRADO ****            |" << endl;
			gotoxy(64, 7); cout << "|______________________________________________________|" << endl;
		}
	}
		else {
			system("cls");
			cout << "                  ____________________________________________________________ " << endl;
			cout << "                 |                                                            |" << endl;
			cout << "                 |                ***** ERROR DE CONECCION *****              |" << endl;
			cout << "                 |____________________________________________________________|" << endl;
		}
		cn.cerrar_coneccion();

	}
};
