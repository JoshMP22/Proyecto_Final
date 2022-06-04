#include <iostream>
#include <string>
#include <conio.h>
#include <string.h>
#include <Windows.h> 
#include "Proveedores.h"
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
			int idc = 0, gen=0;


			do {
				system("cls");
       				cout << " ___________________________________________________________ " << endl;
        			cout << "|           ********** MENU CLIENTES *********              |" << endl;
        			cout << "|___________________________________________________________|" << endl;
					cout << "|                                                           |" << endl;
					cout << "|     1. INGRESAR NUEVO CLIENTE                             |" << endl;
					cout << "|     2. VER CLIENTES                                       |" << endl;
					cout << "|     3. MODIFICAR CLIENTE                                  |" << endl;
					cout << "|     4. ELIMINAR CLIENTE                                   |" << endl;
					cout << "|     0. SALIR                                              |" << endl;
					cout << "|                                                           |" << endl;
					cout << "|  ELIGE UNA OPCION:                                        |" << endl;
					cout << "|___________________________________________________________|" << endl;
					cout << "|                                                           |" << endl;
					cout << "|                                                           |" << endl;
					cout << "|___________________________________________________________|" << endl;
					gotoxy(22,10); cin >> men;
					cin.ignore();
					
				if (men == 1) {

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
					cout << "|   CORREO ELECTRONICO:                                      |" << endl;
					cout << "|                                                            |" << endl;
					cout << "|____________________________________________________________|" << endl;
					
					gotoxy(28, 4); getline(cin, nom);
					gotoxy(28, 5); getline(cin, ap);
					gotoxy(28, 6); getline(cin, n);
					gotoxy(28, 7); cin >> gen; cin.ignore();
					gotoxy(28, 8); getline(cin, tel);
					gotoxy(28, 9); getline(cin, cor);	

					Cliente cl = Cliente(idc, nom, ap, gen, tel,cor,fi, n);
					cl.crear();
					system("pause");
				}
				else if (men == 2) {
					system("cls");
            			Cliente cl = Cliente();
            			cl.leer();

						system("pause");
				}
				else if (men == 3) {
				char b = 's';
				int xc=3, yc=13;
                do {
				gotoxy(xc, yc); cout << "INGRESE EL ID DEL CLIENTE QUE DESEA ACTUALIZAR:  ";
                cin >> idc;
                cin.ignore();

                Cliente cl = Cliente(idc, nom, ap, gen, tel,cor,fi, n);
                cl.actualizar();

				system("cls");
				cout << "                  ____________________________________________________________ " << endl;
				cout << "                 |                                                            |" << endl;
				cout << "                 |   DESEA MODIFICAR OTRO CLIENTE (s/n):                      |" << endl;
				cout << "                 |____________________________________________________________|" << endl;
				cout << "                 |                                                            |" << endl;
				cout << "                 |                                                            |" << endl;
				cout << "                 |____________________________________________________________|" << endl;
				gotoxy(59, 2); cin >> b;
                cin.ignore();
				xc = 20;
				yc = 5;
            } while (b == 's' || b == 'S');

        }
				
        else if (men == 4) {

			gotoxy(3, 13); cout << "INGRESE EL ID DEL CLIENTE QUE DESEA ELIMINAR:  ";
                cin >> idc;
                cin.ignore();


                Cliente cl = Cliente(idc, nom, ap, gen, tel,cor,fi, n);
                cl.eliminar();
				gotoxy(1,18); system("pause");

        }
			} while (men != 0);
		}


		//menu Empleados
		else if (menu == 2) {
			int selec = 0, idp = 0, ide = 0, gen=0;
			char op = 's';
			string nom, ape, dir, tel, d, fn, fil, f;
			int bus;

				do {
					system("cls");
					cout << " ___________________________________________________________ " << endl;
					cout << "|            ********** MENU EMPLEADOS *********            |" << endl;
					cout << "|___________________________________________________________|" << endl;
					cout << "|                                                           |" << endl;
					cout << "|     1. INGRESE NUEVO TRABAJADOR                           |" << endl;
					cout << "|     2. VER BASE DE DATOS DE TRABAJADOR                    |" << endl;
					cout << "|     3. MODIFICAR DATOS DE TRABAJADOR                      |" << endl;
					cout << "|     4. ELIMINAR TRABAJADOR                                |" << endl;
					cout << "|     0. SALIR                                              |" << endl;
					cout << "|                                                           |" << endl;
					cout << "|  ELIGE UNA OPCION:                                        |" << endl;
					cout << "|___________________________________________________________|" << endl;
					cout << "|                                                           |" << endl;
					cout << "|                                                           |" << endl;
					cout << "|___________________________________________________________|" << endl;
					gotoxy(22, 10); cin >> men;
					cin.ignore();

					if (men == 1) {

						system("cls");

						cout << " ____________________________________________________________ " << endl;
						cout << "|               **** INGRESAR NUEVO EMPLEADO ****            |" << endl;
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

						gotoxy(28, 4); getline(cin, nom);
						gotoxy(28, 5); getline(cin, ape);
						gotoxy(28, 6); getline(cin, dir);
						gotoxy(28, 7); getline(cin, tel); 
						gotoxy(28, 8); getline(cin, d);
						gotoxy(28, 9); cin >> gen; cin.ignore();
						gotoxy(28, 10); getline(cin, fn); 
						gotoxy(28, 11); cin >> idp; cin.ignore();
						gotoxy(28, 12); getline(cin, fil);

						empleado em = empleado(ide, nom, ape, dir, tel, d, gen, fn, idp, fil, f); 
						em.crear();
						system("pause"); 
					}

				else if (men == 2) {
						
						empleado em = empleado();
						em.leer();
						system("pause");
				}

				else if (men == 3) {
						char b = 's';
						int xc = 3, yc = 13;
						do {
							gotoxy(xc, yc); cout << "ID DEL EMPLEADO QUE DESEA ACTUALIZAR:  ";
							cin >> ide;
							cin.ignore();

							empleado em = empleado(ide, nom, ape, dir, tel, d, gen, fn, idp, fil, f);
							em.actualizar();

							system("cls");
							cout << "                  ____________________________________________________________ " << endl;
							cout << "                 |                                                            |" << endl;
							cout << "                 |   DESEA MODIFICAR OTRO EMPLEADO (s/n):                      |" << endl;
							cout << "                 |____________________________________________________________|" << endl;
							cout << "                 |                                                            |" << endl;
							cout << "                 |                                                            |" << endl;
							cout << "                 |____________________________________________________________|" << endl;
							gotoxy(59, 2); cin >> b;
							cin.ignore();
							xc = 20;
							yc = 5;
						} while (b == 's' || b == 'S');

					}
				else if (men == 4) {

						gotoxy(3, 13); cout << "INGRESE EL ID DEL CLIENTE QUE DESEA ELIMINAR:  ";
						cin >> ide;	cin.ignore();

					empleado em = empleado(ide, nom, ape, dir, tel, d, gen, fn, idp, fil, f);
					em.eliminar();
					gotoxy(1, 18); system("pause");
				}
			} while (men != 0);
		}

		//menu Puestos
		else if (menu == 3) {
		int selec = 0, idp = 0, ide = 0, gen = 0;
		char op = 's';
		string pues;
		int bus=0;

		do {
			system("cls");
			cout << " ___________________________________________________________ " << endl;
			cout << "|           ********** MENU DE PUESTOS *********            |" << endl;
			cout << "|___________________________________________________________|" << endl;
			cout << "|                                                           |" << endl;
			cout << "|     1. INGRESE NUEVO PUESTO                               |" << endl;
			cout << "|     2. VER PUESTOS                                        |" << endl;
			cout << "|     3. MODIFICAR PUESTO                                   |" << endl;
			cout << "|     4. ELIMINAR PUESTO                                    |" << endl;
			cout << "|     0. SALIR                                              |" << endl;
			cout << "|                                                           |" << endl;
			cout << "|  ELIGE UNA OPCION:                                        |" << endl;
			cout << "|___________________________________________________________|" << endl;
			cout << "|                                                           |" << endl;
			cout << "|                                                           |" << endl;
			cout << "|___________________________________________________________|" << endl;
			gotoxy(22, 10); cin >> men;
			cin.ignore();

			if (men == 1) {

				system("cls");

				cout << " ____________________________________________________________ " << endl;
				cout << "|                **** INGRESAR NUEVO PUESTO ****             |" << endl;
				cout << "|____________________________________________________________|" << endl;
				cout << "|                                                            |" << endl;
				cout << "|   NOMBRE DEL PUESTO:                                       |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|____________________________________________________________|" << endl;

				gotoxy(28, 4); getline(cin, pues);
				
				puesto pu = puesto(idp,pues);
				pu.crear();
				system("pause");
			}

			else if (men == 2) {

				puesto pu = puesto();
				pu.leer();
				system("pause");
			}

			else if (men == 3) {
				char b = 's';
				int xc = 3, yc = 13;
				do {
					gotoxy(xc, yc); cout << "ID DEL PUESTO QUE DESEA ACTUALIZAR:  ";
					cin >> idp;
					cin.ignore();

					puesto pu = puesto(idp, pues);
					pu.actualizar();

					system("pause");
					system("cls");
					cout << "                  ____________________________________________________________ " << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |   DESEA MODIFICAR OTRO PUESTO (s/n):                       |" << endl;
					cout << "                 |____________________________________________________________|" << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |____________________________________________________________|" << endl;
					gotoxy(59, 2); cin >> b;
					cin.ignore();
					xc = 20;
					yc = 5;
				} while (b == 's' || b == 'S');

			}
			else if (men == 4) {

				gotoxy(3, 13); cout << "INGRESE EL ID DEL PUESTO QUE DESEA ELIMINAR:  ";
				cin >> idp;	cin.ignore();

				puesto pu = puesto(idp, pues);
				pu.eliminar();
				gotoxy(1, 18); system("pause");
			}
		} while (men != 0);
		}

		//menu de ventas
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

					Venta vn = Venta(id, nom, ap, n, gen, tel, cor, fi, idc, nfac, ser, f, ide, idp, can, pu, pt);
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
					gotoxy(70, 11); cin >> de;	cin.ignore();

					gotoxy(3, 12); cout << "INGRESE EL ID PARA MODIFICAR:    ";
					cin >> id; cin.ignore();

					if (de == 1) {
						Venta vn = Venta(id, nom, ap, n, gen, tel, cor, fi, idc, nfac, ser, f, ide, idp, can, pu, pt);
						vn.actualizar_Ventas();
					}
					else if (de == 2) {
						Venta_detalle vd = Venta_detalle(id, idv, idp, can, pu);
						vd.Actualizar_Vd();
					}
				}
				else if (men == 4) {

					gotoxy(3, 12); cout << "INGRESE EL ID A ELIMINAR:    ";
					cin >> id; cin.ignore();

					Venta vn = Venta(id, nom, ap, n, gen, tel, cor, fi, idc, nfac, ser, f, ide, idp, can, pu, pt);
					vn.eliminar_Venta();
					gotoxy(3, 17); system("pause");
				}
			} while (men != 0);
		}

		//menu Productos
		else if (menu == 5) {
		int  idp = 0, idm = 0, exi = 0;
		char op = 's';
		string prod, desc, ima,f;
		float pc = 0, pv=0;

		do {
			system("cls");
			cout << " ___________________________________________________________ " << endl;
			cout << "|           ********** MENU PRODUCTOS *********             |" << endl;
			cout << "|___________________________________________________________|" << endl;
			cout << "|                                                           |" << endl;
			cout << "|     1. INGRESAR NUEVO PRODUCTO                            |" << endl;
			cout << "|     2. VER PRODUCTOS                                      |" << endl;
			cout << "|     3. MODIFICAR PRODUCTO                                 |" << endl;
			cout << "|     4. ELIMINAR PRODUCTO                                  |" << endl;
			cout << "|     0. SALIR                                              |" << endl;
			cout << "|                                                           |" << endl;
			cout << "|  ELIGE UNA OPCION:                                        |" << endl;
			cout << "|___________________________________________________________|" << endl;
			cout << "|                                                           |" << endl;
			cout << "|                                                           |" << endl;
			cout << "|___________________________________________________________|" << endl;
			gotoxy(22, 10); cin >> men;
			cin.ignore();

			if (men == 1) {

				system("cls");

				cout << " ____________________________________________________________ " << endl;
				cout << "|               **** INGRESAR NUEVO PRODUCTO ****            |" << endl;
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

				gotoxy(28, 5); getline(cin, prod);
				gotoxy(28, 6); cin >> idm; cin.ignore();
				gotoxy(28, 7); getline(cin, desc);
				gotoxy(28, 8); getline(cin, ima);
				gotoxy(28, 9); cin >> pc; cin.ignore();
				gotoxy(28, 10); cin >> pv; cin.ignore();
				gotoxy(28, 11); cin >> exi; cin.ignore();

				producto pr = producto(idp, prod, idm, desc, ima, pc, pv, exi, f);
				pr.crear();
				system("pause");
			}

			else if (men == 2) {

				producto pr = producto();
				pr.leer();
				system("pause");
			}

			else if (men == 3) {
				char b = 's';
				int xc = 3, yc = 13;
				do {
					gotoxy(xc, yc); cout << "ID DEL PRODUCTO QUE DESEA ACTUALIZAR:  ";
					cin >> idp;
					cin.ignore();

					producto pr = producto(idp, prod, idm, desc, ima, pc, pv, exi, f);
					pr.actualizar();

					system("cls");
					cout << "                  ____________________________________________________________ " << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |   DESEA MODIFICAR OTRO PRODUCTO (s/n):                      |" << endl;
					cout << "                 |____________________________________________________________|" << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |____________________________________________________________|" << endl;
					gotoxy(59, 2); cin >> b;
					cin.ignore();
					xc = 20;
					yc = 5;
				} while (b == 's' || b == 'S');

			}
			else if (men == 4) {

				gotoxy(3, 13); cout << "INGRESE EL ID DEL PRODUCTO QUE DESEA ELIMINAR:  ";
				cin >> idp;	cin.ignore();

				producto pr = producto(idp, prod, idm, desc, ima, pc, pv, exi, f);
				pr.eliminar();
				gotoxy(1, 18); system("pause");
			}
		} while (men != 0);
		}

		//menu Marcas
		else if (menu == 6) {
		int idm = 0;
		char op = 's';
		string marc;

		do {
			system("cls");
			cout << " ___________________________________________________________ " << endl;
			cout << "|             ********** MENU DE MARCA *********            |" << endl;
			cout << "|___________________________________________________________|" << endl;
			cout << "|                                                           |" << endl;
			cout << "|     1. INGRESE NUEVA MARCA                                |" << endl;
			cout << "|     2. VER MARCAS                                         |" << endl;
			cout << "|     3. MODIFICAR MARCA                                    |" << endl;
			cout << "|     4. ELIMINAR MARCA                                     |" << endl;
			cout << "|     0. SALIR                                              |" << endl;
			cout << "|                                                           |" << endl;
			cout << "|  ELIGE UNA OPCION:                                        |" << endl;
			cout << "|___________________________________________________________|" << endl;
			cout << "|                                                           |" << endl;
			cout << "|                                                           |" << endl;
			cout << "|___________________________________________________________|" << endl;
			gotoxy(22, 10); cin >> men;
			cin.ignore();

			if (men == 1) {

				system("cls");

				cout << " ____________________________________________________________ " << endl;
				cout << "|                **** INGRESAR NUEVA MARCA ****              |" << endl;
				cout << "|____________________________________________________________|" << endl;
				cout << "|                                                            |" << endl;
				cout << "|   NOMBRE DELA MARCA:                                       |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|____________________________________________________________|" << endl;

				gotoxy(28, 4); getline(cin, marc);

				marca mar = marca(idm, marc);
				mar.crear();
				system("pause");
			}

			else if (men == 2) {

				marca mar = marca();
				mar.leer();
				system("pause");
			}

			else if (men == 3) {
				char b = 's';
				int xc = 3, yc = 13;
				do {
					gotoxy(xc, yc); cout << "ID DELA MARCA QUE DESEA ACTUALIZAR:  ";
					cin >> idm;
					cin.ignore();

					marca mar = marca(idm, marc);
					mar.actualizar();

					system("pause");
					system("cls");
					cout << "                  ____________________________________________________________ " << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |   DESEA MODIFICAR OTRA MARCA (s/n):                        |" << endl;
					cout << "                 |____________________________________________________________|" << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |____________________________________________________________|" << endl;
					gotoxy(59, 2); cin >> b;
					cin.ignore();
					xc = 20;
					yc = 5;
				} while (b == 's' || b == 'S');

			}
			else if (men == 4) {

				gotoxy(3, 13); cout << "INGRESE EL ID DE LA MARCA QUE DESEA ELIMINAR:  ";
				cin >> idm;	cin.ignore();

				marca mar = marca(idm, marc);
				mar.eliminar();
				gotoxy(1, 18); system("pause");
			}
		} while (men != 0);
		}


		//MENU COMPRAS
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
		
		//Menu Proveedores
		else if (menu == 8) {
		int  idp = 0;
		char op = 's';
		string prov, nit, dir, tel;

		do {
			system("cls");
			cout << " ___________________________________________________________ " << endl;
			cout << "|           ********** MENU PROVEEDOR *********             |" << endl;
			cout << "|___________________________________________________________|" << endl;
			cout << "|                                                           |" << endl;
			cout << "|     1. INGRESAR NUEVO PROVEEDOR                           |" << endl;
			cout << "|     2. VER PROVEEDORES                                    |" << endl;
			cout << "|     3. MODIFICAR PROVEEDOR                                |" << endl;
			cout << "|     4. ELIMINAR PROVEEDOR                                 |" << endl;
			cout << "|     0. SALIR                                              |" << endl;
			cout << "|                                                           |" << endl;
			cout << "|  ELIGE UNA OPCION:                                        |" << endl;
			cout << "|___________________________________________________________|" << endl;
			cout << "|                                                           |" << endl;
			cout << "|                                                           |" << endl;
			cout << "|___________________________________________________________|" << endl;
			gotoxy(22, 10); cin >> men;
			cin.ignore();

			if (men == 1) {

				system("cls");

				cout << " ____________________________________________________________ " << endl;
				cout << "|              **** INGRESAR NUEVO PROVEEDOR ****            |" << endl;
				cout << "|____________________________________________________________|" << endl;
				cout << "|                                                            |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|   NOMBRES DEL PROVEEDOR:                                   |" << endl;
				cout << "|   NIT:                                                     |" << endl;
				cout << "|   DIRECCION:                                               |" << endl;
				cout << "|   TELEFONO:                                                |" << endl;
				cout << "|                                                            |" << endl;
				cout << "|____________________________________________________________|" << endl;

				gotoxy(28, 5); getline(cin, prov);
				gotoxy(28, 6); getline(cin, nit);
				gotoxy(28, 7); getline(cin, dir);
				gotoxy(28, 8); getline(cin, tel);

				proveedor pro = proveedor(idp, prov, nit, dir, tel);
				pro.crear();
				system("pause");
			}

			else if (men == 2) {

				proveedor pro = proveedor();
				pro.leer();
				system("pause");
			}

			else if (men == 3) {
				char b = 's';
				int xc = 3, yc = 13;
				do {
					gotoxy(xc, yc); cout << "ID DEL PROVEEDOR QUE DESEA ACTUALIZAR:  ";
					cin >> idp;
					cin.ignore();

					proveedor pro = proveedor(idp, prov, nit, dir, tel);
					pro.actualizar();

					system("cls");
					cout << "                  ____________________________________________________________ " << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |   DESEA MODIFICAR OTRO PROVEEDOR (s/n):                    |" << endl;
					cout << "                 |____________________________________________________________|" << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |                                                            |" << endl;
					cout << "                 |____________________________________________________________|" << endl;
					gotoxy(59, 2); cin >> b;
					cin.ignore();
					xc = 20;
					yc = 5;
				} while (b == 's' || b == 'S');

			}
			else if (men == 4) {

				gotoxy(3, 13); cout << "INGRESE EL ID DEL PROVEEDOR QUE DESEA ELIMINAR:  ";
				cin >> idp;	cin.ignore();

				proveedor pro = proveedor(idp, prov, nit, dir, tel);
				pro.eliminar();
				gotoxy(1, 18); system("pause");
			}
		} while (men != 0);
		}

	} while (menu != 0);

	return 0;
}
