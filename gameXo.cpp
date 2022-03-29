//---------------------------<LIBARARIES>------------------------------------//
#include<iostream>
//#include <algorithm>
#include<windows.h>
//#include<stdio.h>
//#include<stdlib.h>
#include<conio.h>
#include<iomanip>
using namespace std;
//-----------------------<GLOBAL DATA>-----------------------------------------//

char p[10];//BLOCKS IN THE MATRIX
int move_no;//1-->5
int LoopCount=0;
char levels;// skills("Easy,Normal,Hard") //
char comp_move;// entery of the move of the computer //
char user_move;// entery of the move of the user //
char ch; // For "Yes" or "No" Answer //
char start;// To choose Skill level //
char MYname[25]="codemiles";

COORD where;// Position on the screen //
HANDLE hIn;// HANDLE OF INPUTS //
HANDLE hOut;// HANDLE OF OUTPUTS //
INPUT_RECORD InRec;
DWORD EventCount;
DWORD NumRead;

unsigned char HoldKey;
bool Continue = TRUE;
//-------------------------<FUNCTIONS  PROTOTYPES>-----------------------------//
int way1(char);
int incorrect(int);
int way2(int,char);
int recomend_move();
void Green(char win);
void swap(char&,char&);
void check_status();
int check_condition();
int check_condition2();
void Inlevel();
void MSI();
void setcolor(unsigned short color);
void MY_sign();

