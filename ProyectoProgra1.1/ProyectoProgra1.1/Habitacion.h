#pragma once
#include"Cliente.h"
#include"info.h"
#include"Hora.h"
#include<time.h>

class Habitacion {
private:
	Info* ptrInfo;
	Cliente* ptrCliente;
	string Id;
	char estado;
	int numDeCamas;
	string clase;
	Hora* ptrHora;
	static int idHabitaciones;
public:
	Habitacion();
	Habitacion(Info* ptrI, Cliente* ptrC, char Estado,Hora* hora);
	virtual ~Habitacion();
	void setInfo(Info*);
	void setCliente(Cliente*);
	void setId(string);
	void setEstado(char);
	void setNumCamas(int);
	void setPtrHora(Hora*);
	Hora* getPtrHora();
	string getClase();
	Info* getInfo();
	Cliente* getCliente();
	string getId();
	char getEstado();
	int getnumCamas();
	void generarNumcamas();
	string toString();
};