#pragma once
#include "Nodo.h"
#include <string>;
#include "iostream"
class ListaArboles
{
private:
	Nodo* RaizInicial;
	Nodo* Ultimo;
public :
	ListaArboles();

	void Insertar(Nodo *_Raiz);

	void SuprimirUltimosDos();
	Nodo* ConstruirArbol();
	int size();

	Nodo* getUltimo();
	
	Nodo* Obtener();
	void QuitarAnteriores();
	Nodo* getRaiz();
	std::string ObtenerCodigo();
	
	Nodo* ConstruirArbol(Nodo *Raiz);
	void Imprimir();
	void Ordenar();





};