//-----------------------------<MAIN FUNCTION>--------------------------------------//
int main()
{
hIn= GetStdHandle(STD_INPUT_HANDLE);// Declaration of "hIn" Using "std"
hOut= GetStdHandle(STD_OUTPUT_HANDLE);// Declaration of "hOut"  "std"

         // MSI();// Print MY NAME //
          setcolor(15); //Changing Color //
          cout<<"\n\t\t\t\t________________";
          cout<<"\n\t\t\t\t        |\t\t\t\t  ";
          cout<<"\n_______________________________________/ \\______________________________________"<<endl;


      // PRINT OUT *** LINE //
    for(int h=0;h<80;h++)
    {
    cout<<'*';

    }
    cout<<endl;

    MY_sign();// FCI //

    cout<<endl<<endl;
    setcolor(1913);
    where.X=0;
    where.Y=0;
    SetConsoleCursorPosition(hOut,where);


    cout<<"      X           X                  OOOO"<<setw(18)<<endl; where.Y++;SetConsoleCursorPosition(hOut,where);
    cout<<"        X      X                   OOOO"<<setw(18)<<endl<<endl<<endl;
    setcolor(15);
    for( int h=0;h<80;h++)    cout<<"*";
LoopCount=0;
where.X=25;
where.Y=23;
setcolor(15);

      while(true)
      {
          SetConsoleCursorPosition(hOut,where);
          if(LoopCount%2==0)
                    cout<<"Press  -ENTER- to start the game "<<flush;
                    else
                    cout<<"                                "<<flush;
                    LoopCount++;
        GetNumberOfConsoleInputEvents(hIn,&EventCount);
          GetNumberOfConsoleInputEvents(hIn,&NumRead);


          while(EventCount>0)
          {
              ReadConsoleInput(hIn,
                            &InRec,
                            1,
                            &NumRead);
            if (InRec.EventType == KEY_EVENT)
            {
                if (InRec.Event.KeyEvent.bKeyDown)
                {
                    HoldKey = InRec.Event.KeyEvent.uChar.AsciiChar;
                }
                else
                {

                    SetConsoleCursorPosition(hOut,where);

                    if(LoopCount%2==0)
                    cout<<"Press  -ENTER- to start the game "<<flush;
                    else
                    cout<<"                                "<<flush;
                    LoopCount++;

                    Sleep(200);

                    if (HoldKey == 13)
                    {
                        SetConsoleCursorPosition(hOut,where);
                        cout<<"Press  -ENTER- to start the game "<<flush;
                      break;
                    }
                }
            }


            GetNumberOfConsoleInputEvents(hIn,&EventCount);

          }

        if (HoldKey == 13)
        {


                        SetConsoleCursorPosition(hOut,where);
                        cout<<"Press  -ENTER- to start the game "<<flush;
                      break;
        }


            Sleep(200);
      }
      where.X=57;
      SetConsoleCursorPosition(hOut,where);
      LoopCount=0;
    while (LoopCount<3)
    {

        LoopCount++;
        cout<<"."<<flush;
        Sleep(300);

    }






    char psw[]={"msi"}; //psw is the password to the system.
    char pass[4];//is the password entered by the user.
    int trials=3;//no of trials for password

    setcolor(881);// a function to change the text color
        system("cls");



    do
    {      setcolor(90);

      cout<<"\n"<<setw(43)<<"PASSWORD PART"<<setw(38)<<endl;
setcolor(881);

        cout<<endl<<"Please enter the password of my program:(Note : Only three letters)"<<endl;//ask the user to write password
        cout<<"- Note you only have:"<<trials<<":trials "<<endl;//theres three trials only fo the user

//        cout<<"*    ";

        int i=0;
        char c;
        cout.flush();
        where.X=0;
        where.Y=6;
        while(c!=3 && i<3)
        {

backspace:
          SetConsoleCursorPosition(hOut,where);
MSI:
            c=getch();
            if (c==8){    if(i>0)i--;    where.X=i;    SetConsoleCursorPosition(hOut,where);  cout<<' '<<flush;    goto backspace; }
            if (c==13||c==9)goto MSI;
            if(c==27)exit(0);
            cout<<"*"<<flush;

            cout.flush();
            pass[i]=c;
            i++;
            where.X=i;
            //c=getch();
        }

    //    cout<<"    *\n"<<"**************"<<endl;
        pass[i]='\0';
        //strlwr(pass);
        if(strcmp(psw,pass)!=0)///to compare between the rit password and the password entered by the user
            break;
        trials--;///to decrease the trials by one after each trial

        system("cls");




    }
    while(trials>0);

    if(trials==0)
    {
        cout<<"\nYour access is denied.\n\n"<<endl; //if the user entered wrong pass
    }
    else
    {
        cout<<"\nyour access is granted.\n\n\n\n\n"<<endl; //if the user entered a right pass
            cout.good();
/*
            setcolor(22);
  char TANK[]="THANK YOU FOR CHOOSING MY GAME";
  cout<<"\n\n\n\n";
where.X=60;

SetConsoleCursorPosition(hOut,where);
    for(h=0;h<30;h++)
    {
        cout<<TANK[h]<<flush;
            Sleep(100);
    }
        cout<<flush;*/
back:
        system("cls");//clear all the screen //
setcolor(26);

setcolor(26);
  cout<<"\n"<<setw(41)<<"MAIN MENU"<<setw(40)<<endl<<flush;
setcolor(884);


  cout<<setw(53)<<"********************************\n"
      <<setw(53)<<"*                              *\n"
      <<setw(53)<<"* [1]:(Player 1) Vs (Computer) *\n"
      <<setw(53)<<"* [2]:(Player 2) Vs (Player 2) *\n"
      <<setw(53)<<"*                              *\n"
      <<setw(53)<<"********************************\n"
      <<setw(53)<<"*      Press 'Q' to Exit      *\n"
      <<setw(53)<<"********************************\n";

  cout.flush();


  cout<<flush;
      start=(char)getch();
      if(start=='Q'||start=='q')exit(0);
  for ( int h=0;h<10;h++)
      p[h]=' ';
setcolor(884);
move_no=1;


switch(start)
{

case '1':
////////////////////// Player 1 VS Computer ////////////////////////////////////
do
{
back2:
    system("cls");

    setcolor(15);
    cout<<"\n"<<setw(46)<<"(Player 1) Vs (Computer)"<<setw(35)<<endl;
    setcolor(884);
    move_no=1;

  cout<<setw(53)<<"********* Skill Level ***********\n"
      <<setw(53)<<"*                              *\n"
      <<setw(53)<<"* [1]:Easy.                    *\n"
      <<setw(53)<<"* [2]:Normal.                  *\n"
      <<setw(53)<<"* [3]:Impossible.              *\n"
      <<setw(53)<<"*                              *\n"
      <<setw(53)<<"*********************************\n"
      <<setw(53)<<"*      Press 'R' to Main Menu  *\n"
      <<setw(53)<<"*      Press 'Q' to Exit        *\n"
      <<setw(53)<<"*********************************\n"<<flush;


  for ( int h=0;h<10;h++)
      p[h]=' ';
setcolor(884);
move_no=1;


again1:


  cout.flush();
      levels=(char)getch();




        if(levels=='R'||levels=='r')
            goto back;
        if(levels=='Q'||levels=='q')
            exit(0);

      if(levels>'3'||levels<'1')
    {

      goto again1;
    }



  system("cls");

while(move_no!=6)
{
Rest:
    Inlevel();
        check_status();
    if(move_no==5)
    {

        user_move= recomend_move();
        p[user_move]='X';
        system("cls");
          if(check_condition()!=4){
      Green('X');
//    check_status();
  break;}

        move_no++;
        system("cls");

        check_status();
        check_condition();
        break;
    }

    else
    {
setcolor(884);

  cout<<"Enter your move.(1-9)<Player1>:"<<flush<<endl;
again2:  cout.flush();
      user_move=getch();

        user_move-=48;
        if(user_move+48=='A'||user_move+48=='a'){ for ( int h=0;h<10;h++) p[h]=' '; move_no=1; system("cls"); goto Rest;}
        if(user_move+48=='R'||user_move+48=='r'){goto back2;}
        if(user_move+48=='Q'||user_move+48=='q'){exit(0);}
  if(incorrect(user_move))
  {

  goto again2;
  }
  p[user_move]='X';
  system("cls");
    if(check_condition()!=4){

      Green('X');
//    check_status();
  break;}

  if(move_no<5)
  {
  comp_move = recomend_move();



  p[comp_move ]='O';

  }
  system("cls");


    system("cls");
  if(check_condition()!=4){
      Green('O');
//    check_status();
  break;}




    }
    move_no++;
}

  for (int i=0;i<10;i++)
      p[i]=' ';
  setcolor(884);
  cout.flush();
  cout<<"\bPress any key to contiune ";
  cout.flush();
    getch();

  system("cls");




}while(true);


system("cls");
break;

case '2':
///////////////////////// Player 1 VS Player 2//////////////////////////////////////
    do

{

    move_no=1;
      system("cls");






while(move_no!=6)
{
Rest1:
    setcolor(30);
    cout<<"\n"<<setw(47)<<"(Player 1) Vs (Player 2)"<<setw(34)<<endl<<endl;
    check_status();
    if(move_no==5)
    {

        user_move  = recomend_move();
        p[user_move ]='X';
        move_no++;
        system("cls");

                  if(check_condition2()!=4){

        Green('X');

        break;
        }  check_status();

        check_condition2();
        break;
    }

    else
    {
setcolor(884);
cout<<"-------------------------- Player 1 Turn --------------------------"<<flush<<endl;

again6:  cout.flush();
  user_move=getch();

    user_move-=48;
        if(user_move+48=='A'||user_move+48=='a'){ for (int  h=0;h<10;h++) p[h]=' '; move_no=1; system("cls"); goto Rest1;}
      if(user_move+48=='R'||user_move+48=='r')
            goto back;
        if(user_move+48=='Q'||user_move+48=='q')
        {system("cls"); exit(0);}
  if(incorrect(user_move ))
  {

  goto again6;
  }
  p[user_move ]='X';
  system("cls");
  setcolor(30);

    cout<<"\n"<<setw(47)<<"(Player 1) Vs (Player 2)"<<setw(34)<<endl<<endl;


              if(check_condition2()!=4){
      Green('X');

  break;}
  check_status();

  if(move_no<5)
  {
setcolor(884);
cout<<"-------------------------- Player 2 Turn --------------------------"<<flush<<endl;


again7:  cout.flush();
      user_move=(char)getch();

        user_move-=48;
        if(user_move+48=='A'||user_move+48=='a'){ for (int  h=0;h<10;h++) p[h]=' '; move_no=1; system("cls"); goto Rest1;}
      if(user_move+48=='R'||user_move+48=='r')
            goto back;
        if(user_move+48=='Q'||user_move+48=='q')


  if(incorrect(user_move ))
  {

  goto again7;
  }



  p[user_move ]='O';
  system("cls");


  }

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

          if(check_condition2()!=4){
      Green('O');
//    check_status();
  break;}




    }
    move_no++;
}

for (int i=0;i<10;i++)
      p[i]=' ';
setcolor(884);


  cout<<"Do you want to play again (Y/N): "<<flush;

  cout.flush();
Qeustion:
    ch=getch();


    if(ch=='N'||ch=='n'||ch=='R'||ch=='r')goto back;
      if(ch=='q'||ch=='Q'){system("cls");exit(1);}
      else if(ch!='y'&&ch!='Y')goto Qeustion;

      system("cls");
}while(true);


system("cls");
break;

default:
      goto back;

}



}//endl of main function




}







