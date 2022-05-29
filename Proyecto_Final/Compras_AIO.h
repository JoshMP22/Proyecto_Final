#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Ventas_detalles.h"

using namespace std;


class Compras_AIO
{
protected:
	Conector obj_conexion;

	int int_idcompra = 0, int_no_orden_compra = 0, int_idproveedor = 0;
	string str_fecha_orden;
	
	int int_idproducto = 0, int_cantidad = 0;
	float flt_precio_costo_unitario = 0.0;

public:
	Compras_AIO() {
	}

	Compras_AIO(int int_idcom, int int_nooc, int int_idprov, string str_feor, int int_idprod, int int_can, float flt_pre) {
		int_idcompra = int_idcom;
		int_no_orden_compra = int_nooc;
		int_idproveedor = int_idprov;
		str_fecha_orden = str_feor;
		int_idproducto = int_idprod;
		int_cantidad = int_can;
		flt_precio_costo_unitario = flt_pre;
	}


	int Compras_AIO_max() {
		//Función para devolver el idCompra del ultimo registro y utilizarlo al ingresar el detalle de compras
		obj_conexion.abrir_coneccion();
		MYSQL_ROW fila;
		MYSQL_RES* result;
		int int_max{};

		string max_dat = "SELECT MAX(idCompra) AS idCompra FROM compras";
		const char* execute_show = max_dat.c_str();
		int q_estado = mysql_query(obj_conexion.getConectar(), execute_show);
		result = mysql_store_result(obj_conexion.getConectar());
		while (fila = mysql_fetch_row(result)) {
			int_max = atoi(fila[0]);
		}
		return int_max;
		obj_conexion.cerrar_coneccion();
	}

	void Compras_AIO_ingreso(int int_fase) {
		obj_conexion.abrir_coneccion();
		//Fase 1 = Ingreso de Ventas; Fase 2 = Ingreso del detalle de ventas. 
		string str_idCompra = to_string(int_idcompra);
		int q_estado = 0;
		if (int_fase == 1) {
			string str_no_orden_compra = to_string(int_no_orden_compra);
			string str_idproveedor = to_string(int_idproveedor);

			string insert_dat = "insert into compras (no_orden_compra, idProveedor, fecha_orden, fechaingreso) values (" + str_no_orden_compra + ", '" + str_idproveedor + "', '" + str_fecha_orden + "', NOW())";
			const char* execute_insert = insert_dat.c_str();
			q_estado = mysql_query(obj_conexion.getConectar(), execute_insert);
		}
		else if (int_fase == 2) {
			string str_idproducto = to_string(int_idproducto);
			string str_cantidad = to_string(int_cantidad);
			string str_precio_costo_unitario = to_string(flt_precio_costo_unitario);

			string insert_dat = "insert into compras_detalle (idCompra, idproducto, cantidad, precio_costo_unitario) values(" + str_idCompra + ", " + str_idproducto + ", '" + str_cantidad + "', " + str_precio_costo_unitario + ")";
			const char* execute_insert = insert_dat.c_str();
			q_estado = mysql_query(obj_conexion.getConectar(), execute_insert);
		}
		else {
			cout << "\n\nError: Fase inexistente.\n\n";
		}

		if (!q_estado) {
			cout << "\n\nValores registrados\n\n";
		}
		else {
			cout << "\n\nError: " << mysql_error(obj_conexion.getConectar());
		}

		obj_conexion.cerrar_coneccion();
	}

