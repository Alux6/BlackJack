#include "Juego.h"
#include "Jugador.h"
#include "Baraja.h"
#include "Carta.h"
Juego::Juego(){
}

Jugador Juego::getJugador(int indice){
	return listaDeJugadores[indice];
}

int Juego::getNumeroJugadores(){
	return numeroJugadores;
}

bool Juego::getTerminado(){
	return terminado;
}

void Juego::Terminar(){
	terminado = true;
}

void Juego::iniciarRonda(){
	terminado = false;
	for (int i = 0; i < numeroJugadores; i++){
		listaDeJugadores[i].jugar();
	}
}

void Juego::decirPuntuacion(int indice){
	if(listaDeJugadores[indice].getNombre() == "Banca"){
		std::cout << "La Banca tiene: " << listaDeJugadores[indice].getValor() << " Puntos\n";
	}
	else{
		std::cout << listaDeJugadores[indice].getNombre() <<
			", tienes: " << listaDeJugadores[indice].getValor() << " Puntos.\n";
	}
}

void Juego::elegirGanador(){
	int mayor = 0;
	for(int i = 0; i < numeroJugadores; i++){
		int valorJugador = listaDeJugadores[i].getValor();
		if(valorJugador <= 21){
			if(i == 0){
				mayor = valorJugador;
			}
			else if(listaDeJugadores[i].getValor() > mayor){
				mayor = valorJugador;
			}
		}
	}
	for(int i = 0; i < numeroJugadores; i++){
		int valorJugador = listaDeJugadores[i].getValor();
		if(valorJugador == mayor){
			listaDeJugadores[i].ganar();
		}
	}
}

int Juego::decisionBanca(){
	int suma = 0, valorMedioCartas, decision = 0;

	for(int i = 0; i < baraja.getUtilizadas(); i++){
		suma += baraja.getCarta(i).getValor();
	}
	valorMedioCartas = suma / baraja.getUtilizadas();
	if(listaDeJugadores[numeroJugadores - 1].getValor() + valorMedioCartas < 21){
		decision = 1;
		std::cout << "La banca ha cogido otra carta\n";
	}
	else{
		decision = 2;
		std::cout << "La banca se retira.\n";
	}
	return decision;
}

void Juego::definirJugadores(){
	int numJugadores;
	Jugador a, b, c, d, e, f, g, h, i, j, banca;
	Jugador listaJug[TAM] = {a, b, c, d, e, f, g, h, i, j};
	do{
	std::cout << "Introduzca el número de jugadores que van a participar (Máximo 10, Minimo 2):\n";
	std::cin >> numJugadores;
	}while(numJugadores < 2 || numJugadores > 10);
	numeroJugadores = numJugadores;
	for(int i = 0; i < numeroJugadores; i++){
		std::string nombre;
		std::cout << "Introduzca el nombre del jugador " << i + 1 << std::endl;
		std::cin >> nombre;
		listaDeJugadores[i].setNombre(nombre);
		for (int i = 0; i < numeroJugadores; i++){
		}
	}
	listaDeJugadores[numeroJugadores] = banca;
	listaDeJugadores[numeroJugadores].setNombre("Banca");
	std::cout << numeroJugadores;
	numeroJugadores++;
}

bool Juego::continuar(int indice){
	int decision = 0;
	if(listaDeJugadores[indice].getNombre() != "Banca"){
		do{
			decirPuntuacion(indice);
			std::cout << "Desea coger más cartas?\n 1) Si.\n 2) No.\n";
			std::cin >> decision;
		}while(decision < 1 || decision > 2);
	}
	else{
		decirPuntuacion(indice);
		decision = decisionBanca();
	}
	if(decision == 1){
		return true;
	}
	else{
		return false;
	}
}

int Juego::numeroDeGanadores(){
	int Ganadores = 0;
	for (int i = 0; i < numeroJugadores; i++){
		if(listaDeJugadores[i].getGanador()){
			Ganadores++;
		}
	}
	return Ganadores;
}

void Juego::devolverGanadores(){
	elegirGanador();
	int numGanadores = numeroDeGanadores();
	if(numGanadores == 0){
		std::cout << "No ha ganado nadie.";
	}
	else if (numGanadores == 1){
		std::cout << "El ganador es: \n";
	}
	else{
		std::cout << "Los ganadores son: \n";
	}
	for (int i = 0; i < numeroJugadores; i++){
		if(listaDeJugadores[i].getGanador()){
			std::cout << listaDeJugadores[i].getNombre() << std::endl;
			listaDeJugadores[i].sumarVictoria();
		}
	}
}

void Juego::desarrolloDeLaRonda(){

	srand((unsigned) time(0));
	for (int j = 0; j < 100; j++){
		std::cout << std::endl;
	}
	for(int i = 0; i < getNumeroJugadores(); i++){
			std::cout << getJugador(i).getNombre() << ": " <<
			getJugador(i).getVictorias() << " Victorias.\n";
	}
	while(!getTerminado()){
		int jugadas = 0;
		bool jugando = false;
		for (int i = 0; i < getNumeroJugadores(); i++){
			jugando = jugada(i);
			if(jugando){
				jugadas++;
			}
		}
		if(jugadas == 0){
			Terminar();
		}
	}
}

bool Juego::finalizarPartida(){
	int aux = 0;
	bool terminar = false;
	do{
		std::cout << "\nSeguir jugando?\n 1) Si. \n 2) No.\n";
		std::cin >> aux;
	}while(aux < 1 || aux > 2);
	if (aux == 2){
		terminar = true;
	}
	else{
		iniciarRonda();
	}
	return terminar;
}

int Juego::sacarCarta(){
	int carta = (rand() % baraja.getUtilizadas());
	return carta;
}

bool Juego::jugada(int i){
	if(listaDeJugadores[i].getJugando()){
		if(continuar(i)){
			int carta = sacarCarta();
			int valorCarta = baraja.getCarta(carta).getValor();
			if(valorCarta == 11 && listaDeJugadores[i].getValor() + 11 > 21){
				valorCarta = 1;
			}
			listaDeJugadores[i].sumarValor(valorCarta);
			std::cout << "Ha salido un " << baraja.getCarta(carta).getNombre()
				<< ", por lo que te sumas " << valorCarta << " puntos.\n\n";
			baraja.cartaUsada(carta);
		}
		else{
			listaDeJugadores[i].terminarRonda();
		}
		return true;
	}
	else{
		return false;
	}
}
