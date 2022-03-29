#include<iostream>
#include<windows.h>
#include<time.h>
#include<cstdlib>
#include<conio.h>
using namespace std;
 int UP=72,DOWN=80,LEFT=75,RIGHT=77,ENTER=13,SPACE=32; // key handling
 int blue=1,green=10,red=12,yellow=14, black=0,white=15,sky=3;
 int playAreaX=100,playAreaY=50;
int currentTextLine=0;
int backgroudColor=red,textBackgroundColor=0;
char textBackground=' ';
void setConsole(int X,int Y){
    COORD z;
    z.X=X; z.Y=Y;
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hhh,z);
}
void wait(int millis)
{
    Sleep(millis);
}
void setcolor(int latter , int backgroud=0)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    if(backgroud==0|| backgroud>15)    SetConsoleTextAttribute(hcon,latter);
    else
    {
        SetConsoleTextAttribute(hcon,(backgroud*16 + latter));
    }
}
void setConsoleNormal(){
    setConsole(103,currentTextLine);
}
void print(char *val){
    if(currentTextLine>52) currentTextLine=0;
        setConsole(103,currentTextLine++); cout<<val;
}

void clearScreen(){
    system("CLS");
}
void makePartition(){
    setConsole(0,0);
    setcolor(textBackgroundColor,backgroudColor);
    for(int i=0; i<102; i++) cout<<textBackground;
    for(int i=1; i<51; i++){setConsole(0,i);cout<<textBackground;
    setConsole(101,i);cout<<textBackground; }
    setConsole(0,51);
    for(int i=0; i<102; i++) cout<<textBackground;
    setConsoleNormal();
    setcolor(7);
}

void clearPlayerScreen(){

}
void clearTextScreen(){
}

void showRectangle(int height,int width,int colorB=red,int colorT=black,char text=' '){

}
void showRectangleBox(int height,int width,int thickX=1,int thickY=1,int colorB=red,int colorT=black,char text=' '){
}


