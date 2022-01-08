#include <iostream>
#ifndef _JUGADORH_
#define _JUGADORH_

class Jugador{
	private:
		bool ganador;
		bool jugando;
		std::string Nombre;
		int valorTotal;
		int victorias;

	public:
		Jugador();

		std::string getNombre();

		int getValor();

		int getVictorias();

		bool getJugando();

		bool getGanador();

		void setNombre(std::string nombre);

		void ganar();

		void jugar();

		void sumarValor(int valor);

		void sumarVictoria();

		void terminarRonda();
};

#endif
