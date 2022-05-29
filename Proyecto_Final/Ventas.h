#include<iostream>
#include<mysql.h>
#include<string>
#include<string.h>
#include<conio.h>
#include<sstream>
#include<Windows.h>
#include "Cliente.h"

using namespace std;

class Venta {

protected:	 int idcliente = 0, genero = 0;
			 string serie, fechafactura;
			 int idventa = 0, nofactura = 0, idempleado = 0;
			 string nombre, apellido, nit, telefono, correo, fechaingreso, producto;
			 int idproducto=0;
			 string cantidad;
			 float preciounitario=0, preciototal=0;


public:
	Venta() {} 
	Venta(int idc, string nom, string ap, string n, int gen, string tel, string cor, string fi, int id, int nfac, string ser, string f, int ide, int idp, string can, float pu, float pt ) {
		
		idcliente = idc;
		nombre = nom;
		apellido = ap;
		nit = n;
		genero = gen;
		telefono = tel; 
		correo = cor;
		fechaingreso = fi;
		idventa = id;
		nofactura = nfac;
		serie = ser;
		fechafactura = f;
		idempleado = ide;
		idproducto = idp;
		cantidad = can;
		preciounitario = pu;
		preciototal = pt;

	}

	void setIdCliente(int idc) { idcliente = idc; }
	void setNombre(string nom) { nombre = nom; }
	void setApellido(string ap) { apellido = ap; }
	void setNit(string n) { nit = n; }
	void setGenero(int gen) { genero = gen; }
	void setTelefono(string tel) { telefono = tel; }
	void setCorreo(string cor) { correo = cor; }
	void setFechaIng(string fi) { fechaingreso = fi; }
	void setId(int id) { idventa = id; }
	void setNoFac(int nfac) { nofactura = nfac; }
	void setSerie(string ser) { serie = ser; }
	void setFechaFac(string f) { fechafactura = f; }
	void setIdEmpleado(int ide) { idempleado = ide; }
	void setIdProducto(int idp) { idproducto = idp; }
	void setCantidad(string can) { cantidad = can; }
	void setPrecUnit(float pu) { preciounitario = pu; }
	void setPrecTotal(float pt) { preciototal = pt; }

