#include<iostream>
#include"graphic.h"
using namespace std;
int defCol=134;
COORD c1,c2,c3;
int delaying=2;
void makeSwitch(int x){
    setcolor(defCol);
    COORD useco,uperco,lowerco;

    if(x==1) useco=c1;
    else if(x==2) useco=c2;
    else useco=c3;

    uperco=lowerco=useco; uperco.Y-=2; setconsole(uperco);
    cout<<"            ";
    uperco.Y++; setconsole(uperco);
    cout<<"            ";

    setconsole(useco);
    cout<<"                                                            ";
    useco.Y++; setconsole(useco);
    cout<<"                                                            ";
    lowerco.Y+=2; setconsole(lowerco);
    cout<<"            ";
    lowerco.Y++; setconsole(lowerco);
    cout<<"            ";
}
void turnOn(int x){
    int col;
    COORD s1,s2;
    if(x==1){col=red; s1=c1;}
    else if(x==2) {col=green; s1=c2;}
    else {col=blue; s1=c3;}

    setcolor(3); s1.Y-=2;
    while(s1.X != 64){
        s2=s1; setcolor(3);
        //deleting
        s2=s1; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        setcolor(0,col);
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        setcolor(3);
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";

        //making new
        setcolor(0,col);
        s2=s1; s2.X+=12; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s1.X++; wait(delaying);
    }

}
void turnOf(int x){
    int col;
    COORD s1,s2;
    if(x==1){col=red; s1=c1;}
    else if(x==2) {col=green; s1=c2;}
    else {col=blue; s1=c3;}

    setcolor(3); s1.Y-=2; s1.X=63;
    while(s1.X != 14){
        s2=s1;
        //deleting
        setcolor(3);
        s2=s1; s2.X+=12; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        setcolor(defCol);
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        setcolor(3);
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";

        //making new
        setcolor(0,col);
        if(s1.X<28) setcolor(defCol);
        s2=s1; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s2.Y++; setconsole(s2);  cout<<" ";
        s1.X--;
        wait(delaying);
    }
}
void makeButton(int x){
    COORD Yx;
    if(x==1) Yx=c1;
    else if(x==2) Yx=c2;
    else Yx=c3;
    setcolor(250);
    Yx.X+=65;
    setconsole(Yx);
    cout<<"          ";
    Yx.Y++; setconsole(Yx);
    cout<<"          ";
}
void removeButton(int x){
    COORD Yx;
    if(x==1) Yx=c1;
    else if(x==2) Yx=c2;
    else Yx=c3;
    setcolor(1);
    Yx.X+=65;
    setconsole(Yx);
    cout<<"          ";
    Yx.Y++; setconsole(Yx);
    cout<<"          ";
}
int main(){
    int cursor=1,closing;
    int C1,C2,C3,de;
    int key;
    int x=15,y=5,gap=8;
    bool b[4]; b[1]=b[2]=b[3]=false;
    c1.X=c2.X=c3.X=x;
    c1.Y=y; c2.Y=c1.Y+gap; c3.Y=c2.Y+gap;
    //initial setup
    makeSwitch(1); makeSwitch(2); makeSwitch(3);
    makeButton(1);
    while(1){
            key=getch();
            //getting key
            if(key==UP){removeButton(cursor); cursor--; if(cursor==0) cursor=3; makeButton(cursor);}
            else if(key==DOWN) {removeButton(cursor); cursor++; if(cursor==4) cursor=1;makeButton(cursor);}
            else if(key==LEFT || key == RIGHT){
                if(b[cursor])  turnOf(cursor); else turnOn(cursor);
                b[cursor]=!b[cursor];
                //checking condition
                if(b[1] && b[2] && b[3]){
                    if(cursor==1) closing=3;
                    else if(cursor==2) closing=1;
                    else closing=2;
                    turnOf(closing);
                    b[closing] =!b[closing];
                }

            }else if(key=='q' || key=='Q'){
                setcolor(7);
                system("cls");
                break;
            }
    }

}
