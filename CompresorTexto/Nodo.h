#pragma once

#include <iostream>

class Nodo
{
public:

	Nodo();

	Nodo(char _letra);









private:


	int Camino, Repeticion;
	Nodo* Siguiente;
	Nodo* Izq;
	Nodo* Der;
	Nodo* Anterior;
	
public:

	void setSiguiente(Nodo* _Siguiente);

	void setIzq(Nodo *_Izq);
	void setDer(Nodo* _Der);
	void setCamino(int _camino);
	void setAnterior(Nodo* _Anterior);
	Nodo* getAnterior();
	void setRepeticion(int _repeticiones);
	Nodo* getSiguiente();
	Nodo* getDerecha();
	Nodo* getIzquierda();
	int getCamino();
	int getRepeticion();


	char Letra;





	

};

