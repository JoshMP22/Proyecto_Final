#include<iostream>
#include<mysql.h>
#include<string>
#include<sstream>
#include "Ventas_detalles.h"

using namespace std;

class producto {

protected: string nombre, descripcion, imagen, fechaingreso;
		 float precio_venta = 0, precio_costo = 0;
		 int  idproducto = 0, idmarca = 0, existencia = 0;

public:
	producto() {}
	producto(int idp, string prod, int idm, string desc, string ima, float pc, float pv, int exi, string fi) {

		idproducto = idp;
		nombre = prod;
		idmarca = idm;
		descripcion = desc;
		imagen = ima;
		precio_costo = pc;
		precio_venta = pv;
		existencia = exi;
		fechaingreso = fi;
	}

	void setIdProducto(int idp) { idproducto = idp; }
	void setProducto(string prod) { nombre = prod; }
	void setIdMarca(int idm) { idmarca = idm; }
	void setDescripcion(string desc) { descripcion = desc; }
	void setImagen(string ima) { imagen = ima; }
	void setPrecioC(float pc) { precio_costo = pc; }
	void setPrecioV(float pv) { precio_venta = pv; }
	void setExistencia(int exi) { existencia = exi; }
	void setidFechaingreso(int fi) { fechaingreso = fi; }

	int getIdProducto() { return idproducto; }
	string getNombre() { return nombre; }
	int getIdMarca() { return idmarca; }
	string getDescripcion() { return descripcion; }
	string getImagen() { return imagen; }
	float getPrecioC() { return precio_costo; }
	float getPrecioV() { return precio_venta; }
	int getExistencia() { return existencia; }
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

			string idp = to_string(idproducto);
			string idm = to_string(idmarca);
			string pc = to_string(precio_costo);
			string pv = to_string(precio_venta);
			string exi = to_string(existencia);

			string insertar = "INSERT INTO empresa_c.productos(producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso) VALUES('"+nombre+"',"+idm+",'"+descripcion+"', '"+imagen+"',"+pc+", "+pv+", "+exi+", current_time())";

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

