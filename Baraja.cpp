#include "./Includes/Baraja.h"

Baraja::Baraja(){
	rellenar();
}
void Baraja::rellenar(){
	Carta As(11,"As"), K(10,"K"), Q(10,"Q"), J(10,"J"), Nueve(9,"Nueve"), Ocho(8,"Ocho"),
	Siete(7,"Siete"), Seis(6,"Seis"), Cinco(5,"Cinco"), Cuatro(4,"Cuatro"),
	Tres(3,"Tres"), Dos(2,"Dos");
	barajaDeCartas[0] = As;
	barajaDeCartas[1] = J;
	barajaDeCartas[2] = Q;
	barajaDeCartas[3] = K;
	barajaDeCartas[4] = Nueve;
	barajaDeCartas[5] = Ocho;
	barajaDeCartas[6] = Siete;
	barajaDeCartas[7] = Seis;
	barajaDeCartas[8] = Cinco;
	barajaDeCartas[9] = Cuatro;
	barajaDeCartas[10] = Tres;
	barajaDeCartas[11] = Dos;
	tamUtil = 12;
}

Carta Baraja::getCarta(int indice){
	Carta carta = barajaDeCartas[indice];
	return carta;
}
int Baraja::getUtilizadas(){
	return tamUtil;
}

void Baraja::eliminarCarta(int indice){
	std::cout << "La carta " << barajaDeCartas[indice].getNombre() << " se ha terminado.";
	for (int i = indice; i < tamUtil - 1; i++){
		barajaDeCartas[i] = barajaDeCartas[i + 1];
	}
	tamUtil--;
	if(tamUtil == 0){
		std::cout << "\nLa baraja se ha terminado, enseguida la cambiamos.\n";
		rellenar();
	}
}
void Baraja::cartaVacia(int indice){
	if(barajaDeCartas[indice].getCantidad() == 0){
		eliminarCarta(indice);
	}
}
void Baraja::cartaUsada(int indice){
	barajaDeCartas[indice].usarCarta();
	cartaVacia(indice);
}
