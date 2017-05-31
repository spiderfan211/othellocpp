#include <iostream>
#include<string>
#include "Jugador.h"
using namespace std;

int main(){
	string titulo = "REVERSI v1.0"
	string msg_tablero = "Introduzca el tamaño del tablero que desea de esta forma -> (fila,columna): ";
	string msg_j1 = "Introduzca el nombre del jugador 1: ";
	string msg_j2 = "Introduzca el nombre del jugador 2: ";

	const int MAX_NOMBRE = 50;
	char jugador1[MAX_NOMBRE], jugador2[MAX_NOMBRE];
	char letra, respuesta;
	int fila, columna, turno_actual, ganador,
		util_jugador1, util_jugador2,
		jugadas, ganadas_jugador1, ganadas_jugador2,
		puntuacion_jugador1, puntuacion_jugador2;
	bool jugar = true;

	cout << titulo << endl;
	cout << msg_tablero;
	cin >> letra >> fila >> letra >> columna >> letra;
	Tablero tablero(fila, columna);

	util_jugador1 = util_jugador2 = 0;
	puntuacion_jugador1 = puntuacion_jugador2 = 0;
	ganadas_jugador1 = ganadas_jugador2 = 0;

	cout << msg_j1;
	letra = cin.get();

	do{

		jugador1[util_jugador1] = letra;
		util_jugador1++;
		letra = cin.get();
	}while(letra != '\n' && util_jugador1 < MAX_NOMBRE);

	jugador1[util_jugador1] = '\0';

	Jugador jugador_1(jugador1, 1);

	cout << msg_j2;
	letra = cin.get();

	do{
		jugador2[util_jugador2] = letra;
		util_jugador2++;
		letra = cin.get();
	}while(letra != '\n' && util_jugador2 < MAX_NOMBRE);

	jugador2[util_jugador2] = '\0';

	Jugador jugador_2(jugador2, 2);



//


	do{
		do{
			turno_actual = tablero.TurnoActual();

			if(turno_actual == 1)
				jugador_1.EscogePosicion(tablero);

			else
				jugador_2.EscogePosicion(tablero);

		}while(tablero.Finalizada() != false);

		if(tablero.Finalizada() == true){
			cout << "No hay más movimientos disponibles, se acabó la partida." << endl;
			cout << "Puntuación final: " << endl;
			jugador_1.NombreJugador();
			cout << ": " << jugador_1.PuntuacionJugador(tablero) << " puntos." << endl;
			puntuacion_jugador1 += jugador_1.PuntuacionJugador(tablero);

			jugador_2.NombreJugador();
			cout << ": " << jugador_2.PuntuacionJugador(tablero) << " puntos." << endl;
			puntuacion_jugador2 +=jugador_2.PuntuacionJugador(tablero);

			ganador = tablero.Ganador();

			if(ganador == 0)
				cout << "Ha habido un empate." << endl;

			else if(ganador == 1){
				cout << "El ganador es ";
				jugador_1.NombreJugador();
				cout << "." << endl;
				ganadas_jugador1++;
			}

			else{
				cout << "El ganador es ";
				jugador_2.NombreJugador();
				cout << "." << endl;
				ganadas_jugador2++;
			}

			cout << "Resultados hasta el momento: " << endl;
			jugador_1.NombreJugador();
			cout << ": " << ganadas_jugador1 << " ganadas de " << jugadas << " partidas jugadas con " << puntuacion_jugador1 << " puntos." << endl;

			jugador_2.NombreJugador();
			cout << ": " << ganadas_jugador2 << " ganadas de " << jugadas << " partidas jugadas con " << puntuacion_jugador2 << " puntos." << endl;

			cout << "¿Desea jugar de nuevo? (s/n): ";
			cin >> respuesta;
			if(respuesta == 'n' || respuesta == 'N')
				jugar == false;

			else{
				tablero.VaciaTablero();
				jugadas++;
			}
		}
	}while(jugar != false);
}
