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
	double ganancias = 0;
	double gananciasIncluido = 0;
	double gananciasNoIncluido = 0;
	/*static float costNoInluido1Per;
	static float costNoIncluido2Per;
	static float costNoIncluido3Per;
	static float costNoIncluido4Per;
	static float desc1PNoche;
	static double desc2PNoche;
	static double desc3PNoche;
	static double desc4PNoche;
	static double primera;
	static double Segunda;
	static float adultoTodoIncluido;
	static float ninoTodoIncluido;*/
	 long double costNoInluido1Per = 150;
	 long double costNoIncluido2Per = 250;
	 long double costNoIncluido3Per = 350;
	 long double costNoIncluido4Per = 400;
	 long double desc1PNoche = 0.25;
	 long double desc2PNoche = 0.2;
	 long double desc3PNoche = 0.15;
	 long double desc4PNoche = 0.1;
	 long double primera = 0.3;
	 long double Segunda = 0.2;
	 long double adultoTodoIncluido = 300;
	 long double ninoTodoIncluido = 200;
public:
	
	Contenedora(int, int);
	virtual ~Contenedora();
	string toString() const;
	double getGananciasInclu();
	double getGananciasNoInclu();
	string mostrarHabitacionesLibres();
	string habitacionesEnMantenimiento();
	string habitacionesOcupadas();
	string habitacionLibrePorCama(int);
	bool ingresoHabitacion(Cliente*,Info*,string,Hora*);
	string AdultosActuales();
	string NinosActuales();
	double pagarHabitacion(string);
	bool liberarHabitacion(string);
	/*
	double dineroTodoIncluido();
	double dineroNoTodoIncluido();*/
	string dineroTotal();
};