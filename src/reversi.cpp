#include <iostream>
#include<string>
#include "Jugador.h"
using namespace std;

int main(){
	string titulo = "REVERSI v1.0"
	string msg_tablero = "Introduzca el tamaño del tablero que desea de esta forma -> (fila,columna): ";
	string msg_j1 = "Introduzca el nombre del jugador 1: ";
	string msg_j2 = "Introduzca el nombre del jugador 2: ";
	string msg_sin_mov = "No hay más movimientos disponibles, se acabó la partida.";
	string msg_punt = "Puntuación final: ";
	string msg_ganador = "El ganador es ";
	string msg_empate = "Ha habido un empate.";
	string msg_jugar_nueva = "¿Desea jugar de nuevo? (s/n): ";
	string msg_error = "Debes introducir un valor correcto";
	string msg_resultados = "Resultados hasta el momento: ";

	const int MAX_NOMBRE = 50;
	char jugador1[MAX_NOMBRE], jugador2[MAX_NOMBRE];
	char letra, respuesta;
	int fila, columna, turno_actual, ganador,
		util_jugador1, util_jugador2,
		jugadas, ganadas_jugador1, ganadas_jugador2,
		puntuacion_jugador1, puntuacion_jugador2;
	bool jugar = true, error = false;

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
			turno_actual = tablero.GetTurno();

			cout << "Turno de ";
			if(turno_actual == 1)
				jugador_1.ImprimeNombre();
				cout << endl;
				jugador_1.EscogePosicion(tablero);

			else
				jugador_2.ImprimeNombre();
				cout << endl;
				jugador_2.EscogePosicion(tablero);

		}while(tablero.IsFinalizada() != false);

		if(tablero.Finalizada() == true){
				cout <<msg_sin_mov << endl;
				cout << msg_punt << endl;
				jugador_1.NombreJugador();
				cout << ": " << jugador_1.PuntuacionJugador(tablero) << " puntos." << endl;
				puntuacion_jugador1 += jugador_1.PuntuacionJugador(tablero);

				jugador_2.NombreJugador();
				cout << ": " << jugador_2.PuntuacionJugador(tablero) << " puntos." << endl;
				puntuacion_jugador2 +=jugador_2.PuntuacionJugador(tablero);

				ganador = tablero.GetGanador();

				if(ganador == 0)
					cout << msg_empate << endl;

				else if(ganador == 1){
					cout << msg_ganador;
					jugador_1.NombreJugador();
					cout << "." << endl;
					ganadas_jugador1++;
				}

				else{
					cout << msg_ganador;
					jugador_2.NombreJugador();
					cout << "." << endl;
					ganadas_jugador2++;
				}

				cout << msg_resultados << endl;
				jugador_1.NombreJugador();
				cout << ": " << ganadas_jugador1 << " ganadas de " << jugadas << " partidas jugadas con " << puntuacion_jugador1 << " puntos." << endl;

				jugador_2.NombreJugador();
				cout << ": " << ganadas_jugador2 << " ganadas de " << jugadas << " partidas jugadas con " << puntuacion_jugador2 << " puntos." << endl;

				cout << msg_jugar_nueva;
				cin >> respuesta;
				do{
					if(respuesta == 'n' || respuesta == 'N')
						jugar = false;
						error = false;
					else if (respuesta == 's' || respuesta == 'S'){
						error = false;
						tablero.VaciaTablero();
						jugadas++;
					}
					else{
						error = true;
						cout << msg_error << endl;
					}
				} while(error);
		}
	}while(jugar != false);
}
