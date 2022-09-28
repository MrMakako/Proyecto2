#pragma once

#include <iostream>
#include "Serializado.h"
class Nodo:public Serializado
{
public:

	Nodo();

	Nodo(char _letra);









private:


	int Camino, Repeticion;
	Nodo* Siguiente;
	Nodo* Izq;
	Nodo* Der;

	Serializado Izq_C;
	Serializado Der_C;

	//Estos nodos gaurdaran direcciones de memoeria fijas para realizar la serailizacion 

	
	Nodo* Anterior;
	
public:

	void setSiguiente(Nodo* _Siguiente);

	void setIzq(Nodo *_Izq);
	void setDer(Nodo* _Der);
	void setCamino(int _camino);
	void setAnterior(Nodo* _Anterior);

	Nodo *getDer_C();
	Nodo* getIzq_C();
	Nodo* getAnterior();
	void setRepeticion(int _repeticiones);
	Nodo* getSiguiente();
	Nodo* getDerecha();
	Nodo* getIzquierda();
	int getCamino();
	int getRepeticion();
	char getLetra();

	char Letra;




	

};

