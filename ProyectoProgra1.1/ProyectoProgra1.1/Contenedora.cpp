#include"Contenedora.h"
#include<string>

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
bool Contenedora::ingresoHabitacion(Cliente *cli, Info* inf,string habId,int hora) { //Para hacer el ingreso se le solicita el ID de la habitacion????
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++)
			if (vec1[i][j]->getId().compare(habId) == 0) {
				vec1[i][j]->setCliente(cli);
				vec1[i][j]->setInfo(inf);
				vec1[i][j]->setHora(hora);
				return true;    //True si se ingreso exitosamente 
			}
	return false; //false si no se inserto adecuadamente 
}
double Contenedora::pagarHabitacion(string ced){
	long double total=0;
	long int personas = 0;
	long int ninos = 0;
	long int adultos = 0;
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++)
			if (vec1[i][j]->getCliente()->getCedula().compare(ced) == 0) {
				personas += (vec1[i][j]->getInfo()->getNumAdultos() + vec1[i][j]->getInfo()->getNumNinos());
				ninos += vec1[i][j]->getInfo()->getNumNinos();
				adultos += vec1[i][j]->getInfo()->getNumAdultos();
				if (vec1[i][j]->getInfo()->getTodoIncluido() == 1) {
					total += (ninos * ninoTodoIncluido);
					total += (adultos * adultoTodoIncluido);


				}
				else if (vec1[i][j]->getHora() > 6) {

					if (personas == 1) {
						total += costNoInluido1Per - (costNoInluido1Per * desc1PNoche);
					}
					else if (personas == 2) {
						total += costNoIncluido2Per - (costNoIncluido2Per * desc2PNoche);
					}
					else if (personas == 3) {
						total += costNoIncluido3Per - (costNoIncluido3Per * desc3PNoche);
					}
					else total += costNoIncluido4Per - (costNoIncluido4Per * desc4PNoche);
				}
				else if (personas == 1) {
					total += costNoInluido1Per;
				}
				else if (personas == 2) {
					total += costNoIncluido2Per;
				}
				else if (personas == 3) {
					total += costNoIncluido3Per;
				}
				else { total += costNoIncluido4Per; }
					
				if (vec1[i][j]->getClase() == "Primera") {
					total += total * primera;
				}
				else if (vec1[i][j]->getClase() == "Segunda") {
					total += total * Segunda;
				}
			}
	return total;

}
void Contenedora::liberarHabitacion(string ced) {
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++)
			if (vec1[i][j]->getCliente()->getCedula().compare(ced) == 0) {
				vec1[i][j]->setCliente(nullptr);
				vec1[i][j]->setInfo(nullptr);
				vec1[i][j]->setEstado('L');
			}
}
double Contenedora::dineroTodoIncluido(){
	long double total = 0;
	long int ninos = 0;
	long int adultos = 0;
	stringstream x;
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++) {
			if (vec1[i][j]->getInfo()->getTodoIncluido() == 1) {
				adultos += vec1[i][j]->getInfo()->getNumAdultos();
				ninos += vec1[i][j]->getInfo()->getNumNinos();
				total += (ninos * ninoTodoIncluido);
				total += (adultos * adultoTodoIncluido);
			}
			if (vec1[i][j]->getClase() == "Primera") {
				total += total * primera;
			}
			else if (vec1[i][j]->getClase() == "Segunda") {
				total += total * Segunda;
			}
		}
	return total;
}
double Contenedora::dineroNoTodoIncluido(){
	long double total = 0;
	long int personas = 0;
	for (int i = 0; i < tamN; i++)
		for (int j = 0; j < tamM; j++)
			if (vec1[i][j]->getInfo()->getTodoIncluido() == 0) {
				personas += (vec1[i][j]->getInfo()->getNumAdultos() + vec1[i][j]->getInfo()->getNumNinos());
				if (vec1[i][j]->getHora() > 6) {

					if (personas == 1) {
						total += costNoInluido1Per - (costNoInluido1Per * desc1PNoche);
					}
					else if (personas == 2) {
						total += costNoIncluido2Per - (costNoIncluido2Per * desc2PNoche);
					}
					else if (personas == 3) {
						total += costNoIncluido3Per - (costNoIncluido3Per * desc3PNoche);
					}
					else total += costNoIncluido4Per - (costNoIncluido4Per * desc4PNoche);
				}
				else if (personas == 1) {
					total += costNoInluido1Per;
				}
				else if (personas == 2) {
					total += costNoIncluido2Per;
				}
				else if (personas == 3) {
					total += costNoIncluido3Per;
				}
				else { total += costNoIncluido4Per; }

				if (vec1[i][j]->getClase() == "Primera") {
					total += total * primera;
				}
				else if (vec1[i][j]->getClase() == "Segunda") {
					total += total * Segunda;
				}
			}

return total;
}
string Contenedora::dineroTotal(){
	stringstream x;
	x << "El dinero total recaudado por el hotel es: " << (dineroTodoIncluido() + dineroNoTodoIncluido()) << " Dolares" << endl;
	return x.str();
}