////////////////////////////////<FUNCTION DEFINITIONS>//////////////////////////////////////////////


void check_status()
  {
    int U;
  setcolor(884);
  cout<<setw(40)<<"          1 | 2 | 3                  "<<flush;

for(U=1;U<4;U++)
{
    if(p[U]=='X')
    {
        setcolor(889);
        cout<<p[U]<<flush;
    }
    else if(p[U]=='O')
    {
        setcolor(892);
        cout<<p[U]<<flush;
    }
    else
    {
    setcolor(884);
    cout<<p[U]<<flush;
    }
    if(U<3)
    {
    setcolor(884);cout<<" | "<<flush;
    }
}
  setcolor(884);  cout<<"  *********************"<<flush<<endl;


setcolor(884);  cout<<setw(38)<<"          -----------                "<<flush; cout<<" -----------"<<"  * Press Q to quit  *"<<flush<<endl;
setcolor(884);     cout<<setw(40)<<"          4 | 5 | 6                  "<<flush;
for(U=4;U<7;U++)
{
    if(p[U]=='X')
    {
        setcolor(889);
        cout<<p[U]<<flush;
    }
    else if(p[U]=='O')
    {
        setcolor(892);
        cout<<p[U]<<flush;
    }
    else
    {
        setcolor(884);    cout<<p[U]<<flush;}
    if(U<6)
    { setcolor(884);
        cout<<" | "<<flush;
    }
}

/////////////////////////////////////////

setcolor(884);  cout<<"  * Press R to return *"<<flush<<endl;
  // cout<<p[4]<<" | "<<p[5]<<" | "<<p[6]<<"  * Press R to return *"<<endl;
setcolor(884);    cout<<setw(38)<<"          -----------                "<<flush; cout<<" -----------"<<"  * Press A to restart*"<<flush<<endl;
  setcolor(884); cout<<setw(40)<<"          7 | 8 | 9                  "<<flush;
for(U=7;U<10;U++)
{
    if(p[U]=='X')
    {
        setcolor(889);
        cout<<p[U]<<flush;
    }
    else if(p[U]=='O')
    {
        setcolor(892);
        cout<<p[U]<<flush;
    }
    else
    {setcolor(884);    cout<<p[U]<<flush;}
    if(U<9)
    { setcolor(884);
        cout<<" | "<<flush;
    }
}
  setcolor(884);
    cout<<"  ********************* "<<flush<<endl;
}

