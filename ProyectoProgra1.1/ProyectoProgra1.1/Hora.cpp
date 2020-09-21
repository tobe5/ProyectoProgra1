#include"Hora.h"

Hora::Hora(int h, int m) {
    horas = h;
    minutos = m;
}

Hora::~Hora() {
}

void Hora::setHora(int hora) {
    horas = hora;
}
void Hora::setMinutos(int minuto) {
    minutos = minuto;
}
int Hora::getHora() {
    return horas;
}
int Hora::getMinutos() {
    return minutos;
}

string Hora::toString() {
    stringstream s;
    s << "Hora = " << horas << ":" << minutos << endl;
    return s.str();
}