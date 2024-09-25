#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

int x,y;
int locx = 15, locy =5;
int m,n,l,o,p;
int t,t1=1;
int Game_over=0;
int loop,move;
/*locx locy = are x and y coordinates of player assigning the initial position of player
  l,m,n,o,p = variables for defining the gap between the obstacle
  x,y = variables to create the map or matrix for printing
  t = y coordinate of obstacle
  Game_over = to defing the and check the game is over or not
              the game runs till the value of game over is 0
              when it sets to 1 it breaks the all loop game is considered to be ended
  t1 = time in srand command
  loop = this variable defines the repetition of the function in main code
  move = variable for movement of player
*/




/*defining the function to check if game is over or not */
/*if the coordinate of player which are locx and locy are matched
     to the coordinate of borders which are x = 0 & 29
  or the locx and locy are not matched with any coordinate of
     gaps in obstacle which are for x l,m,n,o,p and for y=t
  than the game is consider to be over and value of game over set to 1
*/
void Gameover()
{
    if ((locy==t)&&(locx!=m)&&(locx!=l)&&(locx!=n)&&(locx!=o)&&(locx!=p))
    {
        Game_over = 1;
    }
    else if((0==locx)||(29==locx))
     {
         Game_over = 1;
     }

}

/*defining the function to print the map */
void map()
{
  /*first of all defining the x and y plane
  with for loop and by using the coordinates
  of x y plane printing the whole map as
  per the requirement */
  for (y=0;y<20;y++)
  {

      for(x=0;x<30;x++)
      {
          Gameover();
         if(Game_over==1)
          {
              system("cls");
              break;
          }
          /*runs the game over command to check if the game is over or not*/
          /*if game is over than clear the screen and breaks the for loop and exit from map function*/

          else if((0==x)||(29==x))
          {
              printf("##");
          }
          /*printing the boarders of map with ## sign*/
          else if ((t == y)&&(x!= m)&&(x!= l)&&(x!= n)&&(x!= o)&&(x!= p))
          {
              printf("##");
          }
          /*printing the obstacle with random gaps in which the
          'm' is the randomly selected no and 'n' and 'l' are
          'm+1' and 'm-1' respectively */
          else if((locx==x)&&(locy==y))
          {
              printf("00");
          }
          /*printing layer location which is defined as 'locx' and
           'locy' in x and y coordinates*/
          else
          {
              printf("  ");
          }
      }
      printf("\n");
      /*at the end of x for loop new line gets started*/
  }
}

/*command to check the user input for the movement of player*/
/*by calling this command user input is taken

1.this command first checks if the user have given
  some input with the help of kbhit command
  kbhit it check the the console for a recent keystroke
2.if user have given some input than to check the
  input given by user getch command is used
3.if the entered value is a than the 1 is assign to
  move variable
  if the entered value is d than 2 is assign to
  move variable
  if x is entered by user than the gameover set to 1

to perform these operation switch case is used
which evaluate the  given expression and executes the statement
associated with it which are the given 3 cases in this code
if any other than these 3 character is entered it does not
perform any operation
*/
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
      case 'a':
        move = 1;
        break;

      case 'd':
        move = 2;
        break;

      case 'x':
        Game_over = 1;
        break;
        }
    }
}

/*command for the movement of player as per the input given by the user*/
/*
this command is dependent on input command
1.First delays execution of code for 100 ms with sleep command
  which makes the game playable
2.If the value of variable move is 1 than it
  decreasing the the locx (x coordinate of player) by 1
  if the value of move variable is 2 than it increases
  locx value by 1

this command run till the value of move changes
*/
void movement()
{

    Sleep(100);
    switch (move)
    {
    case 1 :
       locx--;
       break;
    case 2:
       locx++;
       break;
    }

}


void main()
{
    int score=-1;/*to calculate the score of player it starts from -1 because
                   it gets incremented at start of game to zero */
    while (Game_over!=1)//the loop will run till the game is over
{
    srand ( (unsigned) time (&t1));
    m = rand() % 24 + 3;
    n= m+1;
    l=m-1;
    o=m+2;
    p=m-2;
    t=19;
    score++;//increments the score when 1 obstacle is passed completely
    /*defining the gap between the obstacle with then help
    of rand and srand command 1 no is selected randomly
    between 3 to 27 and the no assign to m variable
    the coordinates consecutive to the m are assign to
    l,n,o,p, and the gap of is created
    t is the obstacle starting coordinate on y axis */

for(loop=0;loop<20;loop++)
 {
     map();
     input();
     movement();
     system("cls");
     t--;

     if(1==Gameover)
     {
         break;
     }
 }
/*the commands are arranged in for loop the loop variable starts from 0
and increment till 20 the loop is repeated 20 time
after that the gap in obstacle changes and the obstacles
y coordinate resets to 19
1.map is printed on screen
2.checks for user input
3.update the position of player as per the input
4.clears the screen and reduce the value of t which is
  the y coordinate of obstacle
5.checks if game is over or not if yes than breaks the loop
*/



 if(1==Gameover)
     {
         break;
     }

}


printf("GAME OVER\n");
printf("score %d\n", score);
/*when the game gets over score and game over gets printed on screen*/


}
