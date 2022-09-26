#include "Pila.h"

void Pila::Insertar(PilaNode* Nodo)
{

	if (tope == nullptr) {
		tope = Nodo;
		Ultimo = Nodo;
	}
	else {
	
		Nodo->setAnterior(tope);
		tope->setSiguiente(Nodo);
		tope = Nodo;
	
	}



}

Pila::Pila()
{
	tope = nullptr;

	Ultimo = nullptr;


}

void Pila::SacarTope()
{
	if (Ultimo != nullptr || tope != nullptr) {

		if (tope->getAnterior()!=nullptr) {
			
			PilaNode* temp = tope;
			tope = tope->getAnterior();
			temp->setAnterior(nullptr);
			tope->setSiguiente(nullptr);
			std::cout << "quitando tope\n";

			delete temp;
		}
		else {
			std::cout << "Borrando en el ultimo\n";
			delete tope;
			tope = nullptr;
			Ultimo = nullptr;
			
		}

	}






//	delete temp;


}

std::string Pila::ObtnerCodigo()
{


	std::string camino = "";

	PilaNode* Actual=Ultimo;
	while (Actual != nullptr) {
		camino = camino + std::to_string(Actual->getNum());
		Actual = Actual->getSiguiente();
	}


	return camino;
}
