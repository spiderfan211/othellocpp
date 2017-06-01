void make_move(char board[][SIZE], int row, int col, char player)
{
   int rowdelta = 0;                   /* Row increment              */
   int coldelta = 0;                   /* Column increment           */
   int x = 0;                          /* Row index for searching    */
   int y = 0;                          /* Column index for searching */
   char opponent = (player == 'O')? '@' : 'O';  /* Identify opponent */

   board[row][col] = player;           /* Place the player counter   */

   /* Check all the squares around this square */
   /* for the opponents counter                */
   for(rowdelta = -1; rowdelta <= 1; rowdelta++)
     for(coldelta = -1; coldelta <= 1; coldelta++)
     {
       /* Don't check off the board, or the current square */
       if(row + rowdelta < 0 || row + rowdelta >= SIZE ||
          col + coldelta < 0 || col + coldelta >= SIZE ||
                               (rowdelta==0 && coldelta== 0))
         continue;

       /* Now check the square */
       if(board[row + rowdelta][col + coldelta] == opponent)
       {
         /* If we find the opponent, search in the same direction */
         /* for a player counter                                  */
         x = row + rowdelta;        /* Move to opponent */
         y = col + coldelta;        /* square           */

         for(;;)
         {
           x += rowdelta;           /* Move to the      */
           y += coldelta;           /* next square      */

           /* If we are off the board give up */
           if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
             break;

           /* If the square is blank give up */
           if(board[x][y] == ' ')
             break;

           /* If we find the player counter, go backwards from here */
           /* changing all the opponents counters to player         */
           if(board[x][y] == player)
           {
             while(board[x-=rowdelta][y-=coldelta]==opponent) /* Opponent? */
               board[x][y] = player;    /* Yes, change it */
             break;                     /* We are done    */
           }
         }
       }
     }
}
