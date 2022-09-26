#pragma once
class PilaNode
{
public:



	PilaNode();
	PilaNode(int num);
	
	void setAnterior(PilaNode *Anterior);

	void setSiguiente(PilaNode *Siguiente);


	PilaNode* getAnterior();
	PilaNode* getSiguiente();
	int getNum();

private:

	int numero;
	PilaNode* Siguiente;

	PilaNode* Anterior;




	
};

