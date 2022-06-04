#include <mysql.h>
#include <iostream>
#include <string>
#include "Trabajador.h"

using namespace  std;

class puesto {

private: string puestos;
	   int idpuesto = 0;

public:
	puesto() {}
	puesto(int idp, string p) {

		idpuesto = idp;
		puestos = p;
	}

	void setIDPuesto(int idp) { idpuesto = idp; }
	void setPuesto(string p) { puestos = p; }

	int getIDPuesto() { return idpuesto; }
	string getPuesto() { return puestos; }

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
			string  insertar = "INSERT INTO empresa_c.puestos(puesto) VALUES ('" + puestos + "')";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				gotoxy(0, 7); cout << "|                **** INGRESADO CON EXITO ****               |" << endl;
				cout << "|____________________________________________________________|" << endl;

			}
			else {
				gotoxy(0, 7); cout << "|                ***** ERROR AL INGRESAR *****               |" << endl;
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

			string consulta = "SELECT * FROM empresa_c.puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				system("cls");
				cout << " __________________________________ " << endl;
				cout << "|    BASE DE DATOS PUESTOS         |" << endl;
				cout << "|__________________________________|" << endl;
				cout << "|   ID    |         PUESTOS        |" << endl;
				cout << "|_________|________________________|" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(0, 5 + i); cout << "|         |                        |" << endl;
					gotoxy(5, 5 + i); cout << fila[0]; gotoxy(15, 5 + i); cout << fila[1]; 
					i++;
				}
				cout << "\n|_________|________________________|" << endl;
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
			cout << " ____________________________________________________________ " << endl;
			cout << "|                  **** ACTUALIZAR PUESTO ****               |" << endl;
			cout << "|____________________________________________________________|" << endl;
			cout << "|                                                            |" << endl;
			cout << "|   NOMBRE DEL PUESTO:                                       |" << endl;
			cout << "|                                                            |" << endl;
			cout << "|____________________________________________________________|" << endl;

			gotoxy(28, 4); getline(cin, puestos);

			string id = to_string(idpuesto);

			string update = "UPDATE empresa_c.puestos SET puesto = '" + puestos + "' WHERE(idPuesto = " + id + ")";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				gotoxy(0, 7); cout << "|               **** ACTUALIZADO CON EXITO ****              |" << endl;
				cout << "|____________________________________________________________|" << endl;

			}
			else {
				gotoxy(0, 7); cout << "|               ***** ERROR AL ACTUALIZAR *****              |" << endl;
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

	void eliminar() {

		int q_estado, q_stado, con = 1;
		char d = 'z';
		string imm = to_string(con);

		Conector cn = Conector();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_coneccion();
		string id = to_string(idpuesto);

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM empresa_c.puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					imm = fila[0];
					istringstream(imm) >> con;
					
					if (idpuesto == con) {
						
						gotoxy(64, 4); cout << " __________________________________ " << endl;
						gotoxy(64, 5); cout << "|    BASE DE DATOS PUESTOS         |" << endl;
						gotoxy(64, 6); cout << "|__________________________________|" << endl;
						gotoxy(64, 7); cout << "|   ID    |         PUESTOS        |" << endl;
						gotoxy(64, 8); cout << "|_________|________________________|" << endl;
						gotoxy(64, 9); cout << "|         |                        |" << endl;
						gotoxy(69, 9); cout << fila[0]; gotoxy(79, 9); cout << fila[1]; 
						gotoxy(64, 10); cout << "|_________|________________________|" << endl;
						gotoxy(64, 11); cout << "|                                  |" << endl;
						gotoxy(64, 12); cout << "| DESEA ELIMINAR(s/n):             |" << endl;
						gotoxy(64, 13); cout << "|__________________________________|" << endl;
						gotoxy(92, 12); cin >> d; cin.ignore();
					}
				}
			}

			if (d == 's' || d == 'S') {
				string delite = "DELETE FROM empresa_c.puestos WHERE idPuesto = " + id + "";
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

