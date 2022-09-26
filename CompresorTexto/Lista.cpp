#include "Lista.h"

Lista::Lista()
{


	Inicio = nullptr;
	Ultimo = nullptr;

}

void Lista::Inserta(ListNode* Nodo)
{

    if (Inicio == nullptr) {

        Inicio = Nodo;
        Ultimo = Nodo;
    }
    else {

        Ultimo->setSiguiente(Nodo);
        Ultimo = Nodo;
    }






}

void Lista::Imprimir()
{


    ListNode* Actual=Inicio;
    while (Actual != nullptr) {
        Actual->Imprimir();
        Actual = Actual->getSiguiente();
        
    }

  
    



}

ListNode* Lista::Buscar(char letra)
{
    ListNode* Actual = Inicio;

    while (Actual != nullptr) {

        if (Actual->getLetra() == letra) {

            return Actual;
        }



        Actual = Actual->getSiguiente();

    }
    return nullptr;
}

Lista::~Lista()
{
}
