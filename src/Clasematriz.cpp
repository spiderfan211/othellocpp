#include "Clasematriz.h"
using namespace std;
   Matriz::Matriz(){
     Matriz(10,10);
   };
   Matriz::Matriz( Matriz &m){   //CAMBIAR CUANDO MEMORIA DINAMICA
     filas = m.GetFilas();
     columnas = m.GetColumnas();
     for (int i = 0; i < filas; i++) {
       for (int j = 0; j< columnas; j++)
        matriz[i][j] = m.GetElemento(i,j);
     }
   };
   Matriz::Matriz(int fils, int cols){   //CAMBIAR CUANDO MEMORIA DINAMICA
     bool aux = (fils  * cols <=  100) && (fils >=  4) && (cols >= 4);
     if (aux){
       filas=fils;
       columnas=cols;
       for (int i = 0; i < fils; i++) {
         for (int j = 0; j < cols; j++)
          matriz[i][j]=0;
       }
     }
   };

   Matriz::~Matriz(){     //CAMBIAR CUANDO MEMORIA DINAMICA
     for (int i = 0; i < filas; i++) {
       for (int j = 0; j< columnas; j++)
        matriz[i][j] = 0;
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


   void Matriz::SetElemento(int f, int c, int elem){
     matriz[f][c]=elem;
   };
