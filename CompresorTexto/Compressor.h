#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Pila.h"
#include "ListaArboles.h"
#include"Lista.h"
#include <fstream>


using namespace std;

class Compressor
{
	std::vector<char> Letras;
	std::fstream Fichero;
	ListaArboles Arboles;
	Lista Codigos;//se guardaran los codigos asignados
	Pila Caminos;//Guardaremos los caminos
	std::string CodigoHuffman;//Aqui se guardara el codigo huffman generado;
	


public:
	Compressor();
	Compressor(std::string _Texto);
	std::string ObtenerCodigo(Nodo* _Raiz);
	
	void GenerarCodigoHuffman();
	void Imprimir();


	void GenerarCodigos();
	void GuardarFicheros();
	
	void Decodificar();
	void ConstruirArbol();
	
	int Repeticiones(char  Letra);
	void EliminarRepeticiones();

};

