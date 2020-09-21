// ProyectoProgra1.1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <stdlib.h>
#include <iostream>
#include "Contenedora.h"
//Esto se tiene que quitar en un futuro...
using namespace std;


void imprimirSubMenu() {
	system("cls");
	cout << "\t\t >>>> Recaudacion del Hotel <<<<" << endl << endl;
	
	cout << "\t1. Con los clientes, 'TODO INCLUIDO'" << endl;
	cout << "\t2. Con los clientes, 'Sin TODO INCLUIDO'" << endl;
	cout << "\t3. Con todos los clientes que hay en el hotel" << endl;
	cout << "\t0. Salir" << endl;
}

void imprimirMenu() {
	system("cls");
	cout << "\t\t >>>> MENU <<<<" << endl << endl;

	cout << "\t1. Cuantas habitaciones estan libres" << endl;
	cout << "\t2. Cuantas estan en mantenimiento" << endl;
	cout << "\t3. Cuantas habitaciones ocupadas" << endl;
	cout << "\t4. Cuantas hay desocupadas por cantidad de camas" << endl;
	cout << "\t5. Realizar la ocupacion de la habitacion" << endl;
	cout << "\t6. Pagar la habitacion utilizando el No. de cedula" << endl;
	cout << "\t7. Liberar la habitacion utilizando el No. de cedula" << endl;
	cout << "\t8. Cuantas personas adultas hay el dia de hoy" << endl;
	cout << "\t9. Cuantos ninos existen hoy en el hotel" << endl;
	cout << "\t10. Saber cuanto dinero recaudo hoy el hotel" << endl;
	cout << "\t0. Salir" << endl;
}

int consultaPorNumCamas() {
	cout << "De cuantas camas ocupa la habitacion?" << endl;
	int num;
	cin >> num;
	return num;
}

Cliente* ingresaCliente() {
	string ced, nom, tel, numCuenta;
	int edad;
	char metPago;
	cout << "Ingresando cliente:" << endl;
	cout << "Numero de cedula:" << endl;
	cin >> ced;
	cout << "Nombre del cliente:" << endl;
	cin >> nom;
	cout << "Edad del cliente:" << endl;
	cin >> edad;
	cout << "Metodo de pago (1 = Efectivo, 2 = Tarjeta):" << endl;
	int op;
	do {
		cin >> op;
		if (op == 1) {
			metPago = 'E';
		}
		else {
			metPago = 'T';
		}
	}while (op != 1 && op != 2);

	Cliente* cli = new Cliente(ced, nom, edad, metPago, tel, numCuenta);
	return cli;
}
Info* ingresaInfo() {
	int numAdultos;
	int numNinos;
	int cantDias;
	bool todoIncluido;
	cout << "Ingresando informacion:" << endl;
	cout << "Numero de adultos:" << endl;
	cin >> numAdultos;
	cout << "Numero de ninos:" << endl;
	cin >> numNinos;
	cout << "Cantidad de dias que se va aquedar:" << endl;
	cin >> cantDias;
	cout << "Todo incluido (1 = Sin todo incluido, 2 = Con todo incluido):" << endl;
	int op;
	do {
		cin >> op;
		if (op == 1) {
			todoIncluido = false;
		}
		else {
			todoIncluido = true;
		}
	} while (op != 1 && op != 2);

	Info* inf = new Info(numAdultos, numNinos, cantDias, todoIncluido);
	return inf;
}
string ingresaHabId() {
	string id;
	cout << "Digite el ID de la habitacion:" << endl;
	cin >> id;
	return id;
}

string ingresaCed() {
	string ced;
	cout << "Digite la cedula del cliente:" << endl;
	cin >> ced;
	return ced;
}

void funcionalidadSubMenu(Contenedora* hotel) {
	int op;
	imprimirSubMenu();
	do {
		cout << "\t\tSeleccione su opcion: ";
		cin >> op;
		switch (op) {
		case 1:
			cout << "Las ganancias de habitaciones todo incluido son: " << hotel->getGananciasInclu() << endl;
			system("Pause");
			break;
		case 2:
			cout << "Las ganancias de habitaciones SIN todo incluido son: " << hotel->getGananciasNoInclu() << endl;
			system("Pause");
			break;
		case 3:
			cout << hotel->dineroTotal();
			system("Pause");
			break;
		default:
			cout << "Seleccione una de las opciones disponibles ";
		}
		imprimirSubMenu();
	} while (op != 0);
}

Hora* ingresaHora() {
	int h,m; //horas, minutos
	cout << "Ingresando hora de ingreso:" << endl;
	cout << "Hora (formato 24h):" << endl;
	do {
		cin >> h;
	} while (h < 0 || h > 24);
	cout << "Minutos (60m):" << endl;
	do {
		cin >> m;
	} while (m < 0 || m > 60);

	Hora* hora = new Hora(h, m);
	return hora;
}

int main()
{
	Cliente* cli = new Cliente("11820", "beto", 19, 'E', "63072446", "cr240601");
	Info* inf = new Info(2, 2, 3, 1);
	Contenedora* hotel = new Contenedora(2,2);
	double total;
	hotel->ingresoHabitacion(cli, inf, "358", new Hora(0,0));
	int op;
	imprimirMenu();
	do {
		cout << "\t\tSeleccione su opcion: ";
		cin >> op;
		switch (op) {
		case 1:
			cout << hotel->mostrarHabitacionesLibres();
			system("Pause");
			break;
		case 2:
			cout << hotel->habitacionesEnMantenimiento();
			system("Pause");
			break;
		case 3:
			cout << hotel->habitacionesOcupadas();
			system("Pause");
			break;
		case 4:
			cout << hotel->habitacionLibrePorCama(consultaPorNumCamas());
			system("Pause");
			break;
		case 5:
			cout << hotel->toString();
			if (hotel->ingresoHabitacion(ingresaCliente(), ingresaInfo(), ingresaHabId(), ingresaHora())) {
				cout << "Se Ingreso exitosamente";
			}
			else {
				cout << "No se pudo ingresar:" << endl << "Puede que no haya espacio o el ID esta incorrecto, porfavor intente de nuevo";
			}
			system("Pause");
			break;
		case 6:
			total = hotel->pagarHabitacion(ingresaCed());
			if (total == -1) {
				cout << "Algo salio mal, no se encontro la cedula introducida" << endl;
			}
			else {
				cout << "El precio a pagar por la noche es: " << total << endl;
			}
			system("Pause");
			break;
		case 7:
			if (hotel->liberarHabitacion(ingresaCed())) {
				cout << "Habitacion liberada correctamente" << endl;
			}
			else {
				cout << "La habitacion no se pudo liberar" << endl;
			}
			system("Pause");
			break;
		case 8:
			cout << hotel->AdultosActuales();
			system("Pause");
			break;
		case 9:
			cout << hotel->NinosActuales();
			system("Pause");
			break;
		case 10:
			funcionalidadSubMenu(hotel);
			break;
		}
		imprimirMenu();
	} while(op != 0);
	system("Pause");
	std::cout << "Hello World!\n";
}