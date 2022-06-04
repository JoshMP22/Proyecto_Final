#include<iostream>
#include<mysql.h>
#include<string>
#include<sstream>
#include "Cliente.h"

using namespace std;	

class empleado {

protected: string nit, nombre, apellido, direccion, telefono, dpi,  fecha_nacimiento, fecha_inicio_laborales, fechaingreso;

		 int  idempleado = 0, genero=0, idpuesto=0;
		 


public:
	empleado() {}
	empleado(int ide, string nom, string ape, string dir, string tel, string d, int gen, string fn, int idp, string fil, string fi) {

		idempleado = ide;
		nombre = nom;
		apellido = ape;
		direccion = dir;
		telefono = tel;
		dpi = d;
		genero = gen;
		fecha_nacimiento = fn;
		idpuesto = idp;
		fecha_inicio_laborales = fil;
		fechaingreso = fi;

	}

	void setIdEmpleado(int ide) { idempleado = ide; }
	void setNombre(string nom) { nombre = nom; }
	void setApellido(string ape) { apellido = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(string tel) { telefono = tel; }
	void setDPI(string d) { dpi = d; }
	void setGenero(int gen) { genero = gen; }
	void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }
	void setidPuesto(int idp) { idpuesto = idp; }
	void setfecha_inicio_laborales(string fil) { fecha_inicio_laborales = fil; }
	void setidFechaingreso(int fi) { fechaingreso = fi; }

	int getId() { return idempleado; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }
	string getDPI() { return dpi; }
	int getGenero() { return genero; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	int getidPuesto() { return idpuesto; }
	string getfecha_incio_laborales() { return fecha_inicio_laborales; }
	string getFehcaingrso() { return fechaingreso; }
	

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
			string idp = to_string(idpuesto);
			string insertar = "INSERT INTO empresa_c.empleados( nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_laborales, fechaingreso) VALUES('"+nombre+"','"+apellido+"','"+direccion+"','"+telefono+"','"+dpi+"', "+gen+", '"+fecha_nacimiento+"', "+idp+", '"+fecha_inicio_laborales+"', current_time())";

			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				gotoxy(0, 15); cout << "|                **** INGRESADO CON EXITO ****               |" << endl;
				cout << "|____________________________________________________________|" << endl;

			}
			else {
				gotoxy(0, 15); cout << "|                ***** ERROR AL INGRESAR *****               |" << endl;
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

			string consulta = "SELECT * FROM empresa_c.empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				system("cls");
				cout << " ______________________________________________________________________________________________________________________ " << endl;
				cout << "|                                              BASE DE DATOS DE EMPLEADOS                                              |" << endl;
				cout << "|______________________________________________________________________________________________________________________|" << endl;
				cout << "|ID|     APELLIDOS       |        DIRECCION       | TELEFONO |      DPI        |GEN|  FECHA DE  |ID |   FECHA INICIO   |" << endl;
				cout << "|  |                     |                        |          |                 |   | NACIMIENTO |PUE|     LABORES      |" << endl;
				cout << "|__|_____________________|________________________|__________|_________________|___|____________|___|__________________|" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(0, 6 + i); cout << "|  |                     |                        |          |                 |   |            |   |                  |" << endl;
					gotoxy(1, 6 + i); cout << fila[0]; gotoxy(5, 6 + i); cout << fila[2]; gotoxy(27, 6 + i); cout << fila[3]; gotoxy(52, 6 + i); cout << fila[4]; gotoxy(63, 6 + i); cout << fila[5];
					gotoxy(81, 6 + i); cout << fila[6]; gotoxy(85, 6 + i); cout << fila[7]; gotoxy(98, 6 + i); cout << fila[8]; gotoxy(102, 6 + i); cout << fila[9];
					i++;
				}
				cout << "\n|__|_____________________|________________________|__________|_________________|___|____________|___|__________________|" << endl;
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
			cout << "|   1. NOMBRES                                             |" << endl;
			cout << "|   2. APELLIDOS                                           |" << endl;
			cout << "|   3. DIRECCION                                           |" << endl;
			cout << "|   4. NUMERO DE TELEFONO                                  |" << endl;
			cout << "|   5. DPI                                                 |" << endl;
			cout << "|   6. GENERO                                              |" << endl;
			cout << "|   7. FECHA DE NACIMIENTO                                 |" << endl;
			cout << "|   8. ID DEL PUESTO                                       |" << endl;
			cout << "|   9. FECHA DE INICIO LABORALES                           |" << endl;
			cout << "|  10. TODOS LOS CAMPOS                                    |" << endl;
			cout << "|                                                          |" << endl;
			cout << "|   QUE CAMPO DESEA MODIFICAR:                             |" << endl;
			cout << "|__________________________________________________________|" << endl;
			cout << "|                                                          |" << endl;
			cout << "|                                                          |" << endl;
			cout << "|__________________________________________________________|" << endl;
			gotoxy(32, 15); cin >> men;
			cin.ignore();