////////////////////////// CHECK POSITIION //////////////////////////////
  int incorrect(int x)
  {
  if(p[x]=='X'||p[x]=='O'||x>9||x<1)
  return true;
  else
  return false;
  }




//////////////////// SWAP CHAR FUNCTION ////////////////////////////////
  void swap(char&x,char&y)
  {
  char temp;
  temp=x;
  x=y;
  y=temp;
  }

/////////////////////////////////////////////////////////////////////////
  int  way2(int x,char win)
  {
  int no_of_wins=0;
  char temp1=win;
  char temp2=win;
  if(incorrect(x)) return 0;
  else {
  swap(p[x],temp1);
  for(int i=1;i<=9;++i)
    {  if(!incorrect(i))
      { swap(p[i],temp2);
  if(p[1]==p[2]&&p[2]==p[3]&&p[3]==win) ++no_of_wins;
  if(p[4]==p[5]&&p[5]==p[6]&&p[6]==win) ++no_of_wins;
  if(p[7]==p[8]&&p[8]==p[9]&&p[9]==win) ++no_of_wins;
  if(p[1]==p[4]&&p[4]==p[7]&&p[7]==win) ++no_of_wins;
  if(p[2]==p[5]&&p[5]==p[8]&&p[8]==win) ++no_of_wins;
  if(p[3]==p[6]&&p[6]==p[9]&&p[9]==win) ++no_of_wins;
  if(p[1]==p[5]&&p[5]==p[9]&&p[9]==win) ++no_of_wins;
  if(p[3]==p[5]&&p[5]==p[7]&&p[7]==win) ++no_of_wins;
  swap(p[i],temp2);
  }    }
  swap(p[x],temp1);
  if(no_of_wins==2) return true;
  return false;
  }  }
