#include "Nodo.h"

Nodo::Nodo()
{
	Izq = nullptr;
	Der = nullptr;
	Anterior = nullptr;
	Siguiente = nullptr;
	Letra = NULL;
	Camino = -1;
	Repeticion = 0;




}

Nodo::Nodo(char _letra)
{
	Izq = nullptr;
	Der = nullptr;
	Anterior = nullptr;
	Siguiente = nullptr;
	Letra = _letra;
	Camino = -1;
	Repeticion = 0;
	


}

void Nodo::setSiguiente(Nodo* _Siguiente)
{

	Siguiente = _Siguiente;
}

void Nodo::setIzq(Nodo* _Izq)
{
	_Izq->setCamino(0);
	Izq_C = *_Izq;
	Izq = _Izq;

}

void Nodo::setDer(Nodo* _Der)
{
	_Der->setCamino(1);
	Der_C = *_Der;
	Der = _Der;
}

void Nodo::setCamino(int _camino)
{
	Camino = _camino;
}

void Nodo::setAnterior(Nodo* _Anterior)
{
	Anterior = _Anterior;
}

Nodo* Nodo::getDer_C()
{


	return (Nodo*)&Der_C;
}

Nodo* Nodo::getIzq_C()
{
	return (Nodo*)&Izq_C;
}

Nodo* Nodo::getAnterior()
{
	return Anterior;
}

void Nodo::setRepeticion(int _repeticiones)
{
	Repeticion = _repeticiones;
}

Nodo* Nodo::getSiguiente()
{
	return Siguiente;
}

Nodo* Nodo::getDerecha()
{
	return Der;
}

Nodo* Nodo::getIzquierda()
{
	return Izq;
}

int Nodo::getCamino()
{
	return Camino;
}

int Nodo::getRepeticion()
{
	return Repeticion;
}

char Nodo::getLetra()
{
	return Letra;
}
