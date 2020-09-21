#pragma once
#include <sstream>
using namespace std;

class Hora {
private:
    int horas;
    int minutos;
public:
    Hora(int = 0, int = 0);  // Constructor conjunto...
    virtual ~Hora();
    void setHora(int);
    void setMinutos(int);
    int getHora();
    int getMinutos();
    string toString();
};