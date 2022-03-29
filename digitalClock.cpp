#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<time.h>
#include"graphic.h"
#include<ctime>
using namespace std;
int M=0;    // 0 for AM
int color=red;
COORD coord;
int param=1;
int today()
{
    system("CLS");
    int ks;
    cout<<"Please enter today date dd/mm/yy format";
    return 1;

}
int takeTime()
{
    int ks=today();
    time_t current_time;
    time(&current_time);
    int t;
    t=current_time-1576800000;
    t-=(3600*24*145);
    t-=ks;
    t+=19800;
    if(t>43200) M=1;
    return t;
}
void cleanArea(COORD a)
{
    int x,y;
    x=6*param+1;
    y=5*param +2;
    for(int i=0; i<y; i++)
    {
        setconsole(a);
        for(int j=0; j<x; j++ ) cout<<" ";
        a.Y++;
    }
}
COORD hrs1,hrs2,sec1,sec2,min1,min2,sqr1,sqr2;
void showTime(int sec,int mint,int hrs)
{
    system("CLS");
    COORD sr1=sqr1,sr2=sqr2;
    SevenSegment(hrs1,hrs/10,color,param);
    SevenSegment(hrs2,hrs%10,color,param);
    SevenSegment(min1,mint/10,color,param);
    SevenSegment(min2,mint%10,color,param);
    SevenSegment(sec1,sec/10,color,param);
    SevenSegment(sec2,sec%10,color,param);
    setcolor(color,color);
    for(int i=0; i<param; i++) { setconsole(sr1); for(int j=0; j<param; j++) cout<<"  "; sr1.Y++;}
    sr1.Y+=param*2;
    for(int i=0; i<param; i++) { setconsole(sr1); for(int j=0; j<param; j++) cout<<"  "; sr1.Y++;}
    for(int i=0; i<param; i++) { setconsole(sr2); for(int j=0; j<param; j++) cout<<"  "; sr2.Y++;}
    sr2.Y+=param*2;
    for(int i=0; i<param; i++) { setconsole(sr2); for(int j=0; j<param; j++) cout<<"  "; sr2.Y++;}
    setcolor(7);
}
void showTsec(int sec)
{
    cleanArea(sec2);
    if(sec%10) SevenSegment(sec2,sec%10,color,param);
    else
    {
        cleanArea(sec1);
        SevenSegment(sec1,sec/10,color,param);
        SevenSegment(sec2,sec%10,color,param);
    }
}
void showMint(int mins)
{
    cleanArea(min2);
    if(mins%10) SevenSegment(min2,mins%10,color,param);
    else
    {
        cleanArea(min1);
        SevenSegment(min1,mins/10,color,param);
        SevenSegment(min2,mins%10,color,param);
    }
}
void showHrs(int hrs)
{
    cleanArea(hrs2);
    if(hrs%10) SevenSegment(hrs2,hrs%10,color,param);
    else
    {
        cleanArea(hrs1);
        SevenSegment(hrs1,hrs/10,color,param);
        SevenSegment(hrs2,hrs%10,color,param);
    }
}
void updatePosition()
{
    hrs1=hrs2=sec1=sec2=min1=min2=sqr1=sqr2=coord;
    int a=param*8+1,b=param*13+1,c=param*2;
    hrs2.X+=a;
    min1.X=hrs2.X+b;
    min2.X=min1.X+a;
    sec1.X=min2.X+b;
    sec2.X=sec1.X+a;
    sqr1.X=hrs2.X+a;
    sqr2.X=min2.X+a;
    sqr1.Y+=param;
    sqr2.Y+=param;
}
int main()
{
    int mins,sec,hrs;
    int Time=takeTime();
    hrs=Time/3600;
    Time%=3600;
    mins=Time/60;
    sec=Time%60;
    if(hrs>12) {M=1; hrs-=12;}
    coord.X=15; coord.Y=15;
    updatePosition();
    COORD ls; ls.X=0; ls.Y=0;
    int update;
    while(1)
    {
        while(!kbhit())
        {
            sec++;
            if(sec>60)  {  mins++; sec=0; showMint(mins); }
            if(mins>60) {  hrs++;  mins=0; showHrs(hrs); }
            if(hrs>12)     hrs-=12;
            showTsec(sec);
            setconsole(ls);
            Sleep(900);
            //getch();
        }
        update=getch();
        if(update==LEFT){param--;  if(param==0) param=1;}
        else if(update==RIGHT){param++; if(param==11) param=10; }
        else if(update==UP){color++; if(color==16) color=15; }
        else if(update==DOWN) {color--; if(color==0) color=1;}
        updatePosition();
        showTime(sec,mins,hrs);

    }

}