			if (men == 1) {

				gotoxy(4, 18); cout << "NOMBRE: ";
				getline(cin, nombre);

				string id = to_string(idempleado);
				string update = "UPDATE empresa_c.empleados SET nombres = '" + nombre + "' WHERE(idEmpleado = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 2) {

				gotoxy(4, 18); cout << " APELLIDOS:   ";
				getline(cin, apellido);
				string id = to_string(idempleado);
				string update = "UPDATE empresa_c.empleados SET apellidos = '" + apellido + "' WHERE(idEmpleado = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 3) {

				gotoxy(4, 18); cout << "    DIRECCION:   ";
				getline(cin, direccion);
				string id = to_string(idempleado);
				string update = "UPDATE empresa_c.empleados SET direccion = '" + direccion + "' WHERE(idEmpleado = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 4) {

				gotoxy(4, 18); cout << "       TELEFONO:   ";
				getline(cin, telefono);
				string id = to_string(idempleado);
				string update = "UPDATE empresa_c.empleados SET telefono = '" + telefono + "' WHERE(idEmpleado = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 5) {

				gotoxy(4, 18); cout << "       DPI:   ";
				getline(cin, dpi);
				string id = to_string(idempleado);
				string update = "UPDATE empresa_c.empleados SET DPI = '" + dpi + "' WHERE(idEmpleado = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}

			else if (men == 6) {

				gotoxy(4, 18); cout << "         GENERO:   ";
				cin >> genero;	cin.ignore();

				string gen = to_string(genero);
				string id = to_string(idempleado);
				string update = "UPDATE empresa_c.empleados SET genero = " + gen + " WHERE(idEmpleado = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
				else {

					gotoxy(0, 20); cout << "|                                                          |" << endl;
					cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
					cout << "|__________________________________________________________|" << endl;
				}
			}
			
			else if (men == 7) {

			gotoxy(4, 18); cout << "    FECHA DE NACIMIENTO:   ";
			cin >> fecha_nacimiento;
			string id = to_string(idempleado);
			string update = "UPDATE empresa_c.empleados SET fecha_nacimiento = '" + fecha_nacimiento + "' WHERE(idEmpleado = " + id + ")";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				gotoxy(0, 20); cout << "|                                                          |" << endl;
				cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
				cout << "|__________________________________________________________|" << endl;
			}
			else {

				gotoxy(0, 20); cout << "|                                                          |" << endl;
				cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
				cout << "|__________________________________________________________|" << endl;
			}
			}

