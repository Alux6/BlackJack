#include "Carta.h"
#ifndef _BARAJAH_
#define _BARAJAH_
class Baraja{
	private:
		static const int TAM = 12;
		Carta barajaDeCartas[TAM];
		int tamUtil;

	public:

		Baraja();

		void rellenar();

		Carta getCarta(int indice);

		int getUtilizadas();

		void eliminarCarta(int indice);

		void cartaVacia(int indice);

		void cartaUsada(int indice);

};

#endif
