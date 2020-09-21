#include"Cliente.h"

Cliente::Cliente() {
	cedula = "indef";
	nombre = "indef";
	edad = 0;
	metodoPago = ' ';
	numTelefono = "000000";
	numCuenta = "ND00000";

}

Cliente::Cliente(string ced, string nom, int ed, char pago, string num, string cuenta) {
	cedula = ced;
	nombre = nom;
	edad = ed;
	metodoPago = pago;
	numTelefono = num;
	numCuenta = cuenta;
}

Cliente::~Cliente() {
}

string Cliente::toString() {
	stringstream x;
	x << " ------------Informacion del cliente------------ " << endl;
	x << "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< "Edad:  " << edad << endl
		<< "Numero de Telefono: " << numTelefono << endl
		<< "Numero de Cuenta: " << numCuenta << endl
		<< "Metodo de pago: " << metodoPago << endl;
	x << " -------------------Fin cliente----------------- " << endl;
	return x.str();
}

void Cliente::setCedula(string ced) { cedula = ced; }
void Cliente::setNombre(string nom) { nombre = nom; }
void Cliente::setEdad(int ed) { edad = ed; }
void Cliente::setMetodoPago(char pago) { metodoPago = pago; }
void Cliente::setNumtelefono(string num) { numTelefono = num; }
void Cliente::setNumCuenta(string cuenta) { numCuenta = cuenta; }

string Cliente::getCedula() { return cedula; }
string Cliente::getNombre() { return nombre; }
int Cliente::getEdad() { return edad; }
string Cliente::getNumTelefono() { return numTelefono; }
string Cliente::getNumCuenta() { return numCuenta; }
char Cliente::getmetodoPago() { return metodoPago; }

bool Cliente::mayorEdad() { return (edad >= 18); }