////////////////////////////////////////////////////////////////////
  int check_condition()
  {
  char x='X',y='O';
  if(way1(x))

  {
      setcolor(889);
  cout<<"\t\t\t************************" <<endl;
  cout<<"\t\t\t*                      *" <<endl;
  cout<<"\t\t\t*    PLAYER(1) WIN    *" <<endl;
  cout<<"\t\t\t*                      *" <<endl;
  cout<<"\t\t\t************************" <<endl;

  return 0;}
  if(way1(y))
  {  setcolor(892);
  cout<<"\t\t\t************************" <<endl;
  cout<<"\t\t\t*                      *" <<endl;
  cout<<"\t\t\t*    COMPUTER WINS    *" <<endl;
  cout<<"\t\t\t*                      *" <<endl;
  cout<<"\t\t\t************************" <<endl;

  return 1;}
  if(move_no==6)
  {
      setcolor(880);
  cout<<"\t\t************************" <<endl;
  cout<<"\t\t*                      *" <<endl;
  cout<<"\t\t*        BALANCE      *" <<endl;
  cout<<"\t\t*                      *" <<endl;
  cout<<"\t\t************************" <<endl;

  return 2;
  }
  return 4;
  }
int check_condition2()
  {
  char x='X',y='O';
  if(way1(x))
  {setcolor(889);
  cout<<"\t\t\t************************"<<endl;
  cout<<"\t\t\t*                      *"<<endl;
  cout<<"\t\t\t*    PLAYER(1) WIN    *"<<endl;
  cout<<"\t\t\t*                      *"<<endl;
  cout<<"\t\t\t************************"<<endl;

  return 0;}
  if(way1(y))
  {setcolor(892);
  cout<<"\t\t\t************************"<<endl;
  cout<<"\t\t\t*                      *"<<endl;
  cout<<"\t\t\t*    PLAYER(2) WIN    *"<<endl;
  cout<<"\t\t\t*                      *"<<endl;
  cout<<"\t\t\t************************"<<endl;

  return 1;}
  if(move_no==6)
  {
      setcolor(880);
  cout<<"\t\t\t************************"<<endl;
  cout<<"\t\t\t*                      *"<<endl;
  cout<<"\t\t\t*        BALANCE      *"<<endl;
  cout<<"\t\t\t*                      *"<<endl;
  cout<<"\t\t\t************************"<<endl;

  return 2;
  }
  return 4;
  }
