#include "Clasematriz.h"
using namespace std;
   Matriz::Matriz(){
     filas = 8;
     columnas = 8;
     for (int i = 0; i < filas * columnas; i++) {
       matriz[i][j]=0;
     }
     matriz[fils/2][cols/2] = 1;
     matriz[fils/2+1][cols/2+1] = 1;
     matriz[fils/2+1][cols/2] = 2;
     matriz[fils/2][cols/2+1] = 2;
   }
   Matriz::Matriz(int fils, int cols){
     filas=fils;
     columnas=cols;
     bool aux = fils  * cols <  100;

     if (aux){
       for (int i = 0; i < fils * cols; i++) {
         matriz[i][j]=0;
       }
       matriz[fils/2][cols/2] = 1;
       matriz[fils/2+1][cols/2+1] = 1;
       matriz[fils/2+1][cols/2] = 2;
       matriz[fils/2][cols/2+1] = 2;
     }
   };


   int Matriz::GetFilas (){                                                           //no estoy seguro del uso del flujo ostream aquí
     return filas;
   };


   int Matriz::GetColumnas(){
     return columnas;
   };


   int Matriz::GetElemento(int f, int c){
     return matriz[f][c];
   };


   void Matriz::SetElemento(int f, int c, int& elem){
     matriz[f][c]=elem;
   };
