// ProyectoProgra1.1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <stdlib.h>
#include <iostream>
#include "Contenedora.h"
//Esto se tiene que quitar en un futuro...
using namespace std;
/*
void imprimirSubMenu() {
	system("cls");
	cout << "\t\t >>>> Recaudacion del Hotel <<<<" << endl << endl;
	
	cout << "\t1. Con los clientes, “TODO INCLUIDO”" << endl;
	cout << "\t2. Con los clientes, “Sin TODO INCLUIDO”" << endl;
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
}*/
int main()
{
	Cliente* cli = new Cliente("118060876", "tony", 19, 'E', 63072446, "cr240601");
	Info* inf = new Info(2, 2, 3, 1);
	Contenedora* cont = new Contenedora(3,3);
	cout<<cont->toString();
	//cout << cont->mostrarHabitacionesLibres();
	//cout << cont->habitacionEnMantenimiento();
	//cout << cont->habitacionOcupada();
	//cout << cont->habitacionLibrePorCama(3);
	//cout << cont->AdultosActuales();
	//cout << cont->NinosActuales();
	if (cont->ingresoHabitacion(cli,inf,"CR",7))
		cout<<"se Ingreso"; 
	cout << cont->toString();
	/*int op;
	do {
		imprimirMenu();
		cout << "\t\tSeleccione su opcion: ";
		cin >> op;
		// No operacion. hay que agregar switch o algo
	} while(op != 0);
	system("Pause"); */
	std::cout << "Hello World!\n";
}