	void Compras_AIO_mostrar(int int_opcion, int int_variable, string str_id) {
		/*
		Combinaciones:
			(int_opcion = 1 && int_variable = 1) = Mostrar solo tabla Compra.
			(int_opcion = 2 && int_variable = 1) = Mostrar solo tabla Compra_Detalle.
			(int_opcion = 1 && int_variable = 2 && str_id = "x") = Filtra por idCompra sobre ambas tablas.
		*/
		if (int_opcion == 1 || int_opcion == 2) {
			if (int_variable == 1 || int_variable == 2) {
				obj_conexion.abrir_coneccion();
				MYSQL_ROW fila;
				MYSQL_RES* result;
				string show_dat;

				do {
					show_dat = "select * from ";
					if (int_opcion == 1) {
						if (int_variable == 1) {
							show_dat = show_dat + "compras";
						}
						else if (int_variable == 2) {
							show_dat = "select idCompra, no_orden_compra, proveedores.proveedor, fecha_orden, fechaingreso from compras inner join proveedores on proveedores.idProveedores=compras.idProveedor where idCompra=" + str_id;
						}
					}
					else if (int_opcion == 2) {
						if (int_variable == 1) {
							show_dat = show_dat + "compras_detalle";
						}
						else if (int_variable == 2) {
							show_dat = "select idCompra_Detalle, idCompra, productos.producto, cantidad, precio_costo_unitario from compras_detalle inner join productos on productos.idProducto=compras_detalle.idproducto where idCompra=" + str_id;
						}
					}
					else if (int_opcion == 3) {
						show_dat = "select sum(cantidad*precio_costo_unitario) as Total from compras_detalle where idCompra=" + str_id;
					}
					const char* execute_show = show_dat.c_str();
					int q_estado = mysql_query(obj_conexion.getConectar(), execute_show);
					if (!q_estado) {
						int i = 1;
						result = mysql_store_result(obj_conexion.getConectar());
						if (int_opcion == 1) {
							cout << "No. | ID, No.Orden de Compra, Proveedor, FechaOrden, FechaIngreso" << endl;
						}
						else if (int_opcion == 2) {
							cout << "No. | ID, ID-Compra, ID-Producto, Cantidad, PrecioUnitario |" << endl;
						}
						while (fila = mysql_fetch_row(result)) {
							if (int_opcion <= 2) {
								cout << i << " | " << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << endl;
							}
							else if (int_opcion == 3) {
								cout << "Total: " << fila[0] << endl;
							}
							i++;
						}
					}
					else {
						cout << "\n\nError: Por favor, ingrese un ID correcto.\n\n";
					}

					if (int_opcion <= 3 && int_variable == 2) {
						int_opcion++;
					}
					else {
						int_opcion = 4;
					}
				} while (int_opcion < 4);

				obj_conexion.cerrar_coneccion();
			}
			else {
				cout << "Error: Por favor ingrese una combinación valida en la variable.";
			}
		}
		else {
			cout << "Error: Por favor ingrese una combinación valida en la opcion.";
		}
	}

	void Compras_AIO_eliminar(string str_id, int int_tabla) {
		/*
		(str_id) = ID a eliminar.
		(int_tabla = 1) = Tabla Compra.
		(int_tabla = 2) = Tabla Compra_detalle.
		*/
		string delete_dat = "delete from ";
		obj_conexion.abrir_coneccion();

		if (int_tabla == 1) {
			delete_dat = delete_dat + "compras where idCompra=" + str_id;
		}
		else if (int_tabla == 2) {
			delete_dat = delete_dat + "compras_detalle where idCompra_detalle=" + str_id;
		}
		else {
			cout << "\n\nError: Ingrese un valor de tabla correcto.\n\n";
		}

		const char* execute_delete = delete_dat.c_str();
		int q_estado = mysql_query(obj_conexion.getConectar(), execute_delete);

		if (!q_estado) {
			cout << "\n\nEliminado\n\n";
		}
		else {
			cout << "\n\nError: ";
			const char* chr_errorbase = "Cannot delete or update a parent row: a foreign key constraint fails";
			const char* chr_error = mysql_error(obj_conexion.getConectar());
			int int_error = strcmp(chr_errorbase, chr_error);

			if (int_error == 0) {
				cout << "Por favor elimine todos los registros asociados a la venta. ";
			}
			else {
				cout << "Por favor verique que el ID exista o comuniquese con su administrador";
			};
		}
		obj_conexion.cerrar_coneccion();
	}

	void Compras_AIO_actualizar(string str_id, string str_columna, string str_nuevo_valor, int int_tabla) {
		/*
		(str_id) = ID a actualizar.
		(str_columna) = Columna a modificar sus registros.
		(str_nuevo_valor) = Nuevo valor.
		(int_tabla = 1) = Tabla Ventas.
		(int_tabla = 2) = Tabla Ventas_detalle.
		*/
		string update_dat;
		obj_conexion.abrir_coneccion();

		if (int_tabla == 1) {
			update_dat = "update compras set " + str_columna + "='" + str_nuevo_valor + "' where idCompra=" + str_id;
		}
		else if (int_tabla == 2) {
			update_dat = "update compras_detalle set " + str_columna + "='" + str_nuevo_valor + "' where idCompra_detalle=" + str_id;
		}
		else {
			cout << "Error: Ingrese un valor de tabla correcto";
		}

		const char* execute_update = update_dat.c_str();
		int q_estado = mysql_query(obj_conexion.getConectar(), execute_update);
		if (!q_estado) {
			cout << "\n\nActualizado\n\n";
		}
		else {
			cout << "\n\nError: " << mysql_error(obj_conexion.getConectar());
		}
		obj_conexion.cerrar_coneccion();
	}
};

