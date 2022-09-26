
#include "ListNode.h"

ListNode::ListNode()
{
	Siguiente = nullptr;
	letra = ' ';
	codigo = "";
}

ListNode::ListNode(char _letra, std::string codigo)
{



	Siguiente = nullptr;
	letra = _letra;
	this->codigo = codigo;
}

ListNode* ListNode::getSiguiente()
{
	return Siguiente;
}

void ListNode::Imprimir()
{
	std::cout << "Letra asignada: " << letra << "--Codigo:" << codigo<<"\n";


	



}

std::string ListNode::getCodigo()
{
	return codigo;
}

char ListNode::getLetra()
{
	return letra;
}

void ListNode::setSiguiente(ListNode* _Nodo)
{

	Siguiente = _Nodo;
}
