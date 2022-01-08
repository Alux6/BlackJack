#include "Baraja.h"
#include "Jugador.h"
#ifndef _JUEGOH_
#define _JUEGOH_

class Juego{
	private:
		static const int TAM = 12;
		Baraja baraja;
		Jugador listaDeJugadores[TAM];
		int numeroJugadores;
		int rondas = 0;
		bool terminado;

	public:
		Juego();

		Jugador getJugador(int indice);

		int getNumeroJugadores();

		bool getTerminado();

		bool continuar(int indice);

		void decirPuntuacion(int indice);

		int decisionBanca();

		void definirJugadores();

		void desarrolloDeLaRonda();

		void devolverGanadores();

		void elegirGanador();

		bool finalizarPartida();

		void iniciarRonda();

		bool jugada(int i);

		int numeroDeGanadores();

		int sacarCarta();

		void Terminar();
};

#endif
