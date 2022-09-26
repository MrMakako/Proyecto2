
#include "Compressor.h"



Compressor::Compressor()
{
	Arboles =ListaArboles();

	Caminos = Pila();

	Codigos = Lista();
	CodigoHuffman = "";
}

Compressor::Compressor(std::string _Texto) {


	Arboles = ListaArboles();
	CodigoHuffman = "";
	Caminos = Pila();

	Codigos = Lista();
	int contador=1;
	for (char c : _Texto) {
		Letras.push_back(c);
	
	}
	for (int i = 0; i < _Texto.length(); i++) {
		contador=1;
	
		if (_Texto[i]!=NULL ) {
			cout << "Cargando\n";
			for (int x = i + 1; x < _Texto.length(); x++) {
				if (_Texto[x] == _Texto[i]) {
					contador++;
					_Texto[x] = NULL;
				}
			}
			
		
			Nodo* Raiz = new Nodo(_Texto[i]);
			Raiz->setRepeticion(contador);
			Arboles.Insertar(Raiz);
		
		}
		
	
	}



	//Seaprar texto en array



	




}

std::string Compressor::ObtenerCodigo(Nodo* _Raiz)
{
	if (_Raiz == nullptr) {
		return "";
	}

	if (_Raiz->getCamino() !=-1) {

		Caminos.Insertar(new PilaNode(_Raiz->getCamino()));
	
	
	}
	if (_Raiz->Letra == NULL) {
		ObtenerCodigo(_Raiz->getIzquierda());
		Caminos.SacarTope();
		ObtenerCodigo(_Raiz->getDerecha());
		Caminos.SacarTope();
		//Aqui llamamos a quitar de la pila un elemento
	
	
	}
	else {
		std::cout << "Letra ecnontrada:" << _Raiz->Letra << "\n";
		Codigos.Inserta(new ListNode(_Raiz->Letra,Caminos.ObtnerCodigo()));
		return "";
	
	}

	return "";
}

void Compressor::GenerarCodigoHuffman()
{
	std::cout << "Texto a comprimir:\n";
	for (char c : Letras) {
	
		std::cout << c;


		CodigoHuffman = CodigoHuffman + Codigos.Buscar(c)->getCodigo();


	}

	std::cout << "n";
	std::cout << "El Codigo es:" << CodigoHuffman<<"\n";

	
}



void Compressor::Imprimir()
{

	for (char c : Letras) {
		cout << c;
	
	}

}

void Compressor::GenerarCodigos()
{

	ObtenerCodigo(Arboles.getRaiz());
	Codigos.Imprimir();





}

void Compressor::ConstruirArbol()
{
	
	Arboles.Ordenar();
	std::cout << "Ordenado!!!!:";
	Arboles.Imprimir();
	std::cout << "\n";
	Arboles.ConstruirArbol();
}

int Compressor::Repeticiones(char Letra)
{
	int cantidad=0;
	for (int i = 0; i < Letras.size(); i++) {
		if (Letras[i] == Letra) {
			cantidad++;
		}
		
	}

	return 0;
}

void Compressor::EliminarRepeticiones()
{

	for (int x = 0; x < Letras.size(); x++) {
		

		for (int i = x+1; i < Letras.size(); i++) {
			

			if (Letras[x]==Letras[i]) {

				Letras.erase(Letras.begin() + i);
				
				
			}
			
		
		}
	
	}


}
