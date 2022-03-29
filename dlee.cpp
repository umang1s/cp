#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
//#include <windows.h>
using namespace std;
class Sudoku
  {
    int board[9][9];
    int change[9][9];
    public:
    Sudoku(){ for(int i = 1; i <= 9; i++) for(int j = 1; j <= 9; j++) board[i][j] = 0;    }
    void Print_Board();
    void Add_First_Cord();
    void Solve();
    void Help_Solve(int i, int j);
    bool Check_Conflicts(int p, int i, int j);
  };
Sudoku Game;
void setcolor(unsigned short color)                 //The function that you'll use to
{                                                   //set the colour
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}
void Sudoku::Print_Board()
  {
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            if(change[i][j] == 1)
            {
                setcolor(10);
                cout << board[i][j] << " ";
                setcolor(7);
            }
            else cout << board[i][j] << " ";
            if(j%3 == 0) cout << "| ";
        }
        cout << endl;
        if(i%3 == 0) cout << "------+-------+---------" << endl;
    }

  }

void Sudoku::Add_First_Cord()

  {
      char i;
      for(int x=1; x<10; x++)
      {
            cout<<" Line : "<<x<<"  ";
            for(int y=1; y<10; y++) {cin>>i; if(i<58 && i>48) {board[x][y]=i-48; change[x][y]=1;} }
            cout<<" line completed "<<endl;
      }
      cout<<"you completed all board "<<endl;

  }

bool Sudoku::Check_Conflicts(int p, int i, int j)

  {

    for(int k = 1; k <= 9; k++)

      if(board[i][k] == p) return false;

    for(int q = 1; q <= 9; q++)

      if(board[q][j] == p) return false;

    /*

      *00

      000

      000

    */

    if((j == 1 || j == 4 || j == 7) && (i == 1 || i == 4 || i == 7))

      {

         if(board[i][j+1] == p || board[i][j+2] == p || board[i+1][j] == p ||

             board[i+2][j] == p || board[i+1][j+1] == p || board[i+1][j+2] == p ||

                 board[i+2][j+1] == p || board[i+2][j+2] == p)return false;

      }

    /*

      000

      000

      *00

    */

    if((j == 1 || j == 4 || j == 7) && (i == 3 || i == 6 || i == 9))

      {

         if(board[i-1][j] == p || board[i-2][j] == p || board[i][j+1] == p ||

             board[i][j+2] == p || board[i-1][j+1] == p || board[i-1][j+2] == p ||

                 board[i-2][j+1] == p || board[i-2][j+2] == p)return false;

      }

    /*

      000

      *00

      000

    */

    if((j == 1 || j == 4 || j == 7) && (i == 2 || i == 5 || i == 8))

      {

         if(board[i-1][j] == p || board[i+1][j] == p || board[i-1][j+1] == p ||

             board[i][j+1] == p || board[i+1][j+1] == p || board[i+1][j+2] == p ||

                 board[i][j+2] == p || board[i+1][j+2] == p)return false;

      }

    /*

      0*0

      000

      000

    */

    if((j == 2 || j == 5 || j == 8) && (i == 1 || i == 5 || i == 7))

      {

         if(board[i-1][j] == p || board[i+1][j] == p || board[i-1][j+1] == p ||

             board[i][j+1] == p || board[i+1][j+1] == p || board[i+1][j+2] == p ||

                 board[i][j+2] == p || board[i+1][j+2] == p)return false;

      }

    /*

      000

      0*0

      000

    */

    if((j == 2 || j == 5 || j == 8) && (i == 2 || i == 5 || i == 8))

      {

         if(board[i-1][j] == p || board[i-1][j-1] == p || board[i-1][j+1] == p ||

             board[i][j+1] == p || board[i][j-1] == p || board[i+1][j+1] == p ||

                 board[i][j] == p || board[i+1][j-1] == p)return false;

      }

    /*

      000

      000

      0*0

    */

    if((j == 2 || j == 5 || j == 8) && (i == 3 || i == 6 || i == 9))

      {

         if(board[i][j-1] == p || board[i][j+1] == p || board[i-1][j] == p ||

             board[i-1][j+1] == p || board[i-1][j-1] == p || board[i-2][j] == p ||

                 board[i-1][j+1] == p || board[i-2][j-1] == p) return false;

      }

    /*

      00*

      000

      000

    */

    if((j == 3 || j == 6 || j == 9) && (i == 1 || i == 4 || i == 7))

      {

         if(board[i][j-1] == p || board[i][j-2] == p || board[i+1][j] == p ||

             board[i+1][j-1] == p || board[i+1][j-2] == p || board[i+2][j] == p ||

                 board[i+2][j-1] == p || board[i+2][j-2] == p) return false;

      }

    /*

      000

      00*

      000

    */

    if((j == 3 || j == 6 || j == 9) && (i == 2 || i == 5 || i == 8))

      {

         if(board[i-1][j] == p || board[i-1][j-1] == p || board[i-1][j-2] == p ||

             board[i][j-1] == p || board[i][j-2] == p || board[i+1][j] == p ||

                 board[i+1][j-1] == p || board[i+1][j-2] == p) return false;

      }

    /*

      000

      000

      00*

    */

    if((j == 3 || j == 6 || j == 9) && (i == 3 || i == 6 || i == 9))

      {

         if(board[i][j-1] == p || board[i][j-1] == p || board[i-1][j] == p ||

             board[i-1][j-1] == p || board[i-1][j-2] == p || board[i-2][j] == p ||

                 board[i-2][j-1] == p || board[i-2][j-2] == p) return false;

      }

    return true;

  }

void Sudoku::Help_Solve(int i, int j)

  {

    if(j <= 0)

      {

        i = i-1;

        j = 9;

      }

    if(change[i][j] == 1) return Game.Help_Solve(i, j-1);

    for(int p = 1; p <= 9; p++)

      if(Game.Check_Conflicts(p, i, j))

        {

          board[i][j] = p;

          return;

        }

    return Game.Help_Solve(i, j-1);

  }

void Sudoku::Solve()

  {

      for(int i = 1; i <= 9; i++)

        {

          for(int j = 1; j <= 9; j++)

            {

              if(board[i][j] == 0 && change[i][j] == 0)

                {

                  Game.Help_Solve(i, j);

                }

            }

        }

      for(int i = 1; i <= 9; i++)

        for(int j = 1; j <= 9; j++)

          if(board[i][j] == 0) Game.Help_Solve(i, j);

  }

int main()

{

  Game.Add_First_Cord();

  Game.Solve();

  Game.Print_Board();

  system("pause");

  return 0;

}
