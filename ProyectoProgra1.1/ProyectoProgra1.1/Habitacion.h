#pragma once
#include"Cliente.h"
#include"info.h"
#include<time.h>

class Habitacion {
private:
	Info* ptrInfo;
	Cliente* ptrCliente;
	string Id;
	char estado;
	int numDeCamas;
public:
	Habitacion();
	Habitacion(Info* ptrI, Cliente* ptrC, string NumId, char Estado);
	virtual ~Habitacion();
	void setInfo(Info*);
	void setCliente(Cliente*);
	void setId(string);
	void setEstado(char);
	void setNumCamas(int);
	Info* getInfo();
	Cliente* getCliente();
	string getId();
	char getEstado();
	int getnumCamas();
	void generarNumcamas();
	string toString();
};