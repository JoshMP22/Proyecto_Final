#include <iostream>
#include <string>
#include <conio.h>
#include <string.h>
#include "Ventas_detalles.h" 
#include "Cliente.h"
#include <cstdlib>

using namespace std;

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
	int menu=0, men=0;
	char m='s';

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
		gotoxy(23,14); cin >> menu;

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
					cin>> gen;
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
				int gen=0, idc=0, ide=0, id=0, c=0, idp=0, nfac=0, idv=0;
				string n, nom, ap, dir, tel, cor, ser, fi, f, can;
				float pu=0, pt=0;

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
				gotoxy(23,10); cin >> men;
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
					gotoxy(31,3); getline(cin, n);

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
				
					if(de==1){
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
			} while (men!=0);
		}


	} while (menu != 0);

	return 0;
}

