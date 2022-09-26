#include "PilaNode.h"

PilaNode::PilaNode()
{


}

PilaNode::PilaNode(int num)
{
	numero = num;
	Anterior = nullptr;
	Siguiente = nullptr;

}

void PilaNode::setAnterior(PilaNode* Anterior)
{


	this->Anterior = Anterior;
}

void PilaNode::setSiguiente(PilaNode* Siguiente)
{


	this->Siguiente = Siguiente;


}



PilaNode* PilaNode::getAnterior()
{
	return  Anterior;
}

PilaNode* PilaNode::getSiguiente()
{
	return Siguiente;
}

int PilaNode::getNum()
{
	return numero;
}


