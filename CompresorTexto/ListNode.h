
#pragma once
#include <string>
#include <iostream>
class ListNode
{



private:
	ListNode* Siguiente;
	char letra;
	std::string codigo;

public:
	ListNode();

	ListNode(char letra, std::string codigo);
	ListNode* getSiguiente();
	void Imprimir();
	std::string getCodigo();
	char getLetra();
	void setSiguiente(ListNode* _Nodo);





};

