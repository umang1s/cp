#include<iostream>
#include<windows.h>
#include<time.h>
#include<cstdlib>
#include<conio.h>
using namespace std;
static int UP=72,DOWN=80,LEFT=75,RIGHT=77,ENTER=13; // key handling
int blue=1,green=10,red=12,yellow=14;
int black=0,white=15,sky=3;
void setcolor(int latter , int backgroud=0)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    if(backgroud==0|| backgroud>15)    SetConsoleTextAttribute(hcon,latter);
    else
    {
        SetConsoleTextAttribute(hcon,(backgroud*16 + latter));
    }
}

void rect(int x,int y,int bgC,int col,int len,int wid)
{
    COORD p;
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    p.X=x;  p.Y=y;
    SetConsoleCursorPosition(hhh,p);
    setcolor(15,bgC);
    for(int i=0; i<len; i++) cout<<" ";
    for(int j=0; j<wid-2; j++)
    {
        y++; p.Y=y;
        SetConsoleCursorPosition(hhh,p);
        cout<<"  ";
        setcolor(15,col);
        for(int k=0; k<len-4; k++) cout<<" ";
        setcolor(15,bgC);
        cout<<"  ";
    }
    y++; p.Y=y;
    SetConsoleCursorPosition(hhh,p);
    for(int i=0; i<len; i++) cout<<" ";
    setcolor(7);
}
int getKey()
{
    char x;
    int k;
    while(!kbhit()){x=getch();}
    x=getch();
    k=x;
    return k;
}
void wait(int millis)
{
    Sleep(millis);
}

void setconsole(COORD x)
{
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hhh,x);
}
void showSeven(COORD coord ,int param,int z)//z=0 for horizontal
{
    setconsole(coord);
    if(z==0)    for(int i=0; i<param; i++)  {
            for(int j=0; j<param*6 +1; j++) cout<<" ";
            coord.Y++;  setconsole(coord);
        }   else   for(int i=0; i<3*param; i++)    {
            for(int j=0; j<param*2; j++) cout<<" ";
            coord.Y++;  setconsole(coord);
        }
}
void showS(COORD b,int param,char a[7])
{
    int k=4*param +1;
    if(!param) param=1;
    if(a[0]==49) showSeven(b,param,0);
    if(a[1]==49) showSeven(b,param,1);  b.X+=k;
    if(a[2]==49) showSeven(b,param,1);  b.X-=k; b.Y+=2*param;
    if(a[3]==49) showSeven(b,param,0);
    if(a[4]==49) showSeven(b,param,1);  b.X+=k;
    if(a[5]==49) showSeven(b,param,1);  b.X-=k;    b.Y+=2*param;
    if(a[6]==49) showSeven(b,param,0);
}
COORD SevenSegment(COORD a,int value,int ColorBgc=12,int param=1)//0 to 9,10, e
{
    int x,y;
    setcolor(0,ColorBgc);
    switch(value)   //p.X=coord.X + (4*param) +1;
    {
        case 0: showS(a,param,"1110111"); break;
        case 1: showS(a,param,"0010010"); break;
        case 2: showS(a,param,"1011101"); break;
        case 3: showS(a,param,"1011011"); break;
        case 4: showS(a,param,"0111010"); break;
        case 5: showS(a,param,"1101011"); break;
        case 6: showS(a,param,"1101111"); break;
        case 7: showS(a,param,"1010010"); break;
        case 8: showS(a,param,"1111111"); break;
        case 9: showS(a,param,"1111011"); break;

    }
    setcolor(7);
    a.X=6*param+2;
    a.Y=5*param+2;
    return a;
}
COORD SevenSegment(COORD a,char value,int ColorBgc=12,int param=1)
{

    int x,y;
    setcolor(0,ColorBgc);
    switch(value)
    {
        /* a1
      a2    a3
        a4
      a5    a6
         a7 */
        case 'A': showS(a,param,"1111110"); break;
        case 'B': showS(a,param,"1111111"); break;
        case 'C': showS(a,param,"1100101"); break;
        case 'D': case 'O': showS(a,param,"1110111"); break;
        case 'E': showS(a,param,"1101101"); break;
        case 'F': showS(a,param,"1101100"); break;
        //case 'G': showS(a,param,"1110111"); break;
        case 'H': showS(a,param,"0111110"); break;
        case 'I': showS(a,param,"0010010"); break;
        case 'J': showS(a,param,"0010011"); break;
        //case 'K': showS(a,param,"1110111"); break;
        case 'L': showS(a,param,"0100101"); break;
        case 'P': showS(a,param,"1111100"); break;
        case 'S': showS(a,param,"1101011"); break;
        case 'U': showS(a,param,"0110111"); break;
    }
    setcolor(7);
    a.X=6*param+2;
    a.Y=5*param+2;
    return a;
}
void square(COORD x,int color,int len,int wid)
{
    setcolor(0,color);
    for(int i=0; i<wid; i++)
    {
        setconsole(x);
        for(int j=0; j<len; j++) cout<<" ";
        x.Y++;
    }
    setcolor(7);
}
void SevenSegmentEraser(COORD a,int param)
{
    square(a,0,param*6+1,param*5+2);
}
