#include<iostream>
#include<windows.h> // color
#include<conio.h>
#include<iomanip>
#include"graphic.h"
using namespace std;
int Cube[6][3][3];
void distroyCube();
int findFronts(int in,int dire)
{
    int vs[4]={0,4,2,5},hs[4]={0,1,2,3};
    int j,k;
    for(x=0; x<4; x++) { if(vs[x]==in) j=x; if(hs[x]==in) k=x;}
    if(j)
    if(dire==UP)
    {
        if(in==0 || in==1 || in==2 || in)
    }
}
void displayCube(int side,int line=0);
COORD L;
void displayArrow(int x,bool which=true);
int BGC=0;
void UpdateMove(int x)
{
    COORD p;
    p.X=L.X+55; p.Y=L.Y+2;
    square(p,0,5,1);
    setconsole(p);
    cout<<x;
}
bool completion()
{
    int x=0,y=0;
    for(int k=0; k<6; k++)
    {
        y=0;
        for(int i=0; i<3; i++) for(int j=0; j<3; j++)   if(Cube[k][1][1]==Cube[k][i][j]) y++;
        if(y==9) x++;
    }
    if(x==6) return true;
    else false;
}
int main()
{
    L.X=30; L.Y=8;
    distroyCube();
    int k=0;
    displayCube(3);
    int i=0,last=1,fronts=1;
    char j;
    displayArrow(last);
    int arrk=0,rotK=0,Move=0;
    bool looping=true;
    int temp1,temp2,temp3;
    while(looping)
    {
        j=getch();
        switch(j)
        {
            case 'H' : fronts=findFronts(fronts,UP); break;
            case 'P' : //down break
            case 'K' : //left
            case 'M' : //right
            case 'a' : //rotate left
            case 'd' ://rotate right
            case 's' : //rotate down
            case 'w' : //rotate en
        }
        if(j==UP) { arrk++; if(arrk==13) arrk=1; displayArrow(last,false); displayArrow(arrk); last=arrk;}
        else if(j==DOWN) {arrk--; if(arrk==0) arrk=12; displayArrow(last,false); displayArrow(arrk); last=arrk;}
        else if(j==LEFT) {rotK--; if(rotK==-1) rotK=5; displayCube(rotK);}
        else if(j==RIGHT) {rotK++; if(rotK==6) rotK=0; displayCube(rotK);}
        else if(j==ENTER)
        {

            if(arrk<4 && arrk>0) //up
            {
                temp1=Cube[rotK][0][arrk-1]; temp2=Cube[rotK][1][arrk-1]; temp3=Cube[rotK][2][arrk-1];
                for(int m=0; m<3; m++)
                {
                    Cube[]
                }
                displayCube(rotK,arrk);
            }
            else if(arrk<7 && arrk>3) //right
            {
                displayCube(rotK,arrk);
            }
            else if(arrk<10 && arrk>6)//down
            {
                displayCube(rotK,arrk-3);
            }
            else    //left
            {
                displayCube(rotK,arrk-3);
            }
            Move++;
            UpdateMove(Move);
            // if(completion()) looping=false;
        }
    }

}
void displayCube(int side,int line)   //line 1 ,2,3 for vertical 4,5,6 for horizontal
{
    COORD P=L;
    if(line==0)
    {
        for(int i=0; i<3; i++){
                for(int j=0; j<3; j++) { square(P,Cube[side][i][j],10,5); P.X+=12;}
        P.X=L.X; P.Y+=6;}
        P.X=L.X+48; P.Y=L.Y+2;
        setconsole(P); cout<<"Move : ";
    }
    else if(line<4)
    {
        P.Y+=(line-1)*6;
        for(int j=0; j<3; j++) {square(P,Cube[side][line-1][j],10,5);P.X+=12;}
    }
    else
    {
        P.X+=(line-4)*12;
        for(int j=0; j<3; j++) {square(P,Cube[side][j][line-4],10,5); P.Y+=6; }
    }
}

void displayArrow(int x,bool IO) //1,2,3 up 4,5,6 left 7,8,9 down 10,11,12 right
{
    COORD P=L;
    int Abc=8;
    bool up;
    switch(x)
    {
        case 1: up=true; P.X=L.X+4; P.Y=L.Y-5; break;
        case 2: up=true; P.X=L.X+16; P.Y=L.Y-5; break;
        case 3: up=true; P.X=L.X+28; P.Y=L.Y-5; break;
        case 4: up=false; P.X=L.X+38; P.Y=L.Y+2; break;
        case 5: up=false; P.X=L.X+38; P.Y=L.Y+8; break;
        case 6: up=false; P.X=L.X+38; P.Y=L.Y+14; break;
        case 7: up=true; P.X=L.X+28; P.Y=L.Y+19; break;
        case 8: up=true; P.X=L.X+16; P.Y=L.Y+19; break;
        case 9: up=true; P.X=L.X+4; P.Y=L.Y+19; break;
        case 10: up=false; P.X=L.X-9; P.Y=L.Y+14; break;
        case 11: up=false; P.X=L.X-9; P.Y=L.Y+8; break;
        case 12: up=false; P.X=L.X-9; P.Y=L.Y+2; break;
    }
    if(up) {if(IO) square(P,Abc,2,3);
            else square(P,BGC,2,3);}
    else  {if(IO) square(P,Abc,6,1);
            else square(P,BGC,6,1);}
}
void distroyCube()
{
    int t[6]={blue,red,yellow,green,15,11};
    for(int k=0; k<6; k++) for(int i=0; i<3; i++) for(int j=0; j<3; j++) Cube[k][i][j]=t[k];
}
