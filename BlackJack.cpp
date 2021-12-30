#include <iostream>
#include <cstdlib>
#include <iterator>

using namespace std;

class Carta{
	private:
		int valor;
		int cantidad;
	public:
		Carta(){
		}
		Carta(int Valor){
			valor = Valor;
		}

		int getValor(){
			return valor;
		}
		int getCantidad(){
			return cantidad;
		}

		void usarCarta(){
			cantidad--;
		}
};

class Jugador{
	private:
		int victorias;
		int valorTotal;
		bool jugando;
		bool banca;
	public:
		Jugador(){
			victorias = 0;
		}
		Jugador(bool banca){
			banca = true;
			victorias = 0;
		}
		int getValor(){
			return valorTotal;
		}
		int getVictorias(){
			return victorias;
		}
		bool getJugando(){
			return jugando;
		}

		void jugar(){
			jugando = true;
			valorTotal = 0;
		}
		void terminarRonda(){
			jugando = false;
		}
		void sumarValor(int valor){
			valorTotal += valor;
		}
		void sumarVictoria(){
			victorias++;
		}
		};

class Baraja{
	private:
		static const int TAM = 4;
		Carta barajaDeCartas[TAM];
		int tamUtil;
	public:
		Baraja(){
			Carta As(11), K(10), Q(10), J(10);
			barajaDeCartas[0] = J;
			barajaDeCartas[1] = Q;
			barajaDeCartas[2] = K;
			barajaDeCartas[3] = As;
			tamUtil = 4;
		}

		Carta getCarta(int indice){
			Carta carta = barajaDeCartas[indice];
			return carta;
		}
		int getUtilizadas(){
			return tamUtil;
		}

		void eliminarCarta(int indice){
			for (int i = indice; i < tamUtil; i++){
				barajaDeCartas[i] = barajaDeCartas[i + 1];
			}
			tamUtil--;
		}
		void cartaVacia(int indice){
			if(barajaDeCartas[indice].getCantidad() == 0){
				eliminarCarta(indice);
			}
		}
		void cartaUsada(int indice){
			barajaDeCartas[indice].usarCarta();
			cartaVacia(indice);
		}


};
class Juego{
	private:
		bool terminado;
		int rondas = 0;
		static const int TAM = 10;
		int numeroJugadores;
		Baraja baraja;
		Jugador listaDeJugadores[TAM];
	public:
		Juego(){
			numeroJugadores = 2;
		}
		Juego(int numJugadores){
			numeroJugadores = numJugadores;
		}

		void decirPuntuacion(int indice){
			cout << "Tienes: " << listaDeJugadores[indice].getValor() << " Puntos.";
		}

		bool continuar(int indice){
			int decision = 0;
			decirPuntuacion(indice);
			do{
				cout << "Desea seguir jugando?\n 1) Si.\n 2) No.";
			}while(decision != 1 || decision != 2);
			if(decision == 1){
				return true;
			}
			else{
				return false;
			}
		}

		int sacarCarta(){
			int carta = rand() % baraja.getUtilizadas();
			return carta;
		}

		void jugada(int i){
			if(listaDeJugadores[i].getJugando()){
				if(continuar(i)){
					int carta = sacarCarta();
					int valorCarta = baraja.getCarta(carta).getValor();
					listaDeJugadores[i].sumarValor(valorCarta);
				}
				else{
					listaDeJugadores[i].terminarRonda();
				}

			}

		}
};
int main(){

}
