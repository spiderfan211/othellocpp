#include <iostream>
#include "jugador.h"
using namespace std;

		void Jugador::DialogoEscoge(Tablero tablero)
		{
			tablero.PrettyPrint();

			cout << "Turno de ";
				if(tablero.TurnoActual() == turno_jugador){
					for(int k = 0; jugador[k] != '\0'; ++k)
						cout << jugador[k];
				}
			cout << ". Introduzca la posición en la que desea colocar la pieza: ";
		}

		Jugador::Jugador(char nom_jugador[], int num_jugador)
		{
			int util = 0;

			for(int i = 0; nom_jugador[i] != '\0' && i < 50; ++i){
				jugador[i] = nom_jugador[i];
				util = i;
			}

			nom_jugador[util + 1] = '\0';
			puntuacion = 0;
			turno_jugador = num_jugador;
		}
		
		void Jugador::NombreJugador()
		{
			for(int k = 0; jugador[k] != '\0'; ++k)
				cout << jugador[k];
		}

		int Jugador::TurnoJugador()
		{
			return turno_jugador;
		}

		int Jugador::PuntuacionJugador(Tablero tablero)
		{
			puntuacion = tablero.Puntuacion(turno_jugador);
			return puntuacion;
		}

		void Jugador::EscogePosicion(Tablero tablero)
		{
			int fila, columna;

			while(tablero.TurnoActual() == turno_jugador && tablero.Finalizada() != true){
				cout << "a" << endl;		
				if(tablero.MovPosible() == true){
					cout << "b" << endl;
					DialogoEscoge(tablero);
					cin >> fila;
					cin >> columna;

					do{
						DialogoEscoge(tablero);
						cin >> fila;
						cin >> columna;
					}while(tablero.PosValida(fila, columna) == false);
	
					if(tablero.PosValida(fila, columna) == true)
						tablero.Coloca(fila, columna);
				}
				else{
					cout << "No hay movimiento disponible, pierde el turno.";
					tablero.CambioTurno();
				}
			}
		}
