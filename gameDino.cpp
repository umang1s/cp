#include <iostream>
#include"graphic.h"
using namespace std;
COORD dino,last;
void jumpBox(int x){
    COORD xs=dino;
    //deleting old
    setconsole(last);
    setcolor(3);
    cout<<"     ";
    last.Y++; setconsole(last);
    cout<<"     ";
    // creating new
    xs.Y-=x; last=xs;
    setconsole(xs);
    setcolor(0,green);
    cout<<"    ";
    xs.Y++; setconsole(xs);
    cout<<"    ";
}
void showValue(int x){
    COORD VV;
    VV.X=5; VV.Y=1;
    setcolor(7);
    setconsole(VV);
    cout<<"       ";
    cout<<x;
}
void showObject1(int x){
    COORD xs;
    xs.Y=8; xs.X=x;
    setcolor(0,red);
    setconsole(xs); cout<<"  "; setcolor(3); cout<<"  "; setcolor(0,red);
    xs.Y++; setconsole(xs); cout<<"  "; setcolor(3); cout<<"  ";

    if(x==0){
        setcolor(0);  xs.Y=8;
        setconsole(xs); cout<<"  "; xs.Y++;
        setconsole(xs); cout<<"  ";
    }
}
void showObject2(int x){
    COORD xs;
    xs.Y=7; xs.X=x;
    setcolor(0,red);
    setconsole(xs); cout<<"  "; setcolor(3); cout<<"  "; setcolor(0,red);
    xs.Y++; setconsole(xs); cout<<"  "; setcolor(3); cout<<"  "; setcolor(0,red);
    xs.Y++; setconsole(xs); cout<<"  "; setcolor(3); cout<<"  ";

    if(x==0){
        setcolor(0);  xs.Y=7;
        setconsole(xs); cout<<"  "; xs.Y++;
        setconsole(xs); cout<<"  "; xs.Y++;
        setconsole(xs); cout<<"  ";
    }
}
int main(){
    int point=0,del=0;
    int key,frame=0,frame2=0,frame3=0;
    bool nextKey=true,inc=false;
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    dino.X=8; dino.Y=8; last=dino;
    setcolor(136);
    cout<<"                                                                                     ";
    cout<<"                       "; jumpBox(0);
    while(1){
        if(nextKey){
                while(kbhit()){
                    key=getch();
                    if(key==UP && nextKey) {nextKey=false; inc=true;}
                    if(key==RIGHT) frame2=118;
                    if(key==LEFT) frame3=118;
                }
        } else {
            if(del==0){
                if(inc) jumpBox(frame++);
                else jumpBox(frame--);
                if(frame==-1) { nextKey=true; frame=0;}
                if(frame==4) inc=false;
                del=2;
            }
            del--;
        }
        if(frame2!=0)   showObject1(frame2--);
        if(frame3!=0)     showObject2(frame3--);
        showValue(point++);
        wait(50);
    }
}
