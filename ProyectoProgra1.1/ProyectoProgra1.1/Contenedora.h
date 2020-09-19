#pragma once
#include<sstream>
#include"Habitacion.h"
using namespace std;

class Contenedora {
private:
	//podriamos necesitar variaberls n y m para que la matriz tenga n columnas y m filas
	int tamN; // tamaño del vector de Directores.
	int tamM; // tamaño del vector de Directores.
	int can; // cantidad de Directores.
	Habitacion*** vec1; // Vector de Directores.

public:
	Contenedora(int, int);
	virtual ~Contenedora();
	string toString() const;
	string mostrarHabitacionesLibres();
	string habitacionEnMantenimiento();
	string habitacionOcupada();
	string habitacionLibrePorCama(int);

	string AdultosActuales();
	string NinosActuales();
};