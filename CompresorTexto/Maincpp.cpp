#include<iostream>

#include "Compressor.h"



int main() {


	Compressor CompresorTexto("Hola Mundo!!!");
	CompresorTexto.Imprimir();
	CompresorTexto.ConstruirArbol();
	CompresorTexto.GenerarCodigos();
	CompresorTexto.GenerarCodigoHuffman();
	CompresorTexto.GuardarFicheros();
	




	return 0;











}