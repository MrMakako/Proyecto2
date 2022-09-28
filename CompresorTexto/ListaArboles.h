#pragma once
#include "Nodo.h"
#include <string>;
#include "iostream"
#include  <fstream>
class ListaArboles
{
private:
	Nodo* RaizInicial;
	Nodo* Ultimo;
public :
	ListaArboles();

	void Insertar(Nodo *_Raiz);
	void Insertar(Nodo _Raiz);
	void ReconstruirArbol();
	void SuprimirUltimosDos();
	Nodo* ConstruirArbol();
	int size();

	Nodo* getUltimo();

	void GuardarArbol();
	void setRaiz(Nodo* Raiz);
	Nodo* Obtener();
	void QuitarAnteriores();
	Nodo* getRaiz();
	std::string ObtenerCodigo();
	
	Nodo* ConstruirArbol(Nodo *Raiz);
	void Imprimir();
	void Ordenar();





};

