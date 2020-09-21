#include"Habitacion.h"


int Habitacion::idHabitaciones = 1;
Habitacion::Habitacion() {
	ptrInfo = NULL;
	ptrCliente = NULL;
	ptrHora = NULL;
	estado = 'L';
	Id = to_string(idHabitaciones++);
	numDeCamas = 2 + rand() % (6 - 2);
	int num = rand() % 3;
	if (num == 0)
		clase = "Primera";
	else
	{
		if (num == 1)
			clase = "Segunda";
		else
			clase = "Tercera";
	};
}
Habitacion::Habitacion(Info* ptrI, Cliente* ptrC, char Estado, Hora* hora) {
	Id = to_string(idHabitaciones++);
	ptrInfo = ptrI;
	ptrCliente = ptrC;
	estado = Estado;
	numDeCamas = 3 + rand() % (5 - 3);
	ptrHora = hora;
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
Info* Habitacion::getInfo() {
	if (ptrInfo)
		return ptrInfo;
	else
		return NULL;
}
Cliente* Habitacion::getCliente() { 
	if (ptrCliente)
		return ptrCliente;
	else
		return NULL;
}
string Habitacion::getId() { return Id; }
char Habitacion::getEstado() { return estado; }
int Habitacion::getnumCamas() { return numDeCamas; }
string Habitacion::toString() {
	stringstream x;
	x << "--------Mostrando la Informacion--------" << endl;
	x << "Numero de Habitacion: " << Id << endl <<
		"Estado de la Habitacion: " << estado << endl <<
		"Numero de camas: " << numDeCamas << endl <<
		"Clase de la habitacion: " << clase<<endl;

	if (ptrCliente) {
		x << ptrCliente->toString();
	}
	else { x << "La Habitacion esta desocupada" << endl; }
	if (ptrInfo) {
		x << ptrInfo->toString();
	}
	else { x << "Esta habitacion no tiene informacion asociada" << endl; }
	x << "-------------Fin Habitacion-------------" << endl;
	return x.str();
}
string Habitacion::getClase() {
	return clase;
}
void Habitacion::setPtrHora(Hora* hora) {
	ptrHora = hora;
}
Hora* Habitacion::getPtrHora() {
	if(ptrHora) {
		return ptrHora;
	}
	return NULL;
}