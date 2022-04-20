#include<iostream>
#include<cstdlib>
#include<conio.h>
#include"graphic.h"
#include<windows.h>
using namespace std;
typedef struct Dir  {   int x,y;    }dir;
dir path[4][56];
dir getDisplayPath(int color,int position)
{
    dir ret;
    if(color==blue) ret=path[3][position];
    else if(color==yellow) ret=path[2][position];
    else if(color==green) ret=path[1][position];
    else ret=path[0][position];
    return ret;
}

void setDisplayPath()
{
    dir normalPath[53];
    int i=0,a,b; //starting from red    //a is x and b is y;
    a=0; b=24;  for(i=1; i<7; i++){normalPath[i].x=a; normalPath[i].y=b; a+=8;} //-->
    a=72; b=24;  for(i=20; i<26; i++){normalPath[i].x=a; normalPath[i].y=b; a+=8;}//  -->
    a=40; b=32;  for(i=46; i<52; i++){normalPath[i].x=a; normalPath[i].y=b; a-=8;} //<--
    a=112; b=32;  for(i=27; i<33; i++){normalPath[i].x=a; normalPath[i].y=b; a-=8;} //   <--

    a=48; b=20;  for(i=7; i<13; i++){normalPath[i].x=a; normalPath[i].y=b; b-=4;} //AA
    a=48; b=56;  for(i=40; i<46; i++){normalPath[i].x=a; normalPath[i].y=b; b-=4;} //AA
    a=64; b=0;  for(i=14; i<20; i++){normalPath[i].x=a; normalPath[i].y=b; b+=4;} //  VV
    a=64; b=36;  for(i=33; i<39; i++){normalPath[i].x=a; normalPath[i].y=b; b+=4;} //  VV

    normalPath[52].x=0; normalPath[52].y=28;//<
    normalPath[26].x=112; normalPath[26].y=28;// >
    normalPath[13].x=56; normalPath[13].y=0;//A
    normalPath[39].x=56; normalPath[39].y=56;// V

    int xx,yy;

    //for red
    int position=0; xx=8; yy=28;
    for(int z=2; z<53; z++) path[0][position++] = normalPath[z];
    for(int m=51; m<56; m++){path[0][m].x=xx; path[0][m].y=yy; xx+=8;}

    //for green
    position=0; xx=56; yy=4;
    for(int z=15; z<53; z++) path[1][position++] = normalPath[z];
    for(int z=1; z<14; z++) path[1][position++] = normalPath[z];
    for(int m=51; m<56; m++){path[1][m].x=xx; path[1][m].y=yy; yy+=4;}

    //for yellow
    position=0; xx=104; yy=28;
    for(int z=28; z<53; z++) path[2][position++] = normalPath[z];
    for(int z=1; z<27; z++) path[2][position++] = normalPath[z];
    for(int m=51; m<56; m++){path[2][m].x=xx; path[2][m].y=yy; xx-=8;}

    //for blue
    position=0; xx=56; yy=52;
    for(int z=41; z<53; z++) path[3][position++] = normalPath[z];
    for(int z=1; z<40; z++) path[3][position++] = normalPath[z];
    for(int m=51; m<56; m++){path[3][m].x=xx; path[3][m].y=yy; yy-=4;}
}
void centerPrint(int x,int y)
{
    COORD p;
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    x+=4; y+=2;
    p.X=x;  p.Y=y;
    SetConsoleCursorPosition(hhh,p);
}
void center(int x)
{
    COORD p;
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    if(x==red){p.X=25;  p.Y=12;}
    else if(x==yellow) {p.X=96;  p.Y=48;}
    else if(x==blue) {p.X=25;  p.Y=48;}
    else {p.X=96;  p.Y=12;}
    SetConsoleCursorPosition(hhh,p);
}
void makeMap()
{
    int fg=15,bg =3;
    int i,j;
    //printing big square
    rect(0,0,bg,fg,50,25);
    rect(72,0,bg,fg,50,25);
    rect(0,36,bg,fg,50,25);
    rect(72,36,bg,fg,50,25);
    //printing vertical box
    i=48;
    while(i<72){    j=0;    while(j<24) {rect(i,j,bg,fg,10,5); j+=4; }    i+=8;   } //vertical up
    i=48;
    while(i<72){    j=36;    while(j<60) {rect(i,j,bg,fg,10,5); j+=4; }    i+=8;   } //vertical down
    i=0;
    while(i<42){    j=24;    while(j<35) {rect(i,j,bg,fg,10,5); j+=4; }    i+=8;   } //horizontal left
    i=72;
    while(i<114){    j=24;    while(j<35) {rect(i,j,bg,fg,10,5); j+=4; }    i+=8;   } //horizontal right
    //the center
    rect(48,24,bg,fg,26,13);
}
bool makeStar(bool x,int z=0,int k=0) //for rewritting star false for setStar
{
	int bg=3,fg=13;
	if(x)
    {
        if(z==48 && k==8) {rect(48,8,bg,fg,10,5); return true;}
        else if(z==48 && k==52) {rect(48,52,bg,fg,10,5);return true;}
        else if(z==64 && k==4) {rect(64,4,bg,fg,10,5); return true;}
        else if(z==64 && k==48) {rect(64,48,bg,fg,10,5); return true;}
        else if(z==8 && k==24) {rect(8,24,bg,fg,10,5); return true;}
        else if(z==96 && k==24) {rect(96,24,bg,fg,10,5); return true;}
        else if(z==16 && k==32) {rect(16,32,bg,fg,10,5); return true;}
        else if(z==104 && k==32) {rect(104,32,bg,fg,10,5); return true;}
        else return false;
    }
    rect(48,8,bg,fg,10,5);
    rect(48,52,bg,fg,10,5);
    rect(64,4,bg,fg,10,5);
    rect(64,48,bg,fg,10,5);
    rect(8,24,bg,fg,10,5);
    rect(96,24,bg,fg,10,5);
    rect(16,32,bg,fg,10,5);
    rect(104,32,bg,fg,10,5);
    return false;
}
void setPlayer(int color,int num,bool dot)  //true for set and false for delete
{
    int bg=15,bb=15; //bg for box background and bb for background
    //red
    if(color==1)
    {
        if(num==1)
        {
            if(dot) rect(12,6,bg,red,10,5);
            else rect(12,6,bb,bb,10,5);
        }
        else if(num==2)
        {
            if(dot) rect(28,6,bg,red,10,5);
            else rect(28,6,bb,red,10,5);
        }
        else if(num==3)
        {
            if(dot) rect(12,14,bg,red,10,5);
            else rect(12,14,bb,red,10,5);
        }
        else
        {
            if(dot) rect(28,14,bg,red,10,5);
            else rect(28,14,bb,red,10,5);
        }
    }

    //green
    if(color==2)
    {
        if(num==1)
        {
            if(dot) rect(84,6,bg,green,10,5);
            else rect(84,6,bb,green,10,5);
        }
        else if(num==2)
        {
            if(dot) rect(99,6,bg,green,10,5);
            else rect(99,6,bb,green,10,5);
        }
        else if(num==3)
        {
            if(dot) rect(84,14,bg,green,10,5);
            else rect(84,14,bb,green,10,5);
        }
        else
        {
            if(dot) rect(99,14,bg,green,10,5);
            else rect(99,14,bg,green,10,5);
        }
    }

    //yellow
    if(color==3)
    {
        if(num==1)
        {
            if(dot) rect(84,42,bg,yellow,10,5);
            else rect(84,42,bb,yellow,10,5);
        }
        else if(num==2)
        {
            if(dot) rect(99,42,bg,yellow,10,5);
            else rect(99,42,bb,yellow,10,5);
        }
        else if(num==3)
        {
            if(dot) rect(84,50,bg,yellow,10,5);
            else rect(84,50,bb,yellow,10,5);
        }
        else
        {
            if(dot) rect(99,50,bg,yellow,10,5);
            else rect(99,50,bb,yellow,10,5);
        }
    }
    //blue
    if(color==4)
    {
        if(num==1)
        {
            if(dot) rect(12,42,bg,blue,10,5);
            else rect(12,42,bb,blue,10,5);
        }
        else if(num==2)
        {
            if(dot) rect(28,42,bg,blue,10,5);
            else rect(28,42,bb,blue,10,5);
        }
        else if(num==3)
        {
            if(dot) rect(12,50,bg,blue,10,5);
            else rect(12,50,bb,blue,10,5);
        }
        else
        {
            if(dot) rect(28,50,bg,blue,10,5);
            else rect(28,50,bb,blue,10,5);
        }
    }
}
int throwDice()
{
    return 1;
}
void showValue(int x,int y);

