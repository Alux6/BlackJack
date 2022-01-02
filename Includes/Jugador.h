
#include <iostream>
#ifndef _JUGADORH_
#define _JUGADORH_

class Jugador{
	private:
		int victorias;
		int valorTotal;
		bool jugando;
		bool ganador;
		std::string Nombre;

	public:
		Jugador();

		void setNombre(std::string nombre);

		std::string getNombre();

		int getValor();

		int getVictorias();

		bool getJugando();

		bool getGanador();

		void ganar();

		void jugar();

		void terminarRonda();

		void sumarValor(int valor);

		void sumarVictoria();
};

#endif
