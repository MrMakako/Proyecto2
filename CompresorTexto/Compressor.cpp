
#include "Compressor.h"



Compressor::Compressor()
{
	Arboles =ListaArboles();

	Caminos = Pila();
	Fichero = std::fstream("Codigo.txt");
	Codigos = Lista();
	CodigoHuffman = "";

}

Compressor::Compressor(std::string _Texto) {
	Fichero = std::fstream();
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

void Compressor::GuardarFicheros()
{
	std::ofstream FicheroSalida("Codigo.txt");


	if (FicheroSalida.is_open()) {
	
		for (int i = 0; i < CodigoHuffman.length(); i++) {
			FicheroSalida << CodigoHuffman[i];


		}

	}

	FicheroSalida.close();
	//La instancia Fichero se destrye al finalizar la funcion.
	Nodo ArbolGaurdar = *Arboles.getRaiz();
	Fichero = std::fstream("Arbol.acf",std::ios::out,std::ios::binary);
	std::cout << "Esta es la raiz inicial que se gaurda:";
	
	Fichero.write((reinterpret_cast<const char*>(&ArbolGaurdar)), sizeof(Nodo));


	Fichero.close();
	return;
	




}

void Compressor::Decodificar()
{
	Nodo* curr=nullptr;
	Fichero = std::fstream("Codigo.txt", std::ios::in);
	if (Fichero.is_open()) {
		std::string num = "";
		CodigoHuffman = "";
		while (!Fichero.eof()) {
			Fichero >> num;
			CodigoHuffman.append(num);
			 num = "";

		}


		Fichero.close();

	}

	else {
		std::cout <<"Error al abrir el fichero funcion decodificar\n";
	}

	std::ifstream fich = std::ifstream("Arbol.acf", std::ios::binary);




	if (fich) {
		fich.seekg(0, std::ios::beg);

		fich.read((reinterpret_cast< char*>(&RaizPrincipal)), sizeof(Nodo));

		curr = &RaizPrincipal;
		fich.close();
	}
	else {
	
		std::cout << "El fichero no existe\n";
	
	}



	std::string palabra="";
	for (int i = 0; i < CodigoHuffman.length();i++) {
	

		if (CodigoHuffman[i] == '1') {
			
			if (curr != nullptr) {
				curr = curr->getDer_C();
			}
		
		}
		else {
			
			
				curr = curr->getIzq_C();
			
		


		}

		if (curr->getIzq_C() == nullptr && curr->getDer_C() == nullptr) {



			palabra += curr->Letra;
			curr =&RaizPrincipal;


		}

	
		
	}
	std::cout << "\n se decofico:" << palabra<<"\n";





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
