#include<iostream>

#include "Compressor.h"



int main() {


	Compressor CompresorTexto("Laptdsfsdfdsfsdfoprr");
	CompresorTexto.Imprimir();
   CompresorTexto.ConstruirArbol();
    CompresorTexto.GenerarCodigos();
	CompresorTexto.GenerarCodigoHuffman();
	CompresorTexto.GuardarFicheros();
	CompresorTexto.Decodificar();
	




	return 0;











}