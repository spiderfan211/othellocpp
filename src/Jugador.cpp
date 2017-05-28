#include<iostream>
#include"Jugador.h"
using namespace std;
    //Jugador::Jugador(char* n){  //NOT SURE
    //  punt = 0;
    //  turno = 0;
    //INSERCIÓN DEL NOMBRE ¿¿??
    //}


   int Jugador::EscogePosicion(int c, Tablero& t){
     int n=0;
     int e[t.GetFils()];
     for(int i = 0; i < t.GetFils(); i++){
       if (t.PuedePoner(i, c)){
         e[i] = t.GetElem(i, c);
         n++;
       }
       if(n == 1){
         return e[0];
       }
       else{
         t.ImprimeTablero();
         int v = this->DialogoEscoger(n, e);    //Entrada de vector por referencia?o parametro
         return e[v];
       }
     }
   };
