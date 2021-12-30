#include <iostream>

using namespace std;

class Carta{
    private:
        int valor;
        int cantidad;
    public:
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

class Juego{
    private:
        bool terminado;
        int rondas = 0;
        int numeroJugadores;

    public:
        Juego(){
            numeroJugadores = 2;
        }
        Juego(int numJugadores){
            numeroJugadores = numJugadores;
        }


};
int main(){

}
