#include "Clasematriz.h"
using namespace std;
   Matriz::Matriz(){
     filas = 0;
     columnas = 0;
     //for (int i = 0; i < filas * columnas; i++) {
     // matriz[i][j]=0;
     //}
     //matriz[fils/2][cols/2] = 1;
     //matriz[fils/2+1][cols/2+1] = 1;
     //matriz[fils/2+1][cols/2] = 2;
     //matriz[fils/2][cols/2+1] = 2;
   }
   Matriz::Matriz( Matriz &m){   //CAMBIAR CUANDO MEMORIA DINAMICA
     filas = m.GetFilas();
     columnas = m.GetColumnas();
     for (int i = 0; i < filas; i++) {
       for (int j = 0; j< columnas; j++)
        matriz[i][j] = m.GetElemento(i,j);
     }
   }
   Matriz::Matriz(int fils, int cols){   //CAMBIAR CUANDO MEMORIA DINAMICA
     filas=fils;
     columnas=cols;
     bool aux = fils  * cols <  100;

     if (aux){
       for (int i = 0; i < fils; i++) {
         for (int j = 0; j< cols; j++)
          matriz[i][j]=0;
       }
       matriz[fils/2][cols/2] = 1;
       matriz[fils/2+1][cols/2+1] = 1;
       matriz[fils/2+1][cols/2] = 2;
       matriz[fils/2][cols/2+1] = 2;
     }
   };

   Matriz::~Matriz(){     //CAMBIAR CUANDO MEMORIA DINAMICA
     for (int i = 0; i < filas; i++) {
       for (int j = 0; j< columnas; j++)
        matriz[i][j] = 0;
     }
   }


   int Matriz::GetFilas (){                                                           //no estoy seguro del uso del flujo ostream aquí
     return filas;
   };


   int Matriz::GetColumnas(){
     return columnas;
   };


   int Matriz::GetElemento(int f, int c){
     return matriz[f][c];
   };


   void Matriz::SetElemento(int f, int c, int elem){
     matriz[f][c]=elem;
   };
