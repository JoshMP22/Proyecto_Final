#include<iostream>
#include<mysql.h>
#include<string>
#include<sstream>
#include"Ventas_detalles.h"

using namespace std;	

class empleado {

protected: string nit, nombre, apellido, telefono, dpi, genero, fecha_nacimiento, idPuesto, fecha_inicio_laborales, fechaingreso;

		 int buscador = 0, idEmpleado = 0;
		 int idEmpleado;


public:
	empleado() {}
	empleado(int ide, string nom, string ape, string dir, string tel, string d, string gen, string fn, string idp, string fil, string f, int bus) {

		idEmpleado = ide;
		buscador = bus;

	}

	void setIdEmpleado(int id) { idEmpleado = id; }
	void setNombre(string nom) { nombre = nom; }
	void setApellido(string ape) { apellido = ape; }
	void setTelefono(string tel) { telefono = tel; }
	void setDPI(string d) { dpi = d; }
	void setGenero(string gen) { genero = gen; }
	void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }
	void setidPuesto(int idp) { idPuesto = idp; }
	void setfecha_inicio_laborales(string fil) { fecha_inicio_laborales = fil; }
	void setidFechaingreso(int f) { fechaingreso = f; }


	int getId() { return idEmpleado; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getTelefono() { return telefono; }
	string getDPI() { return dpi; }
	string getGenero() { return genero; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	string getidPuesto(int idp) { return idPuesto; }
	string getfecha_incio_laborales() { return fecha_inicio_laborales; }
	string getFehcaingrso(int f) { return fechaingreso; }
	int getBuscar() { return buscador; }

	void crear() {

		int q_estado;
		Conector cn = Conector();

		cn.abrir_coneccion();

		if (cn.getConectar()) {

			//cambiar un entero a string
			string id = to_string(idEmpleado);

			string insert = "INSERT INTO empresa_c.empleados( nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_laborales, fechaingreso) VALUES('Prueba','mas','direccion','33443344','2322 23232 2322', 1, '2000-01-01', 2, '2017-02-02', '2016-12-15 09:53:01')";
			const char* i = insert.c_str();
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
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM empresa_c.empleados;";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "         ********* PRODUCTOS ******" << endl;
				cout << " IDEpleao   |  Nombre  |  Apelldo     | DIRECCION        |  TELEFONO     |  DPI     | Genero   | Fecha Nacimiento     | idPuesto      | Fecha Inicio Laborales  |   Fecha ingreso" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << " | " << fila[9] << " | " << fila[10] << endl;
				}
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

	void actualizar() {

		int q_estado;
		int men = 0;
		Conector cn = Conector();

		cn.abrir_coneccion();
		string bus = to_string(buscador);

		if (cn.getConectar()) {
			system("cls");
			cout << "   ********** MENU ACTUALIZAR ********** " << endl;
			cout << " 1. NOMBRE DEL Empleado" << endl;
			cout << " 2. APELLIDO DEL EMPLEADO" << endl;
			cout << " 3. TELEFONO DEL EMPLEADO" << endl;
			cout << " 4. GENERO DEL EMPLEADO" << endl;
			cout << " 5. MODIFICAR TODOS LOS CAMPOS" << endl;
			cout << " QUE CAMPO DESEA MODIFICAR:  ";
			cin >> men;
			cin.ignore();

			if (men == 1) {

				cout << endl << " INGRESE NOMBRE DEL Empleado:   ";
				getline(cin, nombre);

				string update = "UPDATE empresa_c.empleados SET nombres = '" + nombre + "' WHERE(idEmpleado = " + bus + ")";
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

				cout << endl << " INGRESE APELLIDO DEL TRABAJADOR:   ";
				getline(cin, apellido);
				string update = "UPDATE empresa_c.empleados SET apellidos = '" + apellido + "' WHERE (idEmpleado = " + bus + ");";
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

				cout << endl << " INGRESE LA DIRECCION DEL PROVEEDOR:   ";
				getline(cin, telefono);

				string update = "UPDATE empresa_c.empleados SET telefono = '" + telefono + "'  WHERE (`idEmpleado` = " + bus + ")";
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

				cout << endl << " INGRESE GENERO DEL TRABAJADOR:   ";
				getline(cin, genero);

				string update = "UPDATE empresa_c.empleados SET genero = '" + genero + "' WHERE (`idEmpleado` = " + bus + ")";
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
				cout << endl;

				cout << " INGRESE NOMBRE DEL EMPLEADO:                ";
				getline(cin, nombre);
				cout << "INGRESE APELLIDO DEL EMPLEADO:         ";
				getline(cin, apellido);
				cout << "INGRESE DIRECCION DEL EMPLEADO:   ";
				getline(cin, telefono);
				cout << "INGRESE GENERO DEL EMPLEADO:        ";
				getline(cin, genero);

				string update = "UPDATE empresa_c.empleados SET Nombre` = '" + nombre + "', `Apellido` = '" + apellido + "', `telefono` = '" + telefono + " ', `genero` = '" + genero + "' WHERE (`idEmpleado` = " + bus + ")";
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
		int c = 1, r = 0, im = 0;
		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;

		cn.abrir_coneccion();

		string id = to_string(idEmpleado);

		if (cn.getConectar()) {

			string delite = "DELETE FROM empresa_c.empleados WHERE idEmpleado = " + id + "";

			const char* i = delite.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				cout << "ELIMINADO CON EXITO .... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccion();


	}


};


