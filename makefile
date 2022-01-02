BlackJack.run: main.cpp Juego.cpp Jugador.cpp Baraja.cpp Carta.cpp
	g++ -o BlackJack.run $^ -I./Includes
