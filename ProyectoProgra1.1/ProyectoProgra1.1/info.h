#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Info {
private:
	int numAdultos;
	int numNinos;
	int cantDias;
	bool todoIncluido;
public:
	Info();
	Info(int, int, int, bool);
	virtual ~Info();
	void setNumAdultos(int);
	void setNumNinos(int);
	void setCantDias(int);
	void setTodoIncluido(bool);

	int getNumAdultos();
	int getNumNinos();
	int getCantDias();
	bool getTodoIncluido();

	string toString();
};