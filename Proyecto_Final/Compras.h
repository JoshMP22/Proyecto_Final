#include<iostream>
#include<mysql.h>
#include<string>
#include<sstream>
#include "Conector.h"

using namespace std;

class Proveedor{

protected: string nit;
		 int buscador = 0, idventa = 0, nofactura=0, idcliente = 0, idempleado = 0;
		 string serie, fechafactura, fechaingreso;


public:
	Proveedor() {}
	Proveedor(int id, int nfac, string ser, string f, int idc, int ide, string fi, int bus){

		idventa = id;
		nofactura = nfac;
		serie = ser;
		fechafactura = f;
		idcliente = idc;
		idempleado = ide;
		fechaingreso = fi;
		buscador = bus;

	}

	void setId(int id) { idventa = id; }
	void setNoFac(int nfac) { nofactura = nfac; }
	void setSerie(string ser) { serie = ser; }
	void setFechaFac(string f) { fechafactura = f; }
	void setIdCliente(int idc) { idcliente = idc; }
	void setIdEmpleado(int ide) { idempleado = ide; }
	void setFechaIng(string fi) { fechaingreso = fi; }
	void setBuscar(int bus) { buscador = bus; }

	int getId() { return idventa; }
	int getNoFac() { return nofactura; }
	string getSerie() { return serie; }
	string getFechaFac() { return fechafactura; }
	int getIdCliente() { return idcliente; }
	int getIdEmpleado() { return idempleado; }
	string getFechaIng() { return fechaingreso; }
	int getBuscar() { return buscador; }

	void crear() {

		int q_estado;
		Conector cn = Conector();

		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string nfac = to_string(nofactura);
			string idc = to_string(idcliente);
			string ide = to_string(idempleado);

			string insert = "INSERT INTO empresa_c.ventas(nofactura, serie, fechafactura, idcliente, idempleado, fechaingreso) VALUES("+nfac+",'"+serie+"', CURDATE(), "+idc+","+ide+",current_time() )"; 
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

			string consulta = "SELECT * FROM empresa_c.ventas";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "         ********* PRODUCTOS ******" << endl;
				cout << " ID   |  NOFACTURA  |  SERIE     | FECHA FACTURA        |  ID CLIENTE | ID EMPLEADO | FECHA INGRESO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << endl;
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
			cout << " 1. No. FACTURA" << endl;
			cout << " 2. SERIE DE FACTURA" << endl;
			cout << " 3. FECHA FACTURA" << endl;
			cout << " 4. ID CLIENTE" << endl;
			cout << " 5. ID EMPLEADO" << endl;
			cout << " 6. FECHA DE INGRESO" << endl;
			cout << " 7. TODOS LOS CAMPOS" << endl;
			cout << " QUE CAMPO DESEA MODIFICAR:  ";
			cin >> men;
			cin.ignore();

			if (men == 1) {

				cout << endl << " INGRESE EL NUMERO DE FACTURA CORRECTO:   ";
				cin >> nofactura;
				string nfac = to_string(nofactura);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET nofactura = "+nfac+" WHERE(idVenta = "+id+")";
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

				cout << endl << " INGRESE EL NUMERO DE SERIE:   ";
				getline(cin,serie); 
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET serie = '" + serie + "' WHERE(idVenta = " + id + ")";
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

				cout << endl << " INGRESE LA FECHA DE LA FACTURA (AAAA-MM-DD):   ";
				getline(cin,fechafactura);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET fechafactura = '" + fechafactura + "' WHERE(idVenta = " + id + ")";
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

				cout << endl << " INGRESE EL ID DEL CLIENTE:   ";
				cin >> idcliente;
				string idc = to_string(idcliente);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET idcliente = " + idc + " WHERE(idVenta = " + id + ")";
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

				cout << endl << " INGRESE EL ID DEL EMPLEADO:   ";
				cin >> idempleado;
				string ide = to_string(idempleado);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET idcliente = " + ide + " WHERE(idVenta = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}
			else if (men == 6) {

				cout << endl << " INGRESE LA FECHA Y HORA DE INGRESO (AAAA-MM-DD):   ";
				getline(cin, fechaingreso);
				string id = to_string(idventa);
				string update = "UPDATE empresa_c.ventas SET fechaingreso = '" + fechaingreso + "' WHERE(idVenta = " + id + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}


			else if (men == 7) {
				cout << endl;

				cout << " NUMERO DE FACUTA:                ";
				cin >> nofactura;
				cout << " INGRESE SERIE DE LA FACTURA:         ";
				getline(cin, serie);
				cout << "INGRESE FECHA DE LA FACTURA:   ";
				getline(cin, fechafactura);
				cout << " INGRESE ID DEL CLIENTE:   ";
				cin >> idcliente;
				cout << " INGRESE ID DEL EMPLEADO:   ";
				cin >> idempleado;
				cout << "INGRESE FECHA DE INGRESO:        ";
				getline(cin, fechaingreso);

				string nfac = to_string(nofactura);
				string idc = to_string(idcliente);
				string ide = to_string(idempleado);
				string id = to_string(idventa);


				string update = "UPDATE empresa_c.ventas SET nofactura = "+nfac+", serie = '"+serie+"', fechafactura = '"+fechafactura+"', idcliente = "+idc+", idempleado= "+ide+", fechaingreso= '"+fechaingreso+"' WHERE(idVenta= "+id+")";
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
		/*int c = 1, r = 0, im = 0;
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;*/
		
		Conector cn = Conector();
		cn.abrir_coneccion();
		string id = to_string(idventa);
		if (cn.getConectar()) {

			string delite = "DELETE FROM empresa_c.ventas WHERE idProveedor= " + id + "";
			const char* i = delite.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				cout << "ELIMINADO CON EXITO .... \n";

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


};

