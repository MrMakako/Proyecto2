#include "ListNode.h"
#include <iostream>
class Lista
{


private:
	ListNode* Inicio;


	ListNode* Ultimo;


public:



	Lista();

	void Inserta(ListNode* Nodo);
	void Imprimir();


	ListNode* Buscar(char letra);


	~Lista();














};