			else if (men == 8) {

			gotoxy(4, 18); cout << "         ID DEL PUESTO:   ";
			cin >> idpuesto;	cin.ignore();

			string idp = to_string(idpuesto);
			string id = to_string(idempleado);
			string update = "UPDATE empresa_c.empleados SET idPuesto = " + idp + " WHERE(idEmpleado = " + id + ")";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				gotoxy(0, 20); cout << "|                                                          |" << endl;
				cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
				cout << "|__________________________________________________________|" << endl;
			}
			else {

				gotoxy(0, 20); cout << "|                                                          |" << endl;
				cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
				cout << "|__________________________________________________________|" << endl;
			}
			}

			else if (men == 9) {

			gotoxy(4, 18); cout << "    FECHA DE INICIO DE LABORES:   ";
			cin >> fecha_inicio_laborales;
			string id = to_string(idempleado);
			string update = "UPDATE empresa_c.empleados SET fecha_inicio_laborales = '" + fecha_inicio_laborales + "' WHERE(idEmpleado = " + id + ")";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				gotoxy(0, 20); cout << "|                                                          |" << endl;
				cout << "|               *** MODIFICADO CON EXITO ***               |" << endl;
				cout << "|__________________________________________________________|" << endl;
			}
			else {

				gotoxy(0, 20); cout << "|                                                          |" << endl;
				cout << "|                **** ERROR AL MODIFICAR ****              |" << endl;
				cout << "|__________________________________________________________|" << endl;
			}
			}


			else if (men == 10) {
				cout << endl;
				system("cls");
				cout << " ____________________________________________________________ " << endl;
				cout << "|                 **** MODIFICAR EMPLEADO ****               |" << endl;
				cout << "|____________________________________________________________|" << endl;
				cout << "|                                                            |" << endl;
				cout << "|   NOMBRES:                                                 |" << endl;
				cout << "|   APELLIDOS:                                               |" << endl;
				cout << "|   DIRECCION:                                               |" << endl;
				cout << "|   NUMERO DE TELEFONO:                                      |" << endl;
				cout << "|   DPI:                                                     |" << endl;
				cout << "|   GENERO:                                                  |" << endl;
				cout << "|   FECHA DE NACIMIENTO:                                     |" << endl;
				cout << "|   ID DEL PUESTO:                                           |" << endl;
				cout << "|   FECHA DE INICIO LABORALES:                               |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|____________________________________________________________|" << endl;

				gotoxy(28, 4); getline(cin, nombre);
				gotoxy(28, 5); getline(cin, apellido);
				gotoxy(28, 6); getline(cin, direccion);
				gotoxy(28, 7); getline(cin, telefono);
				gotoxy(28, 8); getline(cin, dpi);
				gotoxy(28, 9); cin >> genero; cin.ignore();
				gotoxy(28, 10); getline(cin, fecha_nacimiento);
				gotoxy(28, 11); cin >> idpuesto; cin.ignore();
				gotoxy(28, 12); getline(cin, fecha_inicio_laborales);

				string id = to_string(idempleado);
				string gen = to_string(genero);
				string idp = to_string(idpuesto);

				string update = "UPDATE empresa_c.empleados SET nombres = '"+nombre+"', apellidos = '"+apellido+"', direccion = '"+direccion+"', telefono = '"+telefono+"', DPI = '"+dpi+"', genero = "+gen+", fecha_nacimiento = '"+fecha_nacimiento+"', idPuesto = "+idp+", fecha_inicio_laborales = '"+fecha_inicio_laborales+"' WHERE (idEmpleado = "+id+")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(0, 15); cout << "|                                                            |" << endl;
					cout << "|                *** MODIFICADO CON EXITO ***                |" << endl;
					cout << "|____________________________________________________________|" << endl;
				}
				else {
					gotoxy(0, 15); cout << "|                                                            |" << endl;
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
		string id = to_string(idempleado);

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM empresa_c.empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					imm = fila[0];
					istringstream(imm) >> con;


					if (idempleado == con) {
						gotoxy(64, 4); cout << " ______________________________________________________ " << endl;
						gotoxy(64, 5); cout << "|                   DATOS DE EMPLEADO                  |" << endl;
						gotoxy(64, 6); cout << "|______________________________________________________|" << endl;
						gotoxy(64, 7); cout << "|ID|      NOMBRES    |     APELLIDOS     | FECHA I.LAB |" << endl;
						gotoxy(64, 8); cout << "|__|_________________|___________________|_____________|" << endl;
						gotoxy(64, 9); cout << "|  |                 |                   |             |" << endl;
						gotoxy(65, 9); cout << fila[0]; gotoxy(69, 9); cout << fila[1]; gotoxy(87, 9); cout << fila[2]; gotoxy(107, 9); cout << fila[9];
						gotoxy(64, 10); cout << "|__|_________________|___________________|_____________|" << endl; gotoxy(64, 12); cout << "|                                                    |" << endl;
						gotoxy(64, 11); cout << "|  SEGURO QUE DESEA ELIMINAR ESTE EMPLEADO:            |" << endl;
						gotoxy(64, 12); cout << "|______________________________________________________|" << endl;
						gotoxy(113, 11); cin >> d; cin.ignore();
					}
				}
			}

			if (d == 's' || d == 'S') {
				string delite = "DELETE FROM empresa_c.empleados WHERE idEmpleado = " + id + "";
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