///////////////////////////////////////////////////////////////
void Green(char win)
{
//    system("cls");
    int which,mover;
    if(p[1]==p[2]&&p[2]==p[3]&&p[3]==win){ which=1;mover=1;}
    else if (p[4]==p[5]&&p[5]==p[6]&&p[6]==win) {which=2; mover=1;}
    else if (p[7]==p[8]&&p[8]==p[9]&&p[9]==win) {which=3; mover=1;}
    else if (p[1]==p[4]&&p[4]==p[7]&&p[7]==win) {which=4; mover=3;}
    else if (p[2]==p[5]&&p[5]==p[8]&&p[8]==win) {which=5; mover=3;}
    else if (p[3]==p[6]&&p[6]==p[9]&&p[9]==win) {which=6; mover=3;}
    else if (p[1]==p[5]&&p[5]==p[9]&&p[9]==win) {which=7; mover=4;}
    else if(p[3]==p[5]&&p[5]==p[7]&&p[7]==win)  {which=8; mover=2;}

    int U;
  setcolor(884);
  cout<<setw(40)<<"          1 | 2 | 3                  "<<flush;

for(U=1;U<4;U++)
{
    if(which==1&&mover==1)
    { setcolor(890); cout<<p[U]<<flush;}
    else if(which==4&&mover==3&&U==1)
    { setcolor(890); cout<<p[U]<<flush;}
        else if(which==5&&mover==3&&U==2)
    { setcolor(890); cout<<p[U]<<flush;}
        else if(which==6&&mover==3&&U==3)
    { setcolor(890); cout<<p[U]<<flush;}
        else if(which==7&&mover==4&&U==1)
    { setcolor(890); cout<<p[U]<<flush;}
            else if(which==8&&mover==2&&U==3)
    { setcolor(890); cout<<p[U]<<flush;}
    else if(p[U]=='X')
    {
        setcolor(889);
        cout<<p[U]<<flush;
    }
    else if(p[U]=='O')
    {
        setcolor(892);
        cout<<p[U]<<flush;
    }
    else
    {
    setcolor(884);
    cout<<p[U]<<flush;
    }
    if(U<3)
    {
    setcolor(884);cout<<" | "<<flush;
    }
}
  setcolor(884);  cout<<"  *********************"<<flush<<endl;


setcolor(884);  cout<<setw(38)<<"          -----------                "<<flush; cout<<" -----------"<<"  * Press Q to quit  *"<<flush<<endl;
setcolor(884);     cout<<setw(40)<<"          4 | 5 | 6                  "<<flush;
for(U=4;U<7;U++)
{
        if(which==2&&mover==1)
    { setcolor(890); cout<<p[U]<<flush;}
        else if(which==4&&mover==3&&U==4)
    { setcolor(890); cout<<p[U]<<flush;}
        else if(which==5&&mover==3&&U==5)
    { setcolor(890); cout<<p[U]<<flush;}
            else if(which==6&&mover==3&&U==6)
    { setcolor(890); cout<<p[U]<<flush;}
                else if(which==7&&mover==4&&U==5)
    { setcolor(890); cout<<p[U]<<flush;}
                else if(which==8&&mover==2&&U==5)
    { setcolor(890); cout<<p[U]<<flush;}
    else if(p[U]=='X')
    {
        setcolor(889);
        cout<<p[U]<<flush;
    }
    else if(p[U]=='O')
    {
        setcolor(892);
        cout<<p[U]<<flush;
    }
    else
    {
        setcolor(884);    cout<<p[U]<<flush;}
    if(U<6)
    { setcolor(884);
        cout<<" | "<<flush;
    }
}



setcolor(884);  cout<<"  * Press R to return *"<<flush<<endl;

setcolor(884);    cout<<setw(38)<<"          -----------                "<<flush; cout<<" -----------"<<"  *********************"<<flush<<endl;
  setcolor(884); cout<<setw(40)<<"          7 | 8 | 9                  "<<flush;
for(U=7;U<10;U++)
{
        if(which==3&&mover==1)
        { setcolor(890); cout<<p[U]<<flush;}
            else if(which==4&&mover==3&&U==7)
    { setcolor(890); cout<<p[U]<<flush;}
        else if(which==5&&mover==3&&U==8)
    { setcolor(890); cout<<p[U]<<flush;}
            else if(which==6&&mover==3&&U==9)
    { setcolor(890); cout<<p[U]<<flush;}
                else if(which==7&&mover==4&&U==9)
    { setcolor(890); cout<<p[U]<<flush;}
                else if(which==8&&mover==2&&U==7)
    { setcolor(890); cout<<p[U]<<flush;}
    else if(p[U]=='X')
    {
        setcolor(889);
        cout<<p[U]<<flush;
    }
    else if(p[U]=='O')
    {
        setcolor(892);
        cout<<p[U]<<flush;
    }
    else
    {setcolor(884);    cout<<p[U]<<flush;}
    if(U<9)
    { setcolor(884);
        cout<<" | "<<flush;
    }
}
  cout<<flush<<endl;
}
///////////////////////////////////////////////////////////////////////////////
  int way1(char x)
  {
  char win=x;
  if(
      (p[1]==p[2]&&p[2]==p[3]&&p[3]==win)
    ||(p[4]==p[5]&&p[5]==p[6]&&p[6]==win)
    ||(p[7]==p[8]&&p[8]==p[9]&&p[9]==win)
    ||(p[1]==p[4]&&p[4]==p[7]&&p[7]==win)
    ||(p[2]==p[5]&&p[5]==p[8]&&p[8]==win)
    ||(p[3]==p[6]&&p[6]==p[9]&&p[9]==win)
    ||(p[1]==p[5]&&p[5]==p[9]&&p[9]==win)
    ||(p[3]==p[5]&&p[5]==p[7]&&p[7]==win)
    )
  return true;
  else return false;
  }
