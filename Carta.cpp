#include "./Includes/Carta.h"


Carta::Carta(){
}

Carta::Carta(int Valor, std::string nombre){
	valor = Valor;
	NombreCarta = nombre;
	cantidad = 4;
}

int Carta::getCantidad(){
	return cantidad;
}

int Carta::getValor(){
	return valor;
}

std::string Carta::getNombre(){
	return NombreCarta;
}

void Carta::usarCarta(){
	cantidad--;
}