#include "./Includes/Jugador.h"

Jugador::Jugador(){
	victorias = 0;
}

std::string Jugador::getNombre(){
	return Nombre;
}

int Jugador::getValor(){
	return valorTotal;
}

int Jugador::getVictorias(){
	return victorias;
}

bool Jugador::getJugando(){
	return jugando;
}

bool Jugador::getGanador(){
	return ganador;
}

void Jugador::setNombre(std::string nombre){
	Nombre= nombre;
}

void Jugador::ganar(){
	ganador = true;
}

void Jugador::jugar(){
	ganador = false;
	jugando = true;
	valorTotal = 0;
}

void Jugador::sumarValor(int valor){
	valorTotal += valor;
	if(valorTotal >= 21){
		terminarRonda();
	}
}

void Jugador::sumarVictoria(){
	victorias++;
}

void Jugador::terminarRonda(){
	jugando = false;
}