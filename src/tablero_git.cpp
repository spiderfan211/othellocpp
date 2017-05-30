#include "tablero.h"
#include <iostream>
using namespace std;

	Tablero::Tablero(int nfilas, int ncolumnas): tablero(nfilas, ncolumnas)
	{
		turno = 1;
		
		tablero.Modifica(nfilas/2, ncolumnas/2, 1);
		tablero.Modifica(nfilas/2, ncolumnas/2 + 1, 2);
		tablero.Modifica(nfilas/2 + 1, ncolumnas/2, 2);
		tablero.Modifica(nfilas/2 + 1, ncolumnas/2 + 1, 1);
		fin == false;
	}

	int Tablero::Filas()
	{
		return tablero.Filas();
	}

	int Tablero::Columnas()
	{
		return tablero.Columnas();
	}

	int Tablero::Contenido(int fila, int columna)
	{
		return tablero.Elemento(fila, columna);
	}

	bool Tablero::Finalizada()
	{
		return fin;
	}

	int Tablero::TurnoActual()
	{
		return turno;
	}

	void Tablero::CambioTurno()
	{
		if (Finalizada() == false)
			if(turno == 1)
				turno = 2;
			else
				turno = 1;
	}

	void Tablero::AcabarPartida()
	{
		fin == true;
	}

	int Tablero::Ganador()
	{
		if(fin == true)
			if(Puntuacion(1) == Puntuacion(2))
				return 0;
			else if(Puntuacion(1) > Puntuacion(2))
				return 1;
			else
				return 2;
	}

	int Tablero::Puntuacion(int num_jugador)
	{
		int fichas = 0;

		if(Finalizada() == true)
			for(int i = 0; i < Filas(); ++i){
				for(int j = 0; j < Columnas(); ++j){
					if (Contenido(i,j) == num_jugador)
						fichas++;
				}
			}
			return fichas;
	}

	bool Tablero::PosValida(int fila, int columna)
	{
		int fils;
		bool valido = false;

cout << "1" << endl;
		for(int i = -1; i < 1 || valido != true; ++i){
cout << "2" << endl;
			for(int j = -1; j < 1 || valido != true; ++j){
cout << "3" << endl;
				if(Contenido(fila + i,columna + j) == 2){
cout << "4" << endl;
					if(i == -1){
cout << "5" << endl;
						fils = fila + i - 1;

						if(j == -1){
							for(int k = columna + j - 1; (k >= 0 && fils >= 0) || (Contenido(fils,k) != turno || Contenido(fils,k) != 0) || valido != true; --k){
								if(Contenido(fils,k) == turno)
									valido == true;
								fils--;
									cout << "a" << endl;
							}cout << "b" << endl;
						}

						if (j == 0){
							for(int k = fils; k >= 0 || (Contenido(k, columna) != turno || Contenido(k, columna) != 0) || valido != true; --k){
								if(Contenido(k,columna) == turno)
									valido == true;
									cout << "c" << endl;
							}cout << "d" << endl;
						}
						if (j == 1){
							for(int k = columna + j + 1; (k < Columnas() && fils >= 0) || (Contenido(fils,k) != turno || Contenido(fils,k) != 0) || valido != true; ++k){
								if(Contenido(fils,k) == turno);
									valido == true;
								fils--;
									cout << "e" << endl;
							}cout << "f" << endl;
						}
					}
					if(i == 0){
						if(j == -1){
							for(int k = columna + j - 1; k >= 0 || (Contenido(fila,k) != turno || Contenido(fila, k) != 0) || valido != true; --k){
								if(Contenido(fila,k) == turno)
									valido == true;
								cout << "g" << endl;
							}cout << "h" << endl;
						}
						if(j == 1){
							for(int k = columna + j + 1; k < Columnas() || (Contenido(fila,k) != turno || 										Contenido(fila,k) != 0) || valido != true; ++k){
								if(Contenido(fila,k) == 1)
									valido == true;
									cout << "i" << endl;
							}cout << "j" << endl;
						}
					}
					if(i == 1){
						fils = fila + i + 1;
						if(j == -1){
							for(int k = columna + j - 1; (k >= 0 && fils < Filas()) || Contenido(fils,k) != turno || Contenido(fils,k) != 0 || valido != true; --k){
								if(Contenido(fils,k) == turno)
									valido == true;
								fils++;
cout << "k" << endl;
							}cout << "l" << endl;
						}
						if(j == 0){
							for(int k = fils; k < Filas() || (Contenido(k,columna) != turno || Contenido(k,columna) != 0) || valido != true; ++k){
								if(Contenido(k,columna) == turno)
									valido == true;
cout << "m" << endl;
							}cout << "n" << endl;
						}
						if(j == 1){
							for(int k = columna + j + 1; (k < Columnas() && fils < Filas()) || (Contenido(fils,k) != turno || Contenido(fils,k) != 0) || valido != true; ++k){
								if(Contenido(fils,k) == turno)
									valido == true;
								fils++;
cout << "o" << endl;
							}cout << "p" << endl;
						}
					}
				}
			}
		}

		return valido;	
	}

	bool Tablero::MovPosible()
	{
		bool mov_posible = false;
			
		for(int i = 0; i < Filas() || mov_posible != true; ++i){
			for(int j = 0; j < Columnas() || mov_posible != true; ++j){
				if(Contenido(i,j) == 0){
					cout << "b" << endl;
					mov_posible = PosValida(i,j);
					cout << "c" << endl;
				}
			}
		}

		return mov_posible;
	}

	void Tablero::Coloca(int fila, int columna)
	{
		if(turno == 1 && PosValida(fila, columna) == true && fila < Filas() && columna < Columnas()){
			tablero.Modifica(fila, columna, turno);
			CambioTurno();
		}
		else if(turno == 2 && PosValida(fila, columna) == true && fila < Filas() && columna < Columnas()){
			tablero.Modifica(fila, columna, turno);
			CambioTurno();
		}

		if(MovPosible() == false){
			CambioTurno();
				
			if(MovPosible() == false)
				AcabarPartida();
		}			
	}

	void Tablero::VaciaTablero()
	{
		if(fin == true){
			for(int i = 0; i < Filas(); ++i){
				for(int j = 0; j < Columnas(); ++j)
					tablero.Modifica(i,j,0);
			}
		}

		tablero.Modifica((Filas())/2, (Columnas())/2, 1);
		tablero.Modifica((Filas())/2, (Columnas())/2 + 1, 2);
		tablero.Modifica((Filas())/2 + 1, (Columnas())/2, 2);
		tablero.Modifica((Filas())/2 + 1, (Columnas())/2 + 1, 1);
		fin == false;
	}
	void Tablero::PrettyPrint()
	{
		for(int i = 0; i < Filas(); ++i){
			cout << i << " ";
			for(int j = 0; j < Columnas(); ++j){
				if(Contenido(i,j) == 0)
					cout << "| ";
				if(Contenido(i,j) == 1)
					cout << "|x";
				if(Contenido(i,j) == 2)
				cout << "|o";
			}
			cout << "|" << endl;
		}
	}
