#include "./Includes/Carta.h"


Carta::Carta(){
}
Carta::Carta(int Valor, std::string nombre){
	valor = Valor;
	NombreCarta = nombre;
	cantidad = 4;
}

std::string Carta::getNombre(){
	return NombreCarta;
}

int Carta::getValor(){
	return valor;
}

int Carta::getCantidad(){
	return cantidad;
}

void Carta::usarCarta(){
	cantidad--;
}
