#include"Contenedora.h"


Contenedora::Contenedora(int val, int val2) {
	tamN = val;
	tamM = val2;
	can = 0;
	vec1 = new Habitacion ** [tamN]; //hay que arreglar eso para que use las dos variables
	// Limpiar vector..
	for (int i = 0; i < tamN; i++)// aqui para llenarlo de habitaciones vacias ocupamos un for dentro de otro for
		vec1[i] = NULL;
}

Contenedora::~Contenedora() {
	for (int i = 0; i < can; i++)
		delete vec1[i];
	delete[] vec1;
}

string Contenedora::toString() const { //arreglar
	stringstream s;
	s << "-------------Listado de Habitaciones--------------" << endl;
	for (int i = 0; i < can; i++) {
		if (vec1[i] != NULL)
			s << vec1[i][0]->toString() << endl; //for dentro de forr igual tambien hay que arreglar esto
	}
	s << "----------------------FIN------------------------" << endl;
	return s.str();
}