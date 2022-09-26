#pragma once
#include"PilaNode.h"
#include<string>
#include <iostream>
class Pila
{

public:

	Pila();

	void SacarTope();
	std::string ObtnerCodigo();
	void Insertar(PilaNode* Nodo);
private:

	

	PilaNode* tope;
	PilaNode* Ultimo;



};

