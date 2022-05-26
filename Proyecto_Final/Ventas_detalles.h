#include<iostream>
#include<mysql.h>
#include<string>
#include<string.h>
#include<conio.h>
#include<sstream>
#include<Windows.h>
#include "Ventas.h"

class Venta_detalle
{
protected:	 int iddetalle = 0, idventa = 0, idproducto=0;
			 string cantidad;
			 float preciounitario = 0;

public:
	Venta_detalle() {}

	Venta_detalle(int idd, int idv, int idp, string can, float pu) {

		iddetalle = idd;
		idventa = idv;
		idproducto = idp;
		cantidad = can;
		preciounitario = pu;

	}

	void setIdDet(int idd) { iddetalle = idd; }
	void setIdVenta(int idv) { idventa = idv; }
	void setIdProd(int idp) { idproducto = idp; }
	void setCantidad(string can) { cantidad = can; }
	void setPrecioU(float pu) { preciounitario = pu; }

	int getIdDet() { return iddetalle; }
	int getIdVenta() { return idventa; }
	int getIdProd() { return idproducto; }
	string getCantidad() { return cantidad; }
	float getPrecioU() { return preciounitario; }

	void gotoxy(int x, int y) {
		HANDLE hCon;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);

		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hCon, dwPos);
	}



	void Cuadro(int x1, int y1, int x2, int y2) {
		int i;

		for (i = x1; i < x2; i++) {
			gotoxy(i, y1); cout << "\304"; //linea horizontal superior
			gotoxy(i, y2); cout << "\304"; //linea horizontal inferior
		}

		for (i = y1; i < y2; i++) {
			gotoxy(x1, i); cout << "\263"; //linea vertical izquierda
			gotoxy(x2, i); cout << "\263"; //linea vertical derecha
		}

		gotoxy(x1, y1); cout << "\332";
		gotoxy(x1, y2); cout << "\300";
		gotoxy(x2, y1); cout << "\277";
		gotoxy(x2, y2); cout << "\331";
	}





	void Actualizar_Vd() {

		int q_estado;
		int men = 0;
		Conector cn = Conector();

		cn.abrir_coneccion();
		string bus = to_string(idventa);

		if (cn.getConectar()) {
			system("cls");
			cout << " ________________________________________________________________________ " << endl;
			cout << "|                 ********** MENU ACTUALIZAR **********                  |" << endl;
			cout << "|________________________________________________________________________|" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|         1. ID VENTAS                                                   |" << endl;
			cout << "|         2. ID PRODUCTOS                                                |" << endl;
			cout << "|         3. CANTIDAD                                                    |" << endl;
			cout << "|         4. PRECIO UNITARIO                                             |" << endl;
			cout << "|         5. TODOS LOS CAMPOS                                            |" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|                  QUE CAMPO DESEA MODIFICAR:   _____                    |" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|________________________________________________________________________|" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|________________________________________________________________________|" << endl;
			gotoxy(50, 10); cin >> men;
			cin.ignore();

			if (men == 1) {

				gotoxy(04, 14); cout << "      INGRESE EL ID VENTA:  ";
				cin >> idventa;
				string idd = to_string(iddetalle);
				string idv = to_string(idventa);
				string update = "UPDATE empresa_c.ventas_detalle SET idVenta = " + idv + " WHERE(idVentas_detalle = " + idd + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(03, 16);  cout << "                        MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(03, 16);  cout << "                 **** ERROR DE CONECCION ****" << endl << endl;
				}
			}

			else if (men == 2) {

				gotoxy(04, 14); cout << "      INGRESE EL ID PRODUCTO:  ";
				cin >> idproducto;
				string idd = to_string(iddetalle);
				string idp = to_string(idproducto);
				string update = "UPDATE empresa_c.ventas_detalle SET idProducto = "+idp+" WHERE (idVentas_detalle = "+idd+")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(03, 16);  cout << "                        MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(03, 16);  cout << "                 **** ERROR DE CONECCION ****" << endl << endl;
				}
			}

			else if (men == 3) {

				gotoxy(03, 14); cout << "    INGRESAR CANTIDAD DE PRODUCTO:   ";
				getline(cin, cantidad);
				string idd = to_string(iddetalle);
				string update = "UPDATE empresa_c.ventas_detalle SET cantidad = '" + cantidad + "' WHERE(idVentas_detalle = " + idd + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(03, 16);  cout << "                       MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(03, 16);  cout << "              **** ERROR DE CONECCION ****" << endl << endl;
				}
			}

			else if (men == 4) {

				gotoxy(04, 14); cout << "      INGRESAR PRECIO UNITARIO:  ";
				cin >> preciounitario;
				string idd = to_string(iddetalle);
				string pu = to_string(preciounitario);
				string update = "UPDATE empresa_c.ventas_detalle SET precio_unitario = " + pu + " WHERE(idVentas_detalle = " + idd + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(03, 16);  cout << "                        MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(03, 16);  cout << "                 **** ERROR DE CONECCION ****" << endl << endl;
				}
			}


			else if (men ==	5) {
				system("cls");
				cout << " ______________________________________________________ " << endl;
				cout << "|              **** CAMPOS A MODIFICAR ****            |" << endl;
				cout << "|______________________________________________________|" << endl;
				cout << "|                                                      |" << endl;
				cout << "|   ID VENTA:                                          |" << endl;
				cout << "|   ID PRODUCTO:                                       |" << endl;
				cout << "|   CANTIDAD:                                          |" << endl;
				cout << "|   PRECIO UNITARIO:                                   |" << endl;
				cout << "|______________________________________________________|" << endl;
				cout << "|                                                      |" << endl;
				cout << "|                                                      |" << endl;
				cout << "|______________________________________________________|" << endl;
				gotoxy(28, 4); cin >> idventa;
				cin.ignore();
				gotoxy(28, 5); cin >> idproducto;
				cin.ignore();
				gotoxy(28, 6); getline(cin, cantidad);
				gotoxy(28, 7); cin >> preciounitario;
				cin.ignore();
				
				string idd = to_string(iddetalle);
				string idv = to_string(idventa);
				string idp = to_string(idproducto);
				string pu = to_string(preciounitario);

				string update = "UPDATE empresa_c.ventas_detalle SET idVenta = " + idv + ", idProducto = " + idp + ", cantidad = '" + cantidad + "', precio_unitario = " + pu + " WHERE(idVentas_detalle = " + idd + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(16, 10); cout << "MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(16, 10); cout << "ERROR DE CONECCION" << endl << endl;
				}
			}


		}
		else {
			system("cls");
			cout << endl << endl;
			cout << "                      ******** ERROR DE CONECCION ******** \n";
		}
		system("pause");
		cn.cerrar_coneccion();

	}

	void eliminar_Venta() {

		int q_estado, q_stado;
		char d = 'n';
		int c = 1; 

		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;
		cn.abrir_coneccion();

		string idd = to_string(iddetalle);
		if (cn.getConectar()) {

			string consultad = "SELECT * FROM empresa_c.ventas_detalle";
			const char* j = consultad.c_str();
			q_stado = mysql_query(cn.getConectar(), j);

			if (!q_stado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					if (iddetalle == c) {
						gotoxy(44, 4); cout << " ___________________________________________" << endl;
						gotoxy(44, 5); cout << "|   ****** DETALLES DE LAS VENTAS ******    |" << endl;
						gotoxy(44, 6); cout << "|___________________________________________|" << endl;
						gotoxy(44, 7); cout << "| ID  | ID  | ID  |          |   PRECIO     |" << endl;
						gotoxy(44, 7); cout << "| DET |VENTA|PRODU| CANTIDAD |  UNITARIO    |" << endl;
						gotoxy(44, 8); cout << "|_____|_____|_____|__________|______________|" << endl;
						gotoxy(44, 9); cout << "|     |     |     |          |              |" << endl;
						gotoxy(47, 9); cout << fila[0]; gotoxy(9, 9); cout << fila[1]; gotoxy(15, 9); cout << fila[2]; gotoxy(23, 9); cout << fila[3]; gotoxy(33, 9); cout << fila[4]; 
					}
					gotoxy(44, 10); cout << "|_____|_____|_____|__________|______________|" << endl;
					c++;
				}
			}


			gotoxy(44, 11);            cout << "|                                                                  |" << endl;
			gotoxy(44, 12);            cout << "|          SEGURO QUE DESE ELIMINAR ESTE REGISTRO (s/n):           |" << endl;
			gotoxy(44, 13);            cout << "|__________________________________________________________________|" << endl;
			gotoxy(102, 12);	cin >> d;

			if (d == 's' || d == 'S') {
				string delite = "DELETE FROM empresa_c.ventas_detalle WHERE idVentas_detalle = " + idd + "";
				const char* i = delite.c_str();
				q_estado = mysql_query(cn.getConectar(), i);

				if (!q_estado) {

					gotoxy(0, 14); cout << "|                                        |" << endl;
					cout << "|          ELIMINADO CON EXITO           |" << endl;
					cout << "|________________________________________|" << endl;


				}
				else {
					gotoxy(0, 14); cout << "|                                        |" << endl;
					cout << "|            ERROR AL ELIMINAR           |" << endl;
					cout << "|________________________________________|" << endl; 
				}
			}
			else {
				gotoxy(0, 14); cout << "|                                        |" << endl;
				cout << "|          CANCELADO CON EXITO           |" << endl;
				cout << "|________________________________________|" << endl; 
			}

		}
		else {
			gotoxy(0, 14); cout << "|                                        |" << endl;
			cout << "|           ERROR DE CONECCION           |" << endl;
			cout << "|________________________________________|" << endl; 
		}
		cn.cerrar_coneccion();


	}



};

