#ifndef _MATRIZH_
#define _MATRIZH_
 class Matriz {
 private:
   int filas, columnas;
   int matriz[10][10]; //matriz fija 10x10

 public:
   Matriz();

   Matriz(int fils, int cols);

   Matriz( Matriz &m);

   ~Matriz();

   int GetFilas ();

   int GetColumnas();


   int GetElemento(int f, int c);


   void SetElemento(int f, int c, int elem);

 };
#endif
