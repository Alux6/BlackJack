
#include <cstdlib>
#include "Juego.h"
using namespace std;

int main(){
	Juego juego;
	juego.definirJugadores();
	juego.iniciarRonda();
	bool terminar = false;
	while(!terminar){
		juego.desarrolloDeLaRonda();
		juego.devolverGanadores();
		terminar = juego.finalizarPartida();
	}
}
