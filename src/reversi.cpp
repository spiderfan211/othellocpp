#include "Jugador.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	string titulo = "REVERSI v1.0",
	msg_tablero = "Introduzca el tamaño del tablero que desea de esta forma -> (fila,columna): ",
	msg_j1 = "Introduzca el nombre del jugador 1: ",
	msg_j2 = "Introduzca el nombre del jugador 2: ",
	msg_sin_mov = "No hay más movimientos disponibles, se acabó la partida.",
	msg_punt = "Puntuación final: ",
	msg_ganador = "El ganador es ",
	msg_empate = "Ha habido un empate.",
	msg_jugar_nueva = "¿Desea jugar de nuevo? (s/n): ",
	msg_error = "Debes introducir un valor correcto",
	msg_resultados = "Resultados hasta el momento: ",
	msg_columna = "Introduzca columna";

	const int MAX_NOMBRE = 50;
	char jugador1[MAX_NOMBRE], jugador2[MAX_NOMBRE];
	char letra, respuesta;
	int fila, columna, turno_actual, ganador, jugadas = 1, mov_invalido = 0;
	bool jugar, error;


	cout << titulo << endl;
	cout << msg_tablero;
	do{
		cin >> letra >> fila >> letra >> columna >> letra;
		error = ((fila < 4) || (fila > 10) || (columna < 4) || (columna > 10));
		if (error)
			cout << msg_error;
	}while( error );
	Tablero tablero(fila, columna);

	int** v;

	v = new int*[fila];     //Testeado memoria dinámica
	for(int i = 0; i < fila; i++)
		v[i] = new int[columna];





	int util_jugador1 = 0;
	int util_jugador2 = 0;
	int puntuacion_jugador1 = 0;
	int puntuacion_jugador2 = 0;
	int ganadas_jugador1 = 0;
	int ganadas_jugador2 = 0;

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




	int prueba = tablero.PosValida(v);














	do{
		mov_invalido = 0;		//para evitar el bucle infinito
		do{
				if(!tablero.IsFinalizada())	//I THINK SO
					tablero.ImprimeTablero();
				int c = 0;
				int f = 0;
				turno_actual = tablero.GetTurno();
				if(tablero.MovPosible(v) == true){
				 cout << "Turno de ";
	 			 if(turno_actual == 1){
					 mov_invalido = 0;
	 				 jugador_1.ImprimeNombre();
	 				 cout << endl << msg_columna;
	 				 cin >> c;
	 				 f = jugador_1.EscogePosicion(c, tablero, v);
	 				 tablero.Coloca(f,c); 		//???

	 			 }

	 			 else{
					 mov_invalido = 0;
	 			 	 jugador_2.ImprimeNombre();
	 				 cout << endl << msg_columna;
	 				 cin >> c;
	 				 f = jugador_2.EscogePosicion(c, tablero, v);
	 				 tablero.Coloca(f,c);			//???

				 }
				}

				else{
				 mov_invalido++;
				 if(mov_invalido == 2)
				  tablero.AcabarPartida();
	      }
				tablero.CambioTurno();
			}while(tablero.IsFinalizada() == false);

		if(tablero.IsFinalizada() == true){
				cout <<msg_sin_mov << endl;
				cout << msg_punt << endl;
				jugador_1.ImprimeNombre();
				tablero.PuntuacionTotal();
				cout << ": " << jugador_1.GetPuntuacion(tablero) << " puntos." << endl;
				puntuacion_jugador1 += jugador_1.GetPuntuacion(tablero);

				jugador_2.ImprimeNombre();
				cout << ": " << jugador_2.GetPuntuacion(tablero) << " puntos." << endl;
				puntuacion_jugador2 +=jugador_2.GetPuntuacion(tablero);

				ganador = tablero.GetGanador();

				if(ganador == 0)
					cout << msg_empate << endl;

				else if(ganador == 1){
					cout << msg_ganador;
					jugador_1.ImprimeNombre();
					cout << "." << endl;
					ganadas_jugador1++;
				}

				else{
					cout << msg_ganador;
					jugador_2.ImprimeNombre();
					cout << "." << endl;
					ganadas_jugador2++;
				}

				cout << msg_resultados << endl;
				jugador_1.ImprimeNombre();
				cout << ": " << ganadas_jugador1 << " ganadas de " << jugadas << " partidas jugadas con " << puntuacion_jugador1 << " puntos." << endl;

				jugador_2.ImprimeNombre();
				cout << ": " << ganadas_jugador2 << " ganadas de " << jugadas << " partidas jugadas con " << puntuacion_jugador2 << " puntos." << endl;

				cout << msg_jugar_nueva;
				cin >> respuesta;
				do{
					if(respuesta == 'n' || respuesta == 'N'){
						jugar = false;
						error = false;
					}
					else if (respuesta == 's' || respuesta == 'S'){
						jugar = true;
						error = false;
						tablero.Vacia();
						jugadas++;
					}
					else{
						error = true;
						cout << msg_error << endl;
					}
				} while(error);
		}
	}while(jugar != false);

	for(int i = 0; i < fila; i++){
			delete[] v[i];
	}
	delete[] v;
}
