#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Cliente {
private:
	string cedula;
	string nombre;
	int edad;
	char metodoPago;
	int numTelefono;
	string numCuenta;

public:
	Cliente();
	Cliente(string ced, string nom, int ed, char pago, int num, string cuenta);
	virtual ~Cliente();
	string toString();

	void setCedula(string ced);
	void setNombre(string nom);
	void setMetodoPago(char pago);
	void setEdad(int ed);
	void setNumtelefono(int num);
	void setNumCuenta(string cuenta);

	char getmetodoPago();
	string getCedula();
	string getNombre();
	int getEdad();
	int getNumTelefono();
	string getNumCuenta();
	bool mayorEdad();

};