void Tablero::Coloca(int f, int c)
{
   int f_inc = 0;                   /* Row increment              */
   int c_inc = 0;                   /* Column increment           */
   int x = 0;                          /* Row index for searching    */
   int y = 0;                          /* Column index for searching */

   /* Check all the squares around this square */
   /* for the opponents counter                */
   for(f_inc = -1; f_inc <= 1; f_inc++)
     for(c_inc = -1; c_inc <= 1; c_inc++)
     {
       /* Don't check off the board, or the current square */
       if(f + f_inc < 0 || f + f_inc >= SIZE
         || c + c_inc < 0 || c + c_inc >= SIZE
         || (f_inc==0 && c_inc== 0))
       {

       /* Now check the square */
       if(this->GetElemento(f + f_inc, c + c_inc) == this->TurnoContrario(){
         /* If we find the opponent, search in the same direction */
         /* for a player counter                                  */
         x = f + f_inc;        /* Move to opponent */
         y = c + c_inc;        /* square           */


        bool salir;
         do{
           salir = false;
           x += f_inc;           /* Move to the      */
           y += c_inc;           /* next square      */

           /* If we are off the board give up */
           if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
             salir = true;

           /* If the square is blank give up */
           if(this->GetElemento(x, y) == ' ')
             salir = true;

           /* If we find the player counter, go backwards from here */
           /* changing all the opponents counters to player         */
           if(this->GetElemento(x, y) == turno){
             salir = true
             while(this->GetElemento(x-=f_inc, y-=c_inc) == this->TurnoContrario()) /* Opponent? */
               this->GetElemento(x, y) = turno;    /* Yes, change it */
           }
         } while (!salir)
        }
      }
     }
}