	int getIdCliente() { return idcliente; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getNit() { return nit; }
	int getGenero() { return genero; }
	string getTelefono() { return telefono; }
	string getCorreo() { return correo; }
	string getFechaIng() { return fechaingreso; }
	int getId() { return idventa; }
	int getNoFac() { return nofactura; }
	string getSerie() { return serie; }
	string getFechaFac() { return fechafactura; }
	int getIdEmpleado() { return idempleado; }
	int getIdProducto() { return idproducto; }
	string getCantidad() { return cantidad; }
	float getPrecioU() { return preciounitario; }
	float getPrecioT() { return preciototal; }

	
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



		
	void crear_Venta() {

		int q_estado, q_stado, q_estadon, c=1, c2=0, nn=0, f=0, ff=0, co=0; 
		string rn, idcl, fac, ven, pu, prod;
		float cant=0, total=0;
		char x = 's';
		char n[12], produc[100];
	
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;
		Conector cn = Conector();

		cn.abrir_coneccion();

		if (cn.getConectar()) {

			strcpy_s(n, nit.c_str());
			nn = strlen(n);

			if (nit == "C/F" || nit == "c/f") {

				gotoxy(13, 4); cout << "Consumidor Final";

				gotoxy(3, 6); cout << "INGRESE ID EMPREADO: ";
				gotoxy(24, 6); cin >> idempleado;
				cin.ignore();

				system("cls");
				cout << "\n\n      No. FACUTRA:                        FECHA:" << endl;
				cout << "                                                                                           OPCIONES" << endl;
				cout << "      NIT:" << endl;
				cout << "      NOMBRE:" << endl;
				cout << "      DIRECCION:" << endl;
				cout << "\n                          **** FACTURA ****" << endl;
				cout << "\n  CODIGO            DETALLES                     PRECIO     PRECIO" << endl;
				cout << "                                                UNITARIO     TOTAL" << endl;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                             TOTAL" << endl;
				cout << "\n\n       ''Los Mejores Precios en este lugar, solo para ti''" << endl;

				Cuadro(0, 7, 70, 9); Cuadro(0, 12, 70, 12);  Cuadro(0, 23, 70, 23);  Cuadro(0, 25, 70, 25);
				Cuadro(10, 9, 10, 23);  Cuadro(46, 9, 46, 23);  Cuadro(57, 9, 57, 25);  Cuadro(0, 0, 70, 28);

				Cuadro(72, 4, 118, 4);  Cuadro(72, 2, 118, 7);

				do {
					c = 1;

					gotoxy(75, 6);  cout << "INGRESE ID DE PRODUCTO:_______________";
					gotoxy(103, 6);  cin >> idproducto;
					cin.ignore();
					gotoxy(2, 14 + c2);  cout << idproducto;

					string consulta = "SELECT * FROM empresa_c.productos";
					const char* j = consulta.c_str();
					q_stado = mysql_query(cn.getConectar(), j);

					if (!q_stado) {
						resultado = mysql_store_result(cn.getConectar());

						while (fila = mysql_fetch_row(resultado)) {

							if (c == idproducto) {
								gotoxy(13, 14 + c2); cout << "  " << fila[1];
								gotoxy(49, 14 + c2); cout << fila[6];
								pu = fila[6];
							}
							c++;
						}
					}

					gotoxy(75, 6);  cout << "CANTIDAD DE PRODUTOS:_________________";
					gotoxy(103, 6); getline(cin, cantidad);
					gotoxy(13, 14 + c2); cout << cantidad;

					string consultav = "SELECT * FROM empresa_c.ventas";
					const char* ji = consultav.c_str();
					q_stado = mysql_query(cn.getConectar(), ji);

					if (!q_stado) {
						resultado = mysql_store_result(cn.getConectar());

						while (fila = mysql_fetch_row(resultado)) {

							ven = fila[0];
							fac = fila[1];
							istringstream(fac) >> ff;
							ff -= co;
							string fa = to_string(ff);
							fac = fa;
							serie = fila[2];
						}
					}
					co = 1;

					string consultacli = "SELECT * FROM empresa_c.clientes";
					const char* ii = consultacli.c_str();
					q_estadon = mysql_query(cn.getConectar(), ii);

					if (!q_estadon) {
						resultado = mysql_store_result(cn.getConectar());

						while (fila = mysql_fetch_row(resultado)) {

							rn = fila[3];

							if (rn == nit) {
								idcl = fila[0];
								nombre = fila[1];
								apellido = fila[2];
								break;
							}
						}
					}

					istringstream(fac) >> nofactura;
					istringstream(pu) >> preciounitario;
					istringstream(cantidad) >> cant;
					istringstream(ven) >> idventa;
					idventa += 1;
					preciototal = cant * preciounitario;
					total += preciototal;
					f = nofactura + 1;
					string idv = to_string(idventa);
					string idp = to_string(idproducto);
					string nfac = to_string(f);
					string ide = to_string(idempleado);


					string insert = "INSERT INTO empresa_c.ventas(nofactura, serie, fechafactura, idcliente, idempleado, fechaingreso) VALUES(" + nfac + ",'" + serie + "', CURDATE(), 1," + ide + ",current_time() )";
					const char* iii = insert.c_str();
					q_estado = mysql_query(cn.getConectar(), iii);
					if (!q_estado) {
						gotoxy(1, 29); cout << "*********INGRESADO CON EXITO**********  \n";

					}
					else {
						system("cls");
						gotoxy(6, 3); cout << "************ ERROR DE CONECCION ************\n";
					}

					string insertd = "INSERT INTO empresa_c.ventas_detalle(idVenta, idProducto, cantidad, precio_unitario) VALUES (" + idv + ", " + idp + ", '" + cantidad + "', " + pu + ")";
					const char* jj = insertd.c_str();
					q_estadon = mysql_query(cn.getConectar(), jj);
					if (!q_estadon) {
						gotoxy(1, 29); cout << "*********INGRESADO CON EXITO**********  \n";
					}
					else {
						system("cls");
						gotoxy(6, 3); cout << "************ ERROR DE CONECCION EN VENTAS DETALLES ************\n";
					}

					gotoxy(60, 14 + c2); cout << preciototal;
					gotoxy(60, 24); cout << total;

					gotoxy(75, 6); cout << "DESEA INGRESAR NUEVO PRODUCTO (s/n):  ";
					gotoxy(111, 6); cin >> x;
					cin.ignore();

					string consultave = "SELECT * FROM empresa_c.ventas";
					const char* ve = consultave.c_str();
					q_stado = mysql_query(cn.getConectar(), ve);

					if (!q_stado) {
						resultado = mysql_store_result(cn.getConectar());

						while (fila = mysql_fetch_row(resultado)) {

							fechaingreso = fila[6];

						}
					}
					c2++;
				} while (x == 's' || x == 'S');

				gotoxy(20, 2); cout << serie << f;
				gotoxy(47, 2); cout << fechaingreso;
				gotoxy(17, 4); cout << "C/F";
				gotoxy(17, 5); cout << " Consumidor Final";
				gotoxy(17, 6); cout << " Ciudad";
				gotoxy(1, 29); system("pause");
		
			}


			else if (nn == 8) {
					

					string consulta = "SELECT * FROM empresa_c.clientes";
					const char* ii = consulta.c_str();
					q_estadon = mysql_query(cn.getConectar(), ii);
					
					if (!q_estadon) {
						resultado = mysql_store_result(cn.getConectar());

						while (fila = mysql_fetch_row(resultado)) {
						
							rn = fila[3]; 
							
						if (rn == nit) {
							gotoxy(13, 4); cout << fila[1] << " "<<fila[2] << endl;
							break;
							}
						}
						if (rn != nit) {

							Cuadro(60, 2, 106, 2);	Cuadro(60, 0, 106, 8);
							gotoxy(61, 1);  cout << "                NUEVO CLIENTE";
							gotoxy(61, 3);  cout << " INGRESE NOMBRES:";
							gotoxy(61, 4);  cout << " INGRESE APELLIDOS:";
							gotoxy(61, 5);  cout << " GENERO (0= Femenino, 1= Masculino):";
							gotoxy(61, 6);  cout << " TELEFONO:";
							gotoxy(61, 7);  cout << " CORREO ELECTRONICO:";
							
							gotoxy(82, 3); getline(cin, nombre);
							gotoxy(82, 4); getline(cin, apellido);
							gotoxy(100, 5); cin >> genero;
							cin.ignore();
							gotoxy(82, 6); getline(cin, telefono);
							gotoxy(82, 7); getline(cin, correo);
							
							string gen = to_string(genero);
							string insert = "INSERT INTO empresa_c.clientes(nombres, apellidos, NIT, genero, telefono, correo_electronico, fechaingreso) VALUES('"+nombre+"', '"+apellido+"', '"+nit+"', "+gen+", '"+telefono+"', '"+correo+"', current_time())";
							const char* i = insert.c_str();
							q_estado = mysql_query(cn.getConectar(), i);
							
							if (!q_estado) {
								cout << "INGRESADO CON EXITO" << endl;
							}
							else {
								cout << "ERROR DE CONECCION" << endl;
							}

						}
					}
					
					gotoxy(3, 6); cout << "INGRESE ID EMPREADO: ";
					gotoxy(24, 6); cin >> idempleado;
					cin.ignore();
			
					system("cls");
					cout << "\n\n      No. FACUTRA:                        FECHA:" << endl;
					cout << "                                                                                           OPCIONES" << endl;
					cout << "      NIT:" << endl;
					cout << "      NOMBRE:" << endl;
					cout << "      DIRECCION:" << endl;
					cout << "\n                          **** FACTURA ****" << endl;
					cout << "\n  CODIGO            DETALLES                     PRECIO     PRECIO" << endl;
					cout << "                                                UNITARIO     TOTAL" << endl;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                             TOTAL" << endl;
					cout << "\n\n       ''Los Mejores Precios en este lugar, solo para ti''" << endl;

					Cuadro(0, 7, 70, 9); Cuadro(0, 12, 70, 12);  Cuadro(0, 23, 70, 23);  Cuadro(0, 25, 70, 25);
					Cuadro(10, 9, 10, 23);  Cuadro(46, 9, 46, 23);  Cuadro(57, 9, 57, 25);  Cuadro(0, 0, 70, 28);

					Cuadro(72, 4, 118, 4);  Cuadro(72, 2, 118, 7);

					
					do {
						c = 1;
						
						gotoxy(75, 6);  cout << "INGRESE ID DE PRODUCTO:_______________";
						gotoxy(103, 6);  cin >> idproducto;
						cin.ignore();
						gotoxy(2, 14+c2);  cout << idproducto;
						
						string consulta = "SELECT * FROM empresa_c.productos";
						const char* j = consulta.c_str();
						q_stado = mysql_query(cn.getConectar(), j);

						if (!q_stado) {
							resultado = mysql_store_result(cn.getConectar());

							while (fila = mysql_fetch_row(resultado)) {

								if (c == idproducto) {
									gotoxy(13, 14+c2); cout <<"  " << fila[1];
									gotoxy(49, 14+c2); cout << fila[6];
									pu = fila[6];
								}
								c++;
							}
						}

						gotoxy(75, 6);  cout << "CANTIDAD DE PRODUTOS:_________________";
						gotoxy(103, 6); getline(cin, cantidad);
						gotoxy(13, 14+c2); cout << cantidad;

						string consultav = "SELECT * FROM empresa_c.ventas";
						const char* ji = consultav.c_str();
						q_stado = mysql_query(cn.getConectar(), ji);

						if (!q_stado) {
							resultado = mysql_store_result(cn.getConectar());

							while (fila = mysql_fetch_row(resultado)) {

								ven = fila[0];
								fac = fila[1];
								istringstream(fac) >> ff;
								ff -= co;
								string fa = to_string(ff);
								fac = fa;
								serie = fila[2];
							}
						}
						co = 1;

						string consultacli = "SELECT * FROM empresa_c.clientes";
						const char* ii = consultacli.c_str();
						q_estadon = mysql_query(cn.getConectar(), ii);

						if (!q_estadon) {
							resultado = mysql_store_result(cn.getConectar());

							while (fila = mysql_fetch_row(resultado)) {

								rn = fila[3];

								if (rn == nit) {
									idcl = fila[0];
									nombre = fila[1];
									apellido = fila[2];
									break;
								}
							}
						}

						istringstream(fac) >> nofactura;
						istringstream(pu) >> preciounitario;
						istringstream(cantidad) >> cant;
						istringstream(ven) >> idventa;
						idventa += 1;
						preciototal = cant * preciounitario;
						total += preciototal;
						f = nofactura + 1;
						string idv = to_string(idventa);
						string idp = to_string(idproducto);
						string nfac = to_string(f);
						string ide = to_string(idempleado);


						string insert = "INSERT INTO empresa_c.ventas(nofactura, serie, fechafactura, idcliente, idempleado, fechaingreso) VALUES(" + nfac + ",'" + serie + "', CURDATE(), "+idcl+", " + ide + ", current_time() )";
						const char* iii = insert.c_str();
						q_estado = mysql_query(cn.getConectar(), iii);
						if (!q_estado) {
							gotoxy(1, 29); cout << "*********INGRESADO CON EXITO**********  \n";

						}
						else {
							system("cls");
							gotoxy(6, 3); cout << "************ ERROR DE CONECCION ************\n";
							system("pause");
						}

						string insertd = "INSERT INTO empresa_c.ventas_detalle(idVenta, idProducto, cantidad, precio_unitario) VALUES (" + idv + ", " + idp + ", '" + cantidad + "', " + pu + ")";
						const char* jj = insertd.c_str();
						q_estadon = mysql_query(cn.getConectar(), jj);
						if (!q_estadon) {
							gotoxy(1, 29); cout << "*********INGRESADO CON EXITO**********  \n";
						}
						else {
							system("cls");
							gotoxy(6, 3); cout << "************ ERROR DE CONECCION EN VENTAS DETALLES ************\n";
							system("pause");
						}

						gotoxy(60, 14+c2); cout << preciototal;
						gotoxy(60, 24); cout << total;

						gotoxy(75, 6); cout << "DESEA INGRESAR NUEVO PRODUCTO (s/n):  ";
						gotoxy(111, 6); cin >> x;
						cin.ignore();

						string consultave = "SELECT * FROM empresa_c.ventas";
						const char* ve = consultave.c_str();
						q_stado = mysql_query(cn.getConectar(), ve);

						if (!q_stado) {
							resultado = mysql_store_result(cn.getConectar());

							while (fila = mysql_fetch_row(resultado)) {

								fechaingreso = fila[6];
								
							}
						}
						c2++;
					} while (x == 's' || x == 'S');

					gotoxy(20, 2); cout <<serie<< f;
					gotoxy(47, 2); cout << fechaingreso;
					gotoxy(17, 4); cout << nit;
					gotoxy(17, 5); cout << nombre << " " << apellido;
					gotoxy(17, 6); cout << " CIUDAD";
					gotoxy(1, 29); system("pause");
			}
			else {
			system("cls");
				cout << " EL NIT ES INCORRECTO, **** EL NIT DEBE CONTENER 7 DIGITOS Y UN DIGITO VERIFICADOR ***" << endl;
				system("pause");
				}
		}
		else {
		system("cls");
		gotoxy(6, 3); cout << "************ ERROR DE CONECCION EN VENTAS DETALLES ************\n";
		system("pause");
		}
		cn.cerrar_coneccion();

	}

	void leer_Ventas() {
		int q_estado,q_stado;
		int c = 0, ive=0, idve=0, cc=0;
		char d = 'n';

		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;
		cn.abrir_coneccion();

		if (cn.getConectar()) {
			
			string consulta = "SELECT * FROM empresa_c.ventas";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				system("cls");
				cout << " ___________________________________________________________________________________________________ " << endl;
				cout << "|                                       ********* VENTAS *********                                  |" << endl;
				cout << "|___________________________________________________________________________________________________|" << endl;
				cout << "| ID  |  NOFACTURA  | SERIE |    FECHA FACTURA    | ID CLIENTE | ID EMPLEADO |     FECHA INGRESO    |" << endl;
				cout << "|_____|_____________|_______|_____________________|____________|_____________|______________________|" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					gotoxy(0, 5 + c); cout << "|     |             |       |                     |            |             |                      |" << endl;
					gotoxy(2,  5+c); cout << fila[0]; gotoxy(11, 5+c); cout << fila[1]; gotoxy(24, 5+c); cout << fila[2]; gotoxy(35, 5+c); cout << fila[3];
					gotoxy(57, 5+c); cout << fila[4]; gotoxy(70, 5+c); cout << fila[5]; gotoxy(80, 5+c); cout << fila[6];
					c++;
				}
				cout << "\n|_____|_____________|_______|_____________________|____________|_____________|______________________|" << endl << endl;

				do {
					gotoxy(0, 6 + c); cout << " DESEA VAER LOS DETALLES DE ALGUNA VENTA (s/n):  ___";
					gotoxy(50, 6 + c); cin >> d;

					if (d == 's' || d == 'S') {
						gotoxy(0, 7 + c); cout << " INGRESE ID DE LA VENTA: ___";
						gotoxy(26, 7 + c); cin >> ive;
						ive -= 1;
						string consulta = "SELECT * FROM empresa_c.ventas";
						const char* i = consulta.c_str();
						q_estado = mysql_query(cn.getConectar(), i);

						if (!q_estado) {
							resultado = mysql_store_result(cn.getConectar());
							while (fila = mysql_fetch_row(resultado)) {
								if (ive == cc) {
									gotoxy(0,9+c); cout << " ______________________________________________________________ ";
									cout << "\n|                     DETALLES DE LA VENTA                     |";
									cout << "\n|______________________________________________________________|";
									cout << "\n|  ID  | ID VENTA | ID PRODUCTO |  CANTIDAD  | PRECIO UNITARIO |";
									cout << "\n|______|__________|_____________|____________|_________________|";
									cout << "\n|      |          |             |            |                 |";
									cout << "\n|______|__________|_____________|____________|_________________|";

									string consultad = "SELECT * FROM empresa_c.ventas_detalle";
									const char* j = consultad.c_str();
									q_stado = mysql_query(cn.getConectar(), j);

									if (!q_stado) {
										resultado = mysql_store_result(cn.getConectar());
										while (fila = mysql_fetch_row(resultado)) {
											if (ive == idve) {
												gotoxy(4, 14 + c); cout << fila[0]; gotoxy(11, 14 + c); cout << fila[1]; gotoxy(23, 14 + c); cout << fila[2];
												gotoxy(38, 14 + c); cout << fila[3]; gotoxy(50, 14 + c); cout << fila[4];
											}
											idve++;
										}
									}	
								}
								cc++;
							}
						}
					}
					gotoxy(0, 16 + c); system("pause");
					cc = 0;
					
					
				} while (d=='s'|| d=='S');
			}
			else {
				system("cls");
				gotoxy(6, 3); cout << "************ ERROR DE CONECCION EN VENTAS DETALLES ************\n";
				system("pause");
			}
		}
		else {
			system("cls");
			gotoxy(6, 3); cout << "************ ERROR DE CONECCION EN VENTAS DETALLES ************\n";
			system("pause");
		}
		cn.cerrar_coneccion();


	}

	void actualizar_Ventas() {

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
			cout << "|         1. No. FACTURA                                                 |" << endl;
			cout << "|         2. SERIE DE FACTURA                                            |" << endl;
			cout << "|         3. FECHA FACTURA                                               |" << endl;
			cout << "|         4. ID CLIENTE                                                  |" << endl;
			cout << "|         5. ID EMPLEADO                                                 |" << endl;
			cout << "|         6. FECHA DE INGRESO                                            |" << endl;
			cout << "|         7. TODOS LOS CAMPOS                                            |" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|                  QUE CAMPO DESEA MODIFICAR:   _____                    |" << endl;
			cout << "|________________________________________________________________________|" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|                                                                        |" << endl;
			cout << "|________________________________________________________________________|" << endl;
			gotoxy(50,11); cin >> men;
			cin.ignore();

			if (men == 1) {

				gotoxy(04, 14); cout << "      INGRESE EL NUMERO DE FACTURA CORRECTO:  ";
				cin >> nofactura;
				string nfac = to_string(nofactura);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET nofactura = " + nfac + " WHERE(idVenta = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(03, 16);  cout << "                        MODIFICADO CON EXITO"<< endl << endl;
				}
				else {
					gotoxy(03, 16);  cout << "                 **** ERROR DE CONECCION ****"<< endl << endl;
				}
			}

			else if (men == 2) {

				gotoxy(04, 14); cout << "        INGRESE EL NUMERO DE SERIE:   ";
				getline(cin, serie);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET serie = '" + serie + "' WHERE(idVenta = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(03, 16);  cout << "                      MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(03, 16);  cout << "                **** ERROR DE CONECCION ****"<< endl <<endl;
				}
			}

			else if (men == 3) {

				gotoxy(03, 14); cout << "    INGRESE LA FECHA DE LA FACTURA (AAAA-MM-DD):   ";
				getline(cin, fechafactura);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET fechafactura = '" + fechafactura + "' WHERE(idVenta = " + id + ")";
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

				gotoxy(04, 14); cout << "       INGRESE EL ID DEL CLIENTE:   ";
				cin >> idcliente;
				string idc = to_string(idcliente);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET idcliente = " + idc + " WHERE(idVenta = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(03, 16);  cout << "                      MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(03, 16);  cout << "               **** ERROR DE CONECCION ****" << endl << endl;
				}
			}
			else if (men == 5) {

				gotoxy(04, 14); cout << "        INGRESE EL ID DEL EMPLEADO:   ";
				cin >> idempleado;
				string ide = to_string(idempleado);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET idcliente = " + ide + " WHERE(idVenta = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(03, 16);  cout << "                      MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(03, 16);  cout << "               **** ERROR DE CONECCION ****" << endl << endl;
				}
			}
			else if (men == 6) {

				gotoxy(02, 14); cout << "INGRESE LA FECHA Y HORA DE INGRESO (AAAA-MM-DD):   __________ ________";
				gotoxy(53, 14); getline(cin, fechaingreso);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET fechaingreso = '" + fechaingreso + "' WHERE(idVenta = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(03, 16);  cout << "              MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(03, 16);  cout << "       **** ERROR DE CONECCION ****" << endl << endl;
				}
			}


			else if (men == 7) {
				system("cls");
				cout << " ______________________________________________________ " << endl;
				cout << "|              **** CAMPOS A MODIFICAR ****            |" << endl;
				cout << "|______________________________________________________|" << endl;
				cout << "|                                                      |" << endl;
				cout << "|   NUMERO DE FACUTA:                                  |" << endl;
				cout << "|   SERIE DE LA FACTURA:                               |" << endl;
				cout << "|   FECHA DE LA FACTURA:                               |" << endl;
				cout << "|   ID DEL CLIENTE:                                    |" << endl;
				cout << "|   ID DEL EMPLEADO:                                   |" << endl;
				cout << "|   FECHA DE INGRESO:                                  |" << endl;
				cout << "|______________________________________________________|" << endl;
				cout << "|                                                      |" << endl;
				cout << "|                                                      |" << endl;
				cout << "|______________________________________________________|" << endl;
				gotoxy(28, 4); cin >> nofactura;
				cin.ignore();
				gotoxy(28, 5); getline(cin, serie);
				gotoxy(28, 6); getline(cin, fechafactura);
				gotoxy(28, 7); cin >> idcliente;
				cin.ignore();
				gotoxy(28, 8); cin >> idempleado;
				cin.ignore();
				gotoxy(28, 9); getline(cin, fechaingreso);

				string nfac = to_string(nofactura);
				string idc = to_string(idcliente);
				string ide = to_string(idempleado);
				string id = to_string(idventa);


				string update = "UPDATE empresa_c.ventas SET nofactura = " + nfac + ", serie = '" + serie + "', fechafactura = '" + fechafactura + "', idcliente = " + idc + ", idempleado= " + ide + ", fechaingreso= '" + fechaingreso + "' WHERE(idVenta= " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					gotoxy(16, 12); cout << "MODIFICADO CON EXITO" << endl << endl;
				}
				else {
					gotoxy(16, 12); cout << "ERROR DE CONECCION" << endl << endl;
				}
			}


		}
		else {
		system("cls");
		cout << endl<<endl;
			cout << "                      ******** ERROR DE CONECCION ******** \n";
		}
		system("pause");
		cn.cerrar_coneccion();

	}

	void eliminar_Venta() {

		int q_estado, q_stado;
		char d = 'n';
		int c = 1, ive=0;

		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;
		cn.abrir_coneccion();

		cn.abrir_coneccion();
		string id = to_string(idventa);
		if (cn.getConectar()) {

			string consultad = "SELECT * FROM empresa_c.ventas";
			const char* j = consultad.c_str();
			q_stado = mysql_query(cn.getConectar(), j);

			if (!q_stado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					if (idventa == c) {
						gotoxy(44, 4); cout << " __________________________________________________________________ " << endl;
						gotoxy(44, 5); cout << "|                  ********* VENTAS *********                      |" << endl;
						gotoxy(44, 6); cout << "|__________________________________________________________________|" << endl;
						gotoxy(44, 7); cout << "| ID | NO | SERIE | FECHA FACTURA | ID | ID |     FECHA INGRESO    |" << endl;
						gotoxy(44, 7); cout << "| ID |FACT| SERIE | FECHA FACTURA |CLIE|EMPL|     FECHA INGRESO    |" << endl;
						gotoxy(44, 8); cout << "|____|____|_______|_______________|____|____|______________________|" << endl;
						gotoxy(44, 9); cout << "|    |    |       |               |    |    |                      |" << endl;
						gotoxy(46, 9); cout << fila[0]; gotoxy(51, 9); cout << fila[1]; gotoxy(58, 9); cout << fila[2]; gotoxy(65, 9); cout << fila[3];
						gotoxy(80, 9); cout << fila[4]; gotoxy(85, 9); cout << fila[5]; gotoxy(90, 9); cout << fila[6];
						
					}
						gotoxy(44, 10);cout << "|____|____|_______|_______________|____|____|______________________|" << endl;
					c++;
				}
			}


			gotoxy(44, 11);            cout << "|                                                                  |" << endl;
			gotoxy(44, 12);            cout << "|          SEGURO QUE DESE ELIMINAR ESTE REGISTRO (s/n):           |" << endl;
			gotoxy(44, 13);            cout << "|__________________________________________________________________|" << endl;
			gotoxy(102, 12);	cin >> d;

			if (d == 's' || d == 'S') {
				string delite = "DELETE FROM empresa_c.ventas WHERE idVenta= " + id + "";
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
					cout << "|________________________________________|" << endl; cout << "ERROR DE CONECCION.... \n";
				}
			}
			else {
				gotoxy(0, 14); cout << "|                                        |" << endl;
				cout << "|          CANCELADO CON EXITO           |" << endl;
				cout << "|________________________________________|" << endl; cout << "ERROR DE CONECCION.... \n";
			}

		}
		else {
			gotoxy(0, 14); cout << "|                                        |" << endl;
			cout << "|           ERROR DE CONECCION           |" << endl;
			cout << "|________________________________________|" << endl; cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccion();


	}


};



