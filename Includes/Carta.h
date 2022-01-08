#include <iostream>

#ifndef _CARTAH_
#define _CARTAH_

class Carta{
	private:
		std::string NombreCarta;
		int cantidad;
		int valor;

	public:
		Carta();

		Carta(int Valor, std::string nombre);

		int getCantidad();

		int getValor();

		std::string getNombre();

		void usarCarta();
};

#endif
