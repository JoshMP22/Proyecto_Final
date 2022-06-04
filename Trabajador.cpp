#include "Trabajador.h"
#include <iostream>
#include <string>
#include "Proveedor.h"
using namespace std;

int main()
{

    int selec = 0, id = 0;
    char op = 's';
    int ide;
    string nom;
    string ape;
    string dir;
    string tel, d, gen, fn, idp, fil, f;
    int bus;

    do {
        system("cls");
        cout << "___________________________________________________________" << endl;
        cout << "       ********** MENU PROVEEDORES *********" << endl;
        cout << "___________________________________________________________" << endl;
        cout << "     1. INGRESE NUEVO TRABAJADOR" << endl;
        cout << "     2. VER BASE DE DATOS DE TRABAJADOR" << endl;
        cout << "     3. MODIFICAR DATOS DE TRABAJADOR" << endl;
        cout << "     4. ELIMINAR TRABAJADOR" << endl;
        cout << "     0. SALIR" << endl;
        cin >> selec;
        cin.ignore();

        if (selec == 1) {
            char op = 's';
            system("cls");

            do {
                cout << " INGRESE NOMBRE DEL EMPLEADO:                ";
                getline(cin, nom);
                cout << "INGRESE APELLIDO DEL EMPLEADO:         ";
                getline(cin, ape);
                cout << "INGRESE DIRECCION DEL EMPLEADO:   ";
                getline(cin, dir);
                cout << "INGRESE NUMERO DE TELEFONO:        ";
                getline(cin, tel);
                cout << "INGRESE DPI DEL EMPLEADO:   ";
                getline(cin, d);
                cout << "INGRESE GENERO DEL EMPLEADO:   ";
                getline(cin, gen);
                cout << "INGRESE FECHA DE NACIMIENTO DEL EMPLEADO:   ";
                getline(cin, fn);
                cout << "INGRESE PUESTO DEL EMPLEADO:   ";
                getline(cin, idp);
                cout << "INGRESE FECHA DE INGRESO DEL EMPLEADO:   ";
                getline(cin, fil);


                empleado pro = empleado(id, nom, ape, dir, tel, d, gen, fn, idp, fil);
                pro.crear();
                cout << endl << "DESEA INGRESAR OTRO PROVEEDOR (s/n):  ";
                cin >> op;
                cin.ignore();
            } while (op == 's' || op == 'S');
        }
        else if (selec == 2) {
            system("cls");
            empleado  pro = empleado();
            pro.leer();

            system("pause");

        }
        else if (selec == 3) {

            char b = 's';

            system("cls");
            do {
                cout << "INGRESE EL ID DEL CLIENTE QUE DESEA ACTUALIZAR: ";
                cin >> bus;
                cin.ignore();


                empleado pro = empleado(id, nom, ape, dir, tel, d, gen, fn, idp, fil);
                pro.actualizar();

                system("cls");
                cout << "MODIFICAR OTRO PROVEEDOR (s/n): ";
                cin >> b;
                cin.ignore();

            } while (b == 's' || b == 'S');

        }
        else if (selec == 4) {

            system("cls");
            cout << "INGRESE EL ID DEL PROVEEDOR QUE DESEA ELIMINAR: ";
            cin >> id;
            cin.ignore();

            empleado pro = empleado(id, nom, ape, dir, tel, d, gen, fn, idp, fil);
            pro.eliminar();
            system("pause");

        }

    } while (selec != 0);

}
