#include"Habitacion.h"

Habitacion::Habitacion() {
	ptrInfo = NULL;
	ptrCliente = NULL;
	Id = " ";
	estado = ' ';
	numDeCamas = 3 + rand() % (5 - 3);

}
Habitacion::Habitacion(Info* ptrI, Cliente* ptrC, string NumId, char Estado) {
	ptrInfo = ptrI;
	ptrCliente = ptrC;
	Id = NumId;
	estado = Estado;
	numDeCamas = 3 + rand() % (5 - 3);
}
Habitacion:: ~Habitacion() {
	if (ptrCliente != NULL) delete ptrCliente;
	if (ptrInfo != NULL) delete ptrInfo;


}
void Habitacion::setInfo(Info* ptri) {
	ptrInfo = ptri;
}
void Habitacion::setCliente(Cliente* ptrc) {
	ptrCliente = ptrc;

}
void Habitacion::setId(string numid) {
	Id = numid;
}
void Habitacion::setEstado(char NEstado) {
	estado = NEstado;
}
void Habitacion::setNumCamas(int num) {
	numDeCamas = num;

}
Info* Habitacion::getInfo() { return ptrInfo; }
Cliente* Habitacion::getCliente() { return ptrCliente; }
string Habitacion::getId() { return Id; }
char Habitacion::getEstado() { return estado; }
int Habitacion::getnumCamas() { return numDeCamas; }
string Habitacion::toString() {
	stringstream x;
	x << "--------Mostrando la Informacion--------" << endl;
	x << "Numero de Habitacion: " << Id << endl <<
		"Estado de la Habitacion: " << estado << endl <<
		"Numero de camas: " << numDeCamas << endl;
	if (ptrCliente) {
		x << ptrCliente->toString();
	}
	else x << "La Habitacion esta desocupada " << endl;
	if (ptrInfo) {
		x << ptrInfo->toString();
	}
	else x << "Esta habitacion no tiene informacion asociada" << endl;

	return x.str();
}