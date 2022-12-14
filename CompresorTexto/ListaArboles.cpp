#include "ListaArboles.h"

ListaArboles::ListaArboles()
{

	RaizInicial = 0;
	Ultimo = 0;
}

void ListaArboles::Insertar(Nodo* _Raiz)
{

	if (RaizInicial == nullptr) {
		RaizInicial = _Raiz;
		Ultimo = _Raiz;


	}
	else {
		


		Ultimo->setSiguiente(_Raiz);
		_Raiz->setAnterior(Ultimo);

		Ultimo =Ultimo->getSiguiente();
	
	}







}

void ListaArboles::Insertar(Nodo _Raiz)
{
	Nodo* Nuevo = new Nodo();
	Nuevo->setCamino(_Raiz.getCamino());
	Nuevo->Letra = _Raiz.getLetra();
	Nuevo->setRepeticion(_Raiz.getRepeticion());
	if (RaizInicial == nullptr) {
		RaizInicial = Nuevo;
		Ultimo = Nuevo;


	}
	else {



		Ultimo->setSiguiente(Nuevo);
		Nuevo->setAnterior(Ultimo);

		Ultimo = Ultimo->getSiguiente();

	}


}

void ListaArboles::ReconstruirArbol()
{


	std::ifstream fich = std::ifstream("Arbol.acf", std::ios::binary);

	delete RaizInicial;
	delete Ultimo;

	RaizInicial = nullptr;
	Ultimo = nullptr;



	Nodo Raiz;

	if (fich) {
		fich.seekg(0, std::ios::beg);
		fich.read((reinterpret_cast<char*>(&Raiz)), sizeof(Nodo));
		do {

	
			std::cout << Raiz.getLetra() << "------GUARANDDO\n";
			Insertar(Raiz);
			fich.read((reinterpret_cast<char*>(&Raiz)), sizeof(Nodo));
		
		} while (!fich.eof());
	

		
		fich.close();
	}
	 ConstruirArbol();

}

void ListaArboles::SuprimirUltimosDos()
{
	Nodo* Temp1 = RaizInicial;
	
	Nodo* Temp2=RaizInicial->getSiguiente();

	delete Temp1;

	delete Temp2;




}





Nodo* ListaArboles::ConstruirArbol()
{

	RaizInicial = ConstruirArbol(RaizInicial);


	return RaizInicial;
}

int ListaArboles::size()
{


	Nodo* Actual=RaizInicial;
	while (Actual != nullptr) {
		Actual = Actual->getSiguiente();
	
	}

	return 0;

}

Nodo* ListaArboles::getUltimo()
{
	Nodo* Actual();






	return nullptr;
}

void ListaArboles::GuardarArbol()
{

	std::remove("Arbol.acf");
	Nodo ArbolGaurdar=*RaizInicial;

	std:: ofstream Fichero = std::ofstream("Arbol.acf", std::ios::app, std::ios::binary);
	std::cout << "Esta es la raiz inicial que se gaurda:";

	while (true) {
	
	
		Fichero.write((reinterpret_cast<const char*>(&ArbolGaurdar)), sizeof(Nodo));


		
		if (ArbolGaurdar.getSiguiente() == nullptr) {

			break;
		}
		

			ArbolGaurdar = *ArbolGaurdar.getSiguiente();
		
		
	
	
		//para almacenar el arbol lo haremos cunado este separado despues solo deberiamos de ordnearlo para obtener el resultado;;;;;

	
	
	}
	Fichero.close();
	







}

void ListaArboles::setRaiz(Nodo* Raiz)
{
	RaizInicial = Raiz;
}

Nodo* ListaArboles::Obtener()
{
	return nullptr;
}

void ListaArboles::QuitarAnteriores()
{



	





}

Nodo* ListaArboles::getRaiz()
{
	return RaizInicial;
}

std::string ListaArboles::ObtenerCodigo()
{



	return std::string();
}






Nodo* ListaArboles::ConstruirArbol(Nodo* Raiz)
{

	
	
	Nodo* Nodo1;
	Nodo1 = Raiz;

	Nodo* Nodo2 = Raiz->getSiguiente();
	//tomamos los primeros dos nodos
	
	if (Nodo2 != nullptr) {
		//Si hay mas de un nodo
	
		Nodo* NuevoNodo = new Nodo(NULL);
		NuevoNodo->setRepeticion(Nodo1->getRepeticion() + Nodo2->getRepeticion());
		NuevoNodo->setDer(Nodo2);
		NuevoNodo->setIzq(Nodo1);
		if (Nodo1->Letra != NULL) {
			std::cout << "se combinarion dos raicez <<" << Nodo1->Letra<<"\n";
		}
		if (Nodo2->Letra != NULL) {
			std::cout << "se combinarion dos raicez <<" << Nodo2->Letra << "\n";
		}
		if (Nodo2->getSiguiente() != nullptr) {
			Insertar(NuevoNodo);
			return ConstruirArbol(Nodo2->getSiguiente());
		}
		else {	
			return ConstruirArbol(NuevoNodo);
		}
		




		
		
			
	}

	return Raiz;




}

void ListaArboles::Imprimir()
{


	Nodo* Actual=RaizInicial;

	while (Actual != nullptr) {
		
		if (!Actual->Letra ) {
			std::cout << Actual->Letra;
		}
	

		Actual = Actual->getSiguiente();
	
	}

	std::cout << "\n";
	Actual = Ultimo;
	while (Actual != nullptr) {


		std::cout << Actual->Letra;

		Actual = Actual->getAnterior();


	}
	std::cout << "\n";
}

void ListaArboles::Ordenar()
{

	Nodo* Iterador = RaizInicial;///Primer iterador
	Nodo* Actual = RaizInicial;///Primer iterador
	Nodo* Actual2 = RaizInicial;//Segundo iterador
	Nodo* Mayor=nullptr;
	Nodo* Menor=nullptr;
	while (Iterador != nullptr) {
		
		Actual=RaizInicial;

		while (Actual != nullptr) {
			
			if (Actual->getSiguiente() != nullptr) {

				if (Actual->getSiguiente()->getRepeticion() < Actual->getRepeticion()) {
					std::cout << Actual->getSiguiente()->getRepeticion() << "<" << Actual->getRepeticion() << "\n";
					Mayor = Actual;
					Menor = Actual->getSiguiente();
					if (Menor == Ultimo) {
						Ultimo = Mayor;
					}
					if (Mayor == RaizInicial) {
						RaizInicial = Menor;
					}
					std::cout << Mayor->getRepeticion() << ">" << Menor->getRepeticion()<<"\n";
					if (Mayor->getAnterior() != nullptr) {
						
					
						Mayor->getAnterior()->setSiguiente(Menor);
						Menor->setAnterior(Mayor->getAnterior());

						

						std:: cout<< "Mayor tiene un nodo atras\n";
					}
					if (Menor->getSiguiente() != nullptr) {
					
						Mayor->setSiguiente(Menor->getSiguiente());
						Menor->getSiguiente()->setAnterior(Mayor);
						std::cout << "Menor tiene un nodo enfrente\n";
					}
					else {
					
						Mayor->setSiguiente(nullptr);

					}

					
					Mayor->setAnterior(Menor);
					Menor->setSiguiente(Mayor);

					std::cout << "Ordenando\n";
			

				}
				
				
			}
			std::cout << "Estamos en:" << Actual->getRepeticion() << "\n";

			Actual = Actual->getSiguiente();
		

		}

		Iterador = Iterador->getSiguiente();
		std::cout << "Terminando el ciclo\n";
	}


}
