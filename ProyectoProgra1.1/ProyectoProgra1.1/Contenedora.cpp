#include"Contenedora.h"


Contenedora::Contenedora(int val, int val2) {
	
	tamN = val;
	tamM = val2;
	can = 0;
	vec1 = new Habitacion ** [tamN]; //hay que arreglar eso para que use las dos variables

	for (int i = 0; i < tamN; i++)// aqui para llenarlo de habitaciones vacias ocupamos un for dentro de otro for
		vec1[i] = new Habitacion*[tamM];
	
	for (int i = 0; i < tamN; i++)  // ==> filas
		for (int j = 0; j < tamM; j++) {
			vec1[i][j] = new Habitacion;
			can++;
		}

}

Contenedora::~Contenedora() {
	for (int i = 0; i < tamN; i++)  // Elimina los objetos dentro de la matriz
		for (int j = 0; j < tamM; j++)
			delete[] vec1[i][j];

	for (int i = 0; i < tamN; i++) // Destruimos los vectores asociados
		delete[] vec1[i];

	delete[] vec1;// Se elimina la matriz
}

string Contenedora::toString() const { //arreglar
	stringstream s;
	s << "-------------Listado de Habitaciones--------------" << endl;
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++) {
			s << vec1[i][j]->toString() << endl;
		}
	s << "----------------------FIN------------------------" << endl;
	return s.str();
}
string Contenedora::mostrarHabitacionesLibres() {
	int contador=0;
	stringstream x;
	x << "Mostrando cantidad de habitaciones libres: " ;
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++) {
			if( vec1[i][j]->getEstado()=='L') 
				contador++;
		}
	x << contador << endl;
	return x.str();
}
string Contenedora::habitacionEnMantenimiento(){
	int contador = 0;
	stringstream x;
	x << "Mostrando cantidad de habitaciones en mantenimiento: ";
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++) {
			if (vec1[i][j]->getEstado() == 'M')
				contador++;
		}
	x << contador << endl;
	return x.str();

}
string Contenedora::habitacionOcupada(){
	int contador = 0;
	stringstream x;
	x << "Mostrando cantidad de habitaciones ocupadas: ";
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++) {
			if (vec1[i][j]->getEstado() == 'O')
				contador++;
		}
	x << contador << endl;
	return x.str();



}
string Contenedora::habitacionLibrePorCama(int camas) {
	stringstream x;
	int conT = 0;
	int conS = 0;
	int conP = 0;
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++) {
			if ( vec1[i][j]->getEstado() == 'L' && vec1[i][j]->getnumCamas() == camas) {
				if (vec1[i][j]->getClase() == "Primera") {
					conP++;
				}
				else if (vec1[i][j]->getClase() == "Segunda") {
					conS++;
				}
				else { conT++;}
				

			}
		}
	x << " Mostrando habitaciones"<<endl;
	x << "Hay " << conP << " habitaciones de primera clase" << endl;
	x << "Hay " << conS << " habitaciones de segunda clase" << endl;
	x << "hay " << conT << " habitaciones de tercera clase" << endl;
	return x.str();
}




string Contenedora::AdultosActuales() {
	stringstream x;
	int conAduls = 0;
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++) {
			// Posiblemente tenemos que anadir un if aqui y para todos los for para ver si vec[][] != NULL
			if (vec1[i][j]->getInfo() != NULL) {
				conAduls+= vec1[i][j]->getInfo()->getNumAdultos();
			}
		}
	x << " Mostrando habitaciones" << endl;
	x << "Hay " << conAduls << " adultos en el hotel hoy" << endl;
	return x.str();
}

string Contenedora::NinosActuales() {
	stringstream x;
	int conNinos = 0;
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++) {
			// Posiblemente tenemos que anadir un if aqui y para todos los for para ver si vec[][] != NULL
			if (vec1[i][j]->getInfo() != NULL) {
				conNinos += vec1[i][j]->getInfo()->getNumNinos();
			}
		}
	x << " Mostrando habitaciones" << endl;
	x << "Hay " << conNinos << " ninos en el hotel hoy" << endl;
	return x.str();
}