void gameContinueQuad()
{
    int round=1,sixCounter,currentPlayer;
    bool progress=true;
    int PlayerMove[4][4];
    int temp[6],pos=0 ; //this is for storing value
    while(progress)
    {
        while(round<5)
        {
            sixCounter=0;
            pos=0;
            if(round==1) currentPlayer=red;
            else if(round==2) currentPlayer=green;
            else if(round==3) currentPlayer=yellow;
            else currentPlayer=blue;
            while(currentPlayer)
            {
                center(currentPlayer);
                if(throwDice()==6)
                {
                    sixCounter++;
                    //showValue(6,pos);
                    temp[pos++] =6;
                }
                if(sixCounter==3) currentPlayer=0;
                else
                {
                    ;
                }
                currentPlayer=0; Sleep(2000);
            }
            //now moving part

            round++;
        }
        round=1;
    }
    Sleep(10000);
}

int FirstPage()
{
    return 3;
}
void gameContinueDuo()
{
    cout<<"incomplete";
}
int main()
{
	getch();
    int x=FirstPage();
    system("CLS");
    makeMap();
    makeStar(false);
    for(int i=1; i<5; i++) for(int j=1; j<5; j++) setPlayer(i,j,true);
    setDisplayPath();
    if(x==2) gameContinueDuo();
    else gameContinueQuad();
    setcolor(7);
    system("CLS");
    cout<<"press any key for exit";
    getch();
}
