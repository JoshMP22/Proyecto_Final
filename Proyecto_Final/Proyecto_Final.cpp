#include <iostream>
#include <string>
#include <conio.h>
#include <string.h>
#include "Ventas_detalles.h" 
#include "Cliente.h"
#include "Compras_AIO.h"
#include <cstdlib>

using namespace std;

Compras_AIO obj_compras;

void gotoxy(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

int main()
{
	system("color B0");
	int menu = 0, men = 0;
	char m = 's';

	do {
		system("cls");
		cout << " ______________________________________ " << endl;
		cout << "|          ****** MENU ********        |" << endl;
		cout << "|______________________________________|" << endl;
		cout << "|                                      |" << endl;
		cout << "|    1. CLIENTES                       |" << endl;
		cout << "|    2. EMPLEADOS                      |" << endl;
		cout << "|    3. PUESTOS                        |" << endl;
		cout << "|    4. VENTAS                         |" << endl;
		cout << "|    5. PRODUCTOS                      |" << endl;
		cout << "|    6. MARCAS                         |" << endl;
		cout << "|    7. COMPRAS                        |" << endl;
		cout << "|    8. PROVEEDORES                    |" << endl;
		cout << "|    0. SALIR                          |" << endl;
		cout << "|                                      |" << endl;
		cout << "|  ELIGE UNA OPCION:                   |" << endl;
		cout << "|______________________________________|" << endl;
		gotoxy(23, 14); cin >> menu;

		if (menu == 1) {

			string nom, ap, n, tel, cor, fi;
			int idc = 0, gen = 0;


			do {
				system("cls");
				cout << "           MENU CLIENTES" << endl;
				cout << " 1. INGRESAR NUEVO CLIENTE" << endl;
				cout << " 2. VER CLIENTES" << endl;
				cout << " 3. MODIFICAR" << endl;
				cout << " 4. ELIMINAR" << endl;
				cout << " 0. SALIR" << endl;
				cin >> men;

				if (men == 1) {

					cout << endl;

					cout << " INGRESE NOMBRES:                ";
					getline(cin, nom);
					cout << " INGRESE APELLIDOS:         ";
					getline(cin, ap);
					cout << "INGRESE NIT:   ";
					getline(cin, n);
					cout << " INGRESE GENERO:   ";
					cin >> gen;
					cout << " INGRESE telefono:   ";
					getline(cin, tel);
					cout << "INGRESE CORREO ELECTRONICO:        ";
					getline(cin, cor);
					cout << "INGRESE FECHA DE INGRESO:        ";
					getline(cin, fi);

					//Cliente cl = Cliente(nom, ap, gen, tel,cor,fi, n);
					//cl.crear();


				}
				else if (men == 2) {
					//MENU DE LEER
				}
				else if (men == 3) {
					//MENU DE ACTUALIZAR
				}
				else if (men == 4) {
					//MENU DE ELIMINAR
				}
			} while (men != 0);
		}

		else if (menu == 4) {
			do {
				int gen = 0, idc = 0, ide = 0, id = 0, c = 0, idp = 0, nfac = 0, idv = 0;
				string n, nom, ap, dir, tel, cor, ser, fi, f, can;
				float pu = 0, pt = 0;

				system("cls");
				cout << " ________________________________________ " << endl;
				cout << "|         ****** MENU VENTAS *******     |" << endl;
				cout << "|________________________________________|" << endl;
				cout << "|                                        |" << endl;
				cout << "|   1. EFECTUAR UNA VENTA                |" << endl;
				cout << "|   2. LISTADO DE VENTAS                 |" << endl;
				cout << "|   3. ACTUALIZAR DATOS                  |" << endl;
				cout << "|   4. ELIMINAR REGISTROS                |" << endl;
				cout << "|   0. SALIR                             |" << endl;
				cout << "|                                        |" << endl;
				cout << "|  ELIGE UNA OPCION:                     |" << endl;
				cout << "|________________________________________|" << endl;
				cout << "|                                        |" << endl;
				cout << "|________________________________________|" << endl;
				gotoxy(23, 10); cin >> men;
				cin.ignore();

				if (men == 1) {
					system("cls");
					cout << " ____________________________________________________ " << endl;
					cout << "|               DATOS DE LA VENTA                    |" << endl;
					cout << "|____________________________________________________|" << endl;
					cout << "|  NIT( colocar sin guion ):                         |" << endl;
					cout << "|  NOMBRE:                                           |" << endl;
					cout << "|                                                    |" << endl;
					cout << "|                                                    |" << endl;
					cout << "|                                                    |" << endl;
					cout << "|____________________________________________________|" << endl;
					gotoxy(31, 3); getline(cin, n);

					Venta vn = Venta(idc, nom, ap, n, gen, tel, cor, fi, id, nfac, ser, f, ide, idp, can, pu, pt);
					vn.crear_Venta();

				}
				else if (men == 2) {
					Venta vn = Venta();
					vn.leer_Ventas();

				}
				else if (men == 3) {
					int de = 0;

					gotoxy(44, 4);  cout << " ___________________________________ ";
					gotoxy(44, 5);  cout << "|            ACTUALIZAR             |";
					gotoxy(44, 6);  cout << "|___________________________________|";
					gotoxy(44, 7);  cout << "|                                   |";
					gotoxy(44, 8);  cout << "|  1. DATOS DE LA VENTA             |";
					gotoxy(44, 9);  cout << "|  2. DATOS DE DETALLE DE LA VENTA  |";
					gotoxy(44, 10); cout << "|                                   |";
					gotoxy(44, 11); cout << "|  QUE DESEA ACUTALIZAR:            |";
					gotoxy(44, 12); cout << "|___________________________________|";
					gotoxy(70, 11); cin >> de;
					cin.ignore();

					gotoxy(3, 12); cout << "INGRESE EL ID PARA MODIFICAR:    ";
					cin >> id;

					if (de == 1) {
						Venta vn = Venta(id, nom, ap, n, gen, tel, cor, fi, idv, nfac, ser, f, ide, idp, can, pu, pt);
						vn.actualizar_Ventas();
					}
					else if (de == 2) {
						Venta_detalle vd = Venta_detalle(id, idv, idp, can, pu);
						vd.Actualizar_Vd();
					}
				}
				else if (men == 4) {

					gotoxy(3, 12); cout << "INGRESE EL ID A ELIMINAR:    ";
					cin >> id;

					Venta vn = Venta(id, nom, ap, n, gen, tel, cor, fi, id, nfac, ser, f, ide, idp, can, pu, pt);
					vn.eliminar_Venta();
					gotoxy(3, 17); system("pause");
				}
			} while (men != 0);
		}
		else if (menu == 7) {
		bool bol_state = false;
		do {
			system("cls");
			cout << "+--------------------------------------+" << endl;
			cout << "|        ****** COMPRAS ********       |" << endl;
			cout << "+--------------------------------------+" << endl;
			cout << "|    1. INGRESAR COMPRA                |" << endl;
			cout << "|    2. MOSTRAR COMPRAS                |" << endl;
			cout << "|    3. ACTUALIZAR COMPRA              |" << endl;
			cout << "|    4. ELIMINAR COMPRA                |" << endl;
			cout << "|    0. SALIR                          |" << endl;
			cout << "|                                      |" << endl;
			cout << "|  ELIGE UNA OPCION:                   |" << endl;
			cout << "+--------------------------------------+" << endl;
			gotoxy(23, 9); cin >> men;
			system("cls");
			if (men == 0) {
				bol_state = true;
			}
			else if (men == 1) {
				bool bol_stateo = true;
				char chr_state;
				int int_orden = 0, int_proveedor = 0, int_producto = 0, int_cantidad = 0, int_i = 1;
				int* intp_orden = &int_orden, * intp_proveedor = &int_proveedor, * intp_producto = &int_producto, * intp_cantidad = &int_cantidad;
				string str_feor;
				string* strp_feor = &str_feor;
				float flt_precio = 0;
				float* fltp_precio = &flt_precio;

				cout << "+--------------------------------------+" << endl;
				cout << "|    **** DATOS DE LA COMPRA *****     |" << endl;
				cout << "+--------------------------------------+" << endl;
				cout << "|    NO DE ORDEN:                      |" << endl;
				cout << "|    ID PROVEEDOR:                     |" << endl;
				cout << "|    FECHA DE ORDEN:                   |" << endl;
				cout << "+--------------------------------------+" << endl;
				gotoxy(18, 3); cin >> *intp_orden;
				gotoxy(19, 4); cin >> *intp_proveedor;
				gotoxy(21, 5); cin >> *strp_feor;
				int int_idcompra = obj_compras.Compras_AIO_max();
				obj_compras = Compras_AIO(NULL, *intp_orden, *intp_proveedor, *strp_feor, NULL, NULL, NULL);
				obj_compras.Compras_AIO_ingreso(1);
				do {
					system("cls");
					cout << "+--------------------------------------+" << endl;
					cout << "|     ** REGISTRO #" << int_i << " DE COMPRA ***     |" << endl;
					cout << "+--------------------------------------+" << endl;
					cout << "|    ID PRODUCTO:                      |" << endl;
					cout << "|    CANTIDAD:                         |" << endl;
					cout << "|    PRECIO UNITARIO:                  |" << endl;
					cout << "+--------------------------------------+" << endl;
					gotoxy(18, 3); cin >> *intp_producto;
					gotoxy(15, 4); cin >> *intp_cantidad;
					gotoxy(22, 5); cin >> *fltp_precio;
					obj_compras = Compras_AIO(int_idcompra, NULL, NULL, "*", *intp_producto, *intp_cantidad, *fltp_precio);
					obj_compras.Compras_AIO_ingreso(2);
					int_i++;
					cout << "\n\nDesea añadir una registro mas a la compra? s/n: ";
					cin >> chr_state;
					if (chr_state == 'n' || chr_state == 'N') {
						bol_stateo = false;
					}
				} while (bol_stateo == true);
				//delete [] intp_orden, delete [] intp_proveedor, delete [] intp_producto, delete [] intp_cantidad, delete [] strp_feor, delete [] fltp_precio;
			}
			else if (men == 2) {
				int int_opcion = 0, int_variable = 1;
				string str_id = "*";
				cout << "+--------------------------------------+" << endl;
				cout << "|      **** MOSTRAR COMPRAS ****       |" << endl;
				cout << "+--------------------------------------+" << endl;
				cout << "|    1. COMPRAS                        |" << endl;
				cout << "|    2. DETALLE DE COMPRAS             |" << endl;
				cout << "|    3. VER COMPRA Y DETALLE           |" << endl;
				cout << "|                                      |" << endl;
				cout << "|  ELIGE UNA OPCION:                   |" << endl;
				cout << "+--------------------------------------+" << endl;
				gotoxy(21, 7); cin >> int_opcion;
				if (int_opcion == 3) {
					int_variable = 2;
					int_opcion = 1;
					gotoxy(0, 9);
					cout << "|  ELIGE ID DE COMPRA:                 |" << endl;
					cout << "+--------------------------------------+" << endl;
					gotoxy(23, 9); cin >> str_id;
				}
				system("cls");
				obj_compras.Compras_AIO_mostrar(int_opcion, int_variable, str_id);
			}
			else if (men == 3) {
				cout << "Por favor ingresa la actualizacion de forma manual..." << endl;
				//(ID_a_actualizar, columna, nuevo_valor, tabla(1=Compras;2CompraDetalle=2)
				//obj_compras.Compras_AIO_actualizar("7", "cantidad", "5", 2);
			}
			else if (men == 4) {
				cout << "Por favor ingresa la eliminacion de forma manual..." << endl;
				//(TablaCompra, TablaCompraDetalle)
				//obj_compras.Compras_AIO_eliminar("2", 1);
			}
			else {
				gotoxy(0, 11);
				cout << "|  ELIGE UNA OPCION VALIDA             |" << endl;
				cout << "+--------------------------------------+" << endl;
			}

			menu = 0;
			gotoxy(0, 20);
			system("pause");
		} while (bol_state == false);
		}


	} while (menu != 0);

	return 0;
}