			string consulta = "SELECT * FROM empresa_c.productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				system("cls");
				cout << " _______________________________________________________________________________________________ " << endl;
				cout << "|                            BASE DE DATOS DE PRODUCTOS                                         |" << endl;
				cout << "|_______________________________________________________________________________________________|" << endl;
				cout << "| ID |            PRODUCTO            |ID |  PRECIO  |   PRECIO  |EXISTEN|     FECHA INGRESO    |" << endl;
				cout << "|    |                                |MAR|  COSTO   |   VENTA   |       |                      |" << endl;
				cout << "|____|________________________________|___|__________|___________|_______|______________________|" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					                  
					gotoxy(0, 6 + i); cout << "|    |                                |   |          |           |       |                      |" << endl;
					gotoxy(2, 6 + i); cout << fila[0]; gotoxy(8, 6 + i); cout << fila[1]; gotoxy(40, 6 + i); cout << fila[2]; gotoxy(44, 6 + i); cout << fila[5]; 
					gotoxy(55, 6 + i); cout << fila[6];	gotoxy(67, 6 + i); cout << fila[7]; gotoxy(75, 6 + i); cout << fila[8]; 
					i++;
				}
				cout << "\n|____|________________________________|___|__________|___________|_______|______________________|" << endl;
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
			cout << "|                                                          |" << endl;
			cout << "|   1. NOMBRES DEL PRODUCTO                                |" << endl;
			cout << "|   2. ID MARCA                                            |" << endl;
			cout << "|   3. DESCRIPCION                                         |" << endl;
			cout << "|   4. IMAGEN                                              |" << endl;
			cout << "|   5. PRECIO COSTO                                        |" << endl;
			cout << "|   6. PRECIO VENTA                                        |" << endl;
			cout << "|   7. EXISTENCIA                                          |" << endl;
			cout << "|   8. TODOS LOS CAMPOS                                    |" << endl;
			cout << "|                                                          |" << endl;
			cout << "|                                                          |" << endl;
			cout << "|   QUE CAMPO DESEA MODIFICAR:                             |" << endl;
			cout << "|__________________________________________________________|" << endl;
			cout << "|                                                          |" << endl;
			cout << "|                                                          |" << endl;
			cout << "|__________________________________________________________|" << endl;
			gotoxy(32, 15); cin >> men;
			cin.ignore();

			if (men == 1) {

				gotoxy(4, 18); cout << "NOMBRE DEL PRODUCTO: ";
				getline(cin, nombre);

				string id = to_string(idproducto);
				string update = "UPDATE empresa_c.productos SET producto = '" + nombre + "' WHERE(idProducto = " + id + ")";
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

				gotoxy(4, 18); cout << " ID MARCA:   ";
				cin >> idmarca; cin.ignore();
				string id = to_string(idproducto);
				string idm = to_string(idmarca);
				string update = "UPDATE empresa_c.productos SET idMarca = " + idm + " WHERE(idProducto = " + id + ")";
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

				gotoxy(4, 18); cout << "    DESCRIPCION:   ";
				getline(cin, descripcion);
				string id = to_string(idproducto);
				string update = "UPDATE empresa_c.productos SET descripcion = '" + descripcion + "' WHERE(idProducto = " + id + ")";
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

				gotoxy(4, 18); cout << "      IMAGEN:   ";
				getline(cin, imagen);
				string id = to_string(idproducto);
				string update = "UPDATE empresa_c.productos SET imagen = '" + imagen + "' WHERE(idProducto = " + id + ")";
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

				gotoxy(4, 18); cout << "    PRECIO COSTO:   ";
				cin >> precio_costo; cin.ignore();
				string pc = to_string(precio_costo); 
				string id = to_string(idproducto);
				string update = "UPDATE empresa_c.productos SET precio_costo = " + pc + " WHERE(idProducto = " + id + ")";
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

			gotoxy(4, 18); cout << "    PRECIO DE VENTA:   ";
			cin >> precio_venta; cin.ignore();
			string pv = to_string(precio_venta);
			string id = to_string(idproducto);
			string update = "UPDATE empresa_c.productos SET precio_venta = " + pv + " WHERE(idProducto = " + id + ")";
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

			gotoxy(4, 18); cout << "    CANTIDAD EN EXISTENCIA:   ";
			cin >> existencia; cin.ignore();
			string exi = to_string(existencia);
			string id = to_string(idproducto);
			string update = "UPDATE empresa_c.productos SET existencia = " + exi + " WHERE(idProducto = " + id + ")";
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
				cout << endl;
				system("cls");
				cout << " ____________________________________________________________ " << endl;
				cout << "|                 **** MODIFICAR PRODUCTO ****               |" << endl;
				cout << "|____________________________________________________________|" << endl;
				cout << "|                                                            |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|   NOMBRES DEL PRODUCTO:                                    |" << endl;
				cout << "|   ID DE LA MARCA:                                          |" << endl;
				cout << "|   DESCRIPCION:                                             |" << endl;
				cout << "|   IMAGEN:                                                  |" << endl;
				cout << "|   PRECIO COSTO:                                            |" << endl;
				cout << "|   PRECIO VENTA:                                            |" << endl;
				cout << "|   EXISTENCIA:                                              |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|____________________________________________________________|" << endl;

				
				gotoxy(28, 5); getline(cin, nombre);
				gotoxy(28, 6); cin >> idmarca; cin.ignore();
				gotoxy(28, 7); getline(cin, descripcion);
				gotoxy(28, 8); getline(cin, imagen);
				gotoxy(28, 9); cin >> precio_costo; cin.ignore();
				gotoxy(28, 10); cin >> precio_venta; cin.ignore();
				gotoxy(28, 11); cin >> existencia; cin.ignore();

				string id = to_string(idproducto);
				string idm = to_string(idmarca);
				string pc = to_string(precio_costo);
				string pv = to_string(precio_venta);
				string exi = to_string(existencia);

				string update = "UPDATE empresa_c.productos SET producto = '" + nombre + "', idMarca= " + idm + ", descripcion= '"+descripcion+"', imagen='"+imagen+"', precio_costo=" + pc + ", precio_venta=" + pv + ", existencia= " + exi + " WHERE( idProducto= " + id + ")";
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
		string id = to_string(idproducto);

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM empresa_c.productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {

					imm = fila[0];
					istringstream(imm) >> con;


					if (idproducto == con) {
						gotoxy(63, 4); cout << " _______________________________________________________" << endl;
						gotoxy(63, 5); cout << "|                  DATOS DE EMPLEADO                    |" << endl;
						gotoxy(63, 6); cout << "|_______________________________________________________|" << endl;
						gotoxy(63, 7); cout << "|ID|      NOMBRE DEL PRODUCTO   |EXI|  FECHA INGRESO    |" << endl;
						gotoxy(63, 8); cout << "|__|____________________________|___|___________________|" << endl;
						gotoxy(63, 9); cout << "|  |                            |   |                   |" << endl;
						gotoxy(64, 9); cout << fila[0]; gotoxy(68, 9); cout << fila[1]; gotoxy(97, 9); cout << fila[7]; gotoxy(100, 9); cout << fila[8];
						gotoxy(63, 10); cout << "|__|____________________________|___|___________________|" << endl;
						gotoxy(63, 12); cout << "|                                                       |" << endl;
						gotoxy(63, 11); cout << "|  SEGURO QUE DESEA ELIMINAR ESTE CLIENTE:              |" << endl;
						gotoxy(63, 12); cout << "|_______________________________________________________|" << endl;
						gotoxy(112, 11); cin >> d; cin.ignore();
					}
				}
			}

			if (d == 's' || d == 'S') {
				string delite = "DELETE FROM empresa_c.productos WHERE idProducto = " + id + "";
				const char* i = delite.c_str();
				q_estado = mysql_query(cn.getConectar(), i);

				if (!q_estado) {

					gotoxy(0, 15); cout << "|                                                           |" << endl;
					               cout << "|          ***** ELIMINADO CON EXITO *****                  |" << endl;
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
