#include <iostream>

#ifndef _CARTAH_
#define _CARTAH_

class Carta{
	private:
		int valor;
		int cantidad;
		std::string NombreCarta;


	public:
		Carta();

		Carta(int Valor, std::string nombre);

		std::string getNombre();

		int getValor();

		int getCantidad();

		void usarCarta();
};

#endif
