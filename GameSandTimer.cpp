#include<iostream>
#include"graphic.h"
using namespace std;
class GameSandTimer
{
    int sec,height=5,width=50;   //height , width are for half box
    int x=5, y=5;   //for initial position
public:
    GameSandTimer(int k){sec=k;}
    void setTimer(int k){sec=k;}
    void makeTimer();
    //void showTimer(int x=sec);
    //void setPosition(int x, int y);
};
void GameSandTimer::makeTimer()
{
    int border=16, sand=48,normal=7;
    for(int i=0; i<y; i++) cout<<endl;
    for(int i=0; i<x; i++) cout<<" ";
    setcolor(border);
    for(int i=0; i<width; i++) cout<<" "; cout<<endl;
    for(int i=1; i<height; i++)
    {
        setcolor(normal);
        for(int k=0; k<x; k++) cout<<" ";
        setcolor(border);
        cout<<" ";
        setcolor(sand);
        for(int j=width; j>2; j--)
        {
            cout<<" ";
        }
        setcolor(border);
        cout<<" \n";
    }
}
int main()
{
    GameSandTimer x(5);
    x.makeTimer();
}
