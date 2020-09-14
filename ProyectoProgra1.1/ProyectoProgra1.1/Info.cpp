#include "info.h"

Info::Info() {
	numAdultos = 0;
	numNinos = 0;
	cantDias = 0;
	todoIncluido = false;
}

Info::Info(int nAdul, int nNino, int cDia, bool tInclu) {
	numAdultos = nAdul;
	numNinos = nNino;
	cantDias = cDia;
	todoIncluido = tInclu;
}

Info::~Info() {};
void Info::setNumAdultos(int nAdul) {
	numAdultos = nAdul;
}
void Info::setNumNinos(int nNino) {
	numNinos = nNino;
}
void Info::setCantDias(int cDia) {
	cantDias = cDia;
}
void Info::setTodoIncluido(bool tInclu) {
	todoIncluido = tInclu;
}

int Info::getNumAdultos() {
	return numAdultos;
}
int Info::getNumNinos() {
	return numNinos;
}
int Info::getCantDias() {
	return cantDias;
}
bool Info::getTodoIncluido() {
	return todoIncluido;
}
string Info::toString() {
	stringstream s;
	s << "Numero de adultos " << numAdultos << endl
		<< "Numero de ninos " << numNinos << endl
		<< "Numero de dias " << cantDias << endl;
	s << "Todo incluido: " << todoIncluido;
	return s.str();
}
