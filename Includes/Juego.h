#include "Baraja.h"
#include "Jugador.h"
#ifndef _JUEGOH_
#define _JUEGOH_

class Juego{
	private:
		bool terminado;
		int rondas = 0;
		static const int TAM = 12;
		int numeroJugadores;
		Baraja baraja;
		Jugador listaDeJugadores[TAM];

	public:
		Juego();

		Jugador getJugador(int indice);

		int getNumeroJugadores();

		bool getTerminado();

		void Terminar();

		void iniciarRonda();

		void decirPuntuacion(int indice);

		void elegirGanador();

		void devolverGanadores();

		void definirJugadores();

		void desarrolloDeLaRonda();

		bool finalizarPartida();

		bool continuar(int indice);

		bool jugada(int i);

		int numeroDeGanadores();

		int decisionBanca();

		int sacarCarta();
};

#endif
