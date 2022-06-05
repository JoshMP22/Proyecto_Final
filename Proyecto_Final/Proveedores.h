#include<iostream>
#include<mysql.h>
#include<string>
#include<sstream>
#include "Compras_AIO.h"

using namespace std;

class proveedor {

protected: string provee, nit, direccion, telefono;

		 int  idproveedor = 0;



public:
	proveedor() {}
	proveedor(int idp, string prov, string n, string dir, string tel) {

		idproveedor = idp;
		provee = prov;
		nit = n;
		direccion = dir;
		telefono = tel;

	}

	void setIdProveedor(int idp) { idproveedor = idp; }
	void setProveedor(string prov) { provee = prov; }
	void setNIT(string n) { nit = n; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(string tel) { telefono = tel; }

	int getIdProveedor() { return idproveedor; }
	string getProveedor() { return provee; }
	string getNit() { return nit; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }


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

			string idp = to_string(idproveedor);
			string insertar = "INSERT INTO empresa_c.proveedores( proveedor, nit, direccion, telefono) VALUES('" + provee + "','" + nit + "','" + direccion + "','" + telefono + "')";

			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				gotoxy(0, 11); cout << "|                **** INGRESADO CON EXITO ****               |" << endl;
								   cout << "|____________________________________________________________|" << endl;

			}
			else {
				gotoxy(0, 11); cout << "|                ***** ERROR AL INGRESAR *****               |" << endl;
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
		int q_estado, i = 0;
		Conector cn = Conector();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM empresa_c.proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				system("cls");
				cout << " ___________________________________________________________________________________________________ " << endl;
				cout << "|                                              BASE DE DATOS DE PROVEEDORES                         |" << endl;
				cout << "|___________________________________________________________________________________________________|" << endl;
				cout << "|ID|           PROVEEDOR          |      NIT      |           DIRECCION           |     TELEFONO    |" << endl;
				cout << "|__|______________________________|_______________|_______________________________|_________________|" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(0, 5 + i); cout << "|  |                              |               |                               |                 |" << endl;
					gotoxy(1, 5 + i); cout << fila[0]; gotoxy(5, 5 + i); cout << fila[1]; gotoxy(36, 5 + i); cout << fila[2]; gotoxy(53, 5 + i); cout << fila[3]; gotoxy(84, 5 + i); cout << fila[4];
					i++;
				}
				cout << "\n|__|______________________________|_______________|_______________________________|_________________|" << endl;
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

		if (cn.getConectar()) {
			system("cls");
			cout << " __________________________________________________________ " << endl;
			cout << "|           ********** MENU ACTUALIZAR **********          |" << endl;
			cout << "|__________________________________________________________|" << endl;
			cout << "|                                                          |" << endl;
			cout << "|   1. NOMBRE DEL PROVEEDOR                                |" << endl;
			cout << "|   2. NIT                                                 |" << endl;
			cout << "|   3. DIRECCION                                           |" << endl;
			cout << "|   4. NUMERO DE TELEFONO                                  |" << endl;
			cout << "|   5. TODOS LOS CAMPOS                                    |" << endl;
			cout << "|                                                          |" << endl;
			cout << "|   QUE CAMPO DESEA MODIFICAR:                             |" << endl;
			cout << "|__________________________________________________________|" << endl;
			cout << "|                                                          |" << endl;
			cout << "|                                                          |" << endl;
			cout << "|__________________________________________________________|" << endl;
			gotoxy(32, 10); cin >> men;
			cin.ignore();

			if (men == 1) {

				gotoxy(4, 13); cout << "NOMBRE DEL PROVEEDOR: ";
				getline(cin, provee);

				string id = to_string(idproveedor); 
				string update = "UPDATE empresa_c.proveedores SET proveedor = '" + provee + "' WHERE(idProveedor = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 15); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 15); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 2) {

				gotoxy(4, 13); cout << "NOMBRE DEL NIT: ";
				getline(cin, nit);

				string id = to_string(idproveedor);
				string update = "UPDATE empresa_c.proveedores SET nit = '" + nit + "' WHERE(idProveedor = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 15); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 15); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 3) {

				gotoxy(4, 13); cout << "    DIRECCION:   ";
				getline(cin, direccion);
				string id = to_string(idproveedor);
				string update = "UPDATE empresa_c.proveedores SET direccion = '" + direccion + "' WHERE(idProveedor = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 15); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 15); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 4) {

				gotoxy(4, 13); cout << "       TELEFONO:   ";
				getline(cin, telefono);
				string id = to_string(idproveedor);
				string update = "UPDATE empresa_c.proveedores SET telefono = '" + telefono + "' WHERE(idProveedor = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 15); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 15); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}


			else if (men == 5) {
				cout << endl;
				system("cls");
				cout << " ____________________________________________________________ " << endl;
				cout << "|                 **** MODIFICAR EMPLEADO ****               |" << endl;
				cout << "|____________________________________________________________|" << endl;
				cout << "|                                                            |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|   NOMBRES DEL PROVEEDOR:                                   |" << endl;
				cout << "|   NIT:                                                     |" << endl;
				cout << "|   DIRECCION:                                               |" << endl;
				cout << "|   TELEFONO:                                                |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|____________________________________________________________|" << endl;

				gotoxy(28, 5); getline(cin, provee);
				gotoxy(28, 6); getline(cin, nit);
				gotoxy(28, 7); getline(cin, direccion);
				gotoxy(28, 8); getline(cin, telefono);

				string id = to_string(idproveedor);
				
				string update = "UPDATE empresa_c.proveedores SET proveedor = '" + provee + "', nit = '" + nit + "', direccion = '" + direccion + "', telefono = '" + telefono + "' WHERE (idProveedor = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 11); cout << "|                                                            |" << endl;
					cout << "|                *** MODIFICADO CON EXITO ***                |" << endl;
					cout << "|____________________________________________________________|" << endl;
				}
				else {
					gotoxy(0, 11); cout << "|                                                            |" << endl;
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
		string id = to_string(idproveedor);

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM empresa_c.proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					imm = fila[0];
					istringstream(imm) >> con;


					if (idproveedor == con) {
						gotoxy(64, 4); cout << " __________________________________________________ " << endl;
						gotoxy(64, 5); cout << "|                 DATOS DE EMPLEADO                |" << endl;
						gotoxy(64, 6); cout << "|__________________________________________________|" << endl;
						gotoxy(64, 7); cout << "|ID|     PROVEEDOR   |    NIT   | DIRECCION        |" << endl;
						gotoxy(64, 8); cout << "|__|_________________|__________|__________________|" << endl;
						gotoxy(64, 9); cout << "|  |                 |          |                  |" << endl;
						gotoxy(65, 9); cout << fila[0]; gotoxy(69, 9); cout << fila[1]; gotoxy(87, 9); cout << fila[2]; gotoxy(98, 9); cout << fila[3]; 
						gotoxy(64, 10); cout << "|__|_________________|__________|__________________|" << endl;
						gotoxy(64, 12); cout << "|                                                  |" << endl;
						gotoxy(64, 11); cout << "|  SEGURO QUE DESEA ELIMINAR ESTE PROVEEDOR:       |" << endl;
						gotoxy(64, 12); cout << "|__________________________________________________|" << endl;
						gotoxy(110, 11); cin >> d; cin.ignore();
					}
				}
			}

			if (d == 's' || d == 'S') {
				string delite = "DELETE FROM empresa_c.proveedores WHERE idProveedor = " + id + "";
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
