#include"Habitacion.h"

Habitacion::Habitacion() {

	// modificaciones aqui para probar con datos quemados para que sea mas rapido

	//ptrInfo = NULL;
	ptrInfo = new Info();
	ptrInfo->setNumNinos(rand() % 3);
	ptrInfo->setNumAdultos(rand() % 13);

	ptrCliente = NULL;
	int num = rand() % 3 ;
	if (num==0)
		estado = 'O';
	else
	{
		if (num==1)
			estado = 'M';
		else
			estado = 'L';
	};	
	Id = "CR";
	numDeCamas = 2 + rand() % (6 - 2);
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
Habitacion::Habitacion(Info* ptrI, Cliente* ptrC, string NumId, char Estado,int hora) {
	ptrInfo = ptrI;
	ptrCliente = ptrC;
	Id = NumId;
	estado = Estado;
	numDeCamas = 3 + rand() % (5 - 3);
	horaEntrada = hora;
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
		"Numero de camas: " << numDeCamas << endl <<
		"Clase de la habitacion: " << clase<<endl;

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
string Habitacion::getClase() {
	return clase;
}
void Habitacion::setHora(int hora) {
	horaEntrada = hora;
}
int Habitacion::getHora() {
	return horaEntrada;
}