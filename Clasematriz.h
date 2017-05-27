#include<fstream>
using namespace std;
 class Matriz {
 private:
   int filas, columnas;
   new int matriz[10][10]; //matriz fija 10x10

 public:

   Matriz(int fils, int cols);

   int GetFilas ();

   int GetColumnas();


   int GetElemento(int f, int c);


   void SetElemento(int f, int c, int& elem);

 }
