#include <iostream>
#include <cstdlib>
#include <iterator>

using namespace std;

class Carta{
	private:
		int valor;
		int cantidad;
		string Nombre;
	public:
		Carta(){
		}
		Carta(int Valor, string nombre){
			valor = Valor;
			Nombre = nombre;
		}

		string getNombre(){
			return Nombre;
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
		bool ganador;
		string Nombre;
	public:
		Jugador(){
			victorias = 0;
		}
		void setNombre(string nombre){
			Nombre = nombre;
		}
		string getNombre(){
			return Nombre;
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
		bool getGanador(){
			return ganador;
		}

		void ganar(){
			ganador = true;
		}
		void jugar(){
			ganador = false;
			jugando = true;
			valorTotal = 0;
		}
		void terminarRonda(){
			jugando = false;
		}
		void sumarValor(int valor){
			valorTotal += valor;
			if(valorTotal >= 21){
				terminarRonda();
			}
		}
		void sumarVictoria(){
			victorias++;
		}
		};

class Baraja{
	private:
		static const int TAM = 12;
		Carta barajaDeCartas[TAM];
		int tamUtil;
	public:
		Baraja(){
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
		}

		Jugador getJugador(int indice){
			return listaDeJugadores[indice];
		}
		int getNumeroJugadores(){
			return numeroJugadores;
		}
		bool getTerminado(){
			return terminado;
		}
		void Terminar(){
			terminado = true;
		}

		// Comprobar para eliminar.
		void eliminarJugador(int indice){
			for (int i = indice; i < numeroJugadores; i++){
				listaDeJugadores[i] = listaDeJugadores[i + 1];
			}
			numeroJugadores--;
		}
		void iniciarRonda(){
			terminado = false;
			for (int i = 0; i < numeroJugadores; i++){
				listaDeJugadores[i].jugar();
			}
		}
		void decirPuntuacion(int indice){
			cout << listaDeJugadores[indice].getNombre() <<
				", tienes: " << listaDeJugadores[indice].getValor() << " Puntos.\n";
		}
		void elegirGanador(){
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
		void definirJugadores(){
			int numJugadores;
			Jugador a, b, c, d, e, f, g, h, i, j;
			Jugador listaJug[TAM] = {a, b, c, d, e, f, g, h, i, j};
			do{
			cout << "Introduzca el número de jugadores que van a participar (Máximo 10, Minimo 2):\n";
			cin >> numJugadores;
			}while(numJugadores < 2 || numJugadores > 10);
			numeroJugadores = numJugadores;
			for(int i = 0; i < numJugadores; i++){
				listaDeJugadores[i] = listaJug[i];
			}
			for(int i = 0; i < numeroJugadores; i++){
				string nombre;
				cout << "Introduzca el nombre del jugador " << i + 1 << endl;
				cin >> nombre;
				listaDeJugadores[i].setNombre(nombre);
			}
		}

		bool continuar(int indice){
			int decision = 0;
			do{
				decirPuntuacion(indice);
				cout << "Desea coger más cartas?\n 1) Si.\n 2) No.\n";
				cin >> decision;
			}while(decision < 1 || decision > 2);
			if(decision == 1){
				return true;
			}
			else{
				return false;
			}
		}

		int numeroDeGanadores(){
			int Ganadores = 0;
			for (int i = 0; i < numeroJugadores; i++){
				if(listaDeJugadores[i].getGanador()){
					Ganadores++;
				}
			}
			return Ganadores;
		}

		void devolverGanadores(){
			elegirGanador();
			int numGanadores = numeroDeGanadores();
			if(numGanadores == 0){
				cout << "No ha ganado nadie.";
			}
			else if (numGanadores == 1){
				cout << "El ganador es: \n";
			}
			else{
				cout << "Los ganadores son: \n";
			}
			for (int i = 0; i < numeroJugadores; i++){
				if(listaDeJugadores[i].getGanador()){
					cout << listaDeJugadores[i].getNombre() << endl;
					listaDeJugadores[i].sumarVictoria();
				}
			}
		}

		int sacarCarta(){
			int carta = (rand() % baraja.getUtilizadas());
			return carta;
		}

		bool jugada(int i){
			if(listaDeJugadores[i].getJugando()){
				if(continuar(i)){
					int carta = sacarCarta();
					int valorCarta = baraja.getCarta(carta).getValor();
					baraja.cartaUsada(carta);
					if(valorCarta == 11 && listaDeJugadores[i].getValor() + 11 > 21){
						valorCarta = 1;
					}
					listaDeJugadores[i].sumarValor(valorCarta);
					cout << "Ha salido un " << baraja.getCarta(carta).getNombre()
						<< ", por lo que te sumas " << valorCarta << " puntos.\n\n";
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
};
int main(){
	srand((unsigned) time(0));
	Juego juego;
	juego.definirJugadores();
	juego.iniciarRonda();
	bool terminar = false;
	while(!terminar){
		for (int j = 0; j < 100; j++){
			cout << endl;
		}
		for(int i = 0; i < juego.getNumeroJugadores(); i++){
				cout << juego.getJugador(i).getNombre() << ": " <<
				juego.getJugador(i).getVictorias() << " Victorias.\n";
		}
		while(!juego.getTerminado()){
			int jugadas = 0;
			bool jugando = false;
			for (int i = 0; i < juego.getNumeroJugadores(); i++){
				jugando = juego.jugada(i);
				if(jugando){
					jugadas++;
				}
			}
			if(jugadas == 0){
				juego.Terminar();
			}
		}
		juego.devolverGanadores();
		int aux = 0;
		do{
			cout << "\nTerminar el juego?\n 1) Si. \n 2) No.\n";
			cin >> aux;
		}while(aux < 1 || aux > 2);
		if (aux == 1){
			terminar = true;
		}
		else{
			juego.iniciarRonda();
		}
	}
}