////////////////////////////////////////////////////////////////
  int recomend_move()
  {
      if( levels=='3'&&move_no<3 )
  {
  if(move_no==1)
    if(incorrect(5)) return 7;
          else return 5;
  else if(move_no==2)
    if((p[1]==p[9]&&p[9]=='X')||(p[3]==p[7]&&p[7]=='X'))
      return 2;
  }
      char temp,x='X',y='O',temp1='O',temp2='X';
  if( (levels=='3'|| levels=='2')&&move_no>1)
  {
      for(int i=1;i<=9;++i)
  if(!incorrect(i))
  {
  temp='X';
  swap(p[i],temp);
  if(way1(x))
  return i;
  else swap(p[i],temp);
  }

            if(levels=='3')
  for(int p=1;p<=9;++p)
  {


  if(way2(p,temp1)) return p;

  if(way2(p,temp2)) return p;
  else continue;

  }


  for(int  i=1;i<=9;++i)
  if(!incorrect(i))
  {
  temp='O';
  swap(p[i],temp);
  if(way1(y))
  return i;
  else swap(p[i],temp);
  }



/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

}//end of the first if-condition

/////////////////////////////////////////////////////////////////////////


  while(levels=='1'||(levels=='2'||levels=='3'&&move_no==1)) {
      int Return;

      Return=rand()%10;
      if(!incorrect(Return)&&Return!=0)
          return Return;
      else
          continue;
    }

    if(!incorrect(1)) return 1;
  else if(!incorrect(3)) return 3;
  else if(!incorrect(7)) return 7;
  else if(!incorrect(9)) return 9;
  else if(!incorrect(2))  return 2;
  else if(!incorrect(4))  return 4;
  else return 8;

}
  void Inlevel()
{

      if(levels=='1'){
              setcolor(11);
    cout<<"\n"<<setw(40)<<"Easy Level"<<setw(40)<<endl<<endl;
    setcolor(884);}
    else if (levels=='2')
    {
            setcolor(15);
    cout<<"\n"<<setw(41)<<"Normal Level"<<setw(40)<<endl<<endl;
    setcolor(884);
    }
    else  {

                setcolor(12);
    cout<<"\n"<<setw(41)<<"Impossible Level"<<setw(37)<<endl<<endl;
    setcolor(884);
    }
}
void MSI()
{
    hIn= GetStdHandle(STD_INPUT_HANDLE);// Declaration of "hIn"
hOut= GetStdHandle(STD_OUTPUT_HANDLE);// Declaration of "hOut"      //Cursor Postions


            setcolor(12);

          cout<<"\t\t\t      "<<flush;
            setcolor(15);

          cout<<"M      S    I    "<<flush;
            Sleep(1000);
            setcolor(12);

            where.X=31;
            where.Y=0;
                for(int Q=1;Q<7;Q++)
                {

                for(int C=0;C<5;C++)
                      {
                          SetConsoleCursorPosition(hOut,where);
                          //if(Try==MYname[Q])break;
                          if(C%3==0)
                          cout<<'/'<<flush;
                          else if(C%3==1)
                          cout<<"\\"<<flush;
                          else
                          cout<<'-'<<flush;

                          Sleep(10);
                      }

                      SetConsoleCursorPosition(hOut,where);

                            cout<<MYname[Q]<<flush;

                    where.X++;
                }

                  where.X+=2 ;






                for(int Q=7;Q<10;Q++)
                {




                      for(int C=0;C<5;C++)
                      {
                        SetConsoleCursorPosition(hOut,where);
                          //if(Try==MYname[Q])break;
                          if(C%3==0)
                          cout<<'/'<<flush;
                          else if(C%3==1)
                          cout<<"\\"<<flush;
                          else
                          cout<<'-'<<flush;

                          Sleep(10);
                      }
                      SetConsoleCursorPosition(hOut,where);
                            cout<<MYname[Q]<<flush;

                    where.X++;
                }
                where.X+=2;







              for(int Q=10;Q<15;Q++)
                {

                for(int C=0;C<5;C++)
                      {

                          SetConsoleCursorPosition(hOut,where);
                          //if(Try==MYname[Q])break;
                          if(C%3==0)
                          cout<<'/'<<flush;
                          else if(C%3==1)
                          cout<<"\\"<<flush;
                          else
                          cout<<'-'<<flush;

                          Sleep(10);
                      }

                      SetConsoleCursorPosition(hOut,where);

                            cout<<MYname[Q]<<flush;

                    where.X++;
                }

}
//                        <COLOR FUNCTIONS>                                    //

void setcolor(unsigned short color)
{    //begining of set color funtion

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);      //gets std handle
    SetConsoleTextAttribute(hCon,color);     //Sets Console Text Attribute HCon color.
}    //end of set color funtion
void MY_sign()
{

        setcolor(15 );
        cout<<"CAIRO UNVIERISITY"<<endl;
        cout<<"FACULTY OF COMPUTER AND INFORMATION"<<endl;
        setcolor(44);
        cout<<setw(41)<<"X-O GAME "<<setw(40)<<endl;
        setcolor(2);

}

