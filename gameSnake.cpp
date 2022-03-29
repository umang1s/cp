#include<iostream>
#include"graphic.h"
#include<conio.h>
using namespace std;
typedef struct StoreCoord{COORD coord;}scd;
scd snake[100];
COORD food,normal,FOOd[100];
int top=1,bottom=0,upperArray=100,Food=0,FooD=0;
void printting(bool sod,int value)
{
    setconsole(snake[value].coord);
    if(sod)    {setcolor(0,red); cout<<"  "; }
    else  { setcolor(0,yellow); cout<<"  "; }
    setcolor(7);
    setconsole(normal);
     //wait(1000);
}
void fillFood()
{
    ///int LeftBorder=5,RightBorder=103,UpBorder=1,DownBorder=27;
    int xxx[100]={7,79,15,43,91,51,101,67,31,83,27,39,71,99,19,37,73,53,87,39,91,75,57,39,37,95,49,93,23,37,75,59,61,89,9,//35
    47,83,57,79,13,19,99,23,45,73,91,31,69,21,53,71,89,33,57,27,89,37,43,47,79,31,35,49,07,81,31,45,67,93,59,101,55,77,99,33,//75
    59,19,39,27,75,91,47,29,59,71,47,39,21,59,33,89,11,57,37,39,89,07,47,89,29};
    int yyy[100]={7,9,10,21,15,25,16,26,23,8,18,20,11,9,23,6,21,25,10,23,19,9,12,16,9,21,24,15,19,20,10,18,14,16,22,17,24,19,18,
    21,8,15,20,17,13,19,25,26,21,15,15,23,19,20,8,21,26,14,17,12,23,19,7,20,21,16,8,19,25,20,8,13,19,21,11,23,8,11,16,26,22,18};
    for(int i=0; i<100; i++)
    {
        FOOd[i].X=xxx[i]; FOOd[i].Y=yyy[i];
    }
}
bool checkBordering(COORD Mouth)
{
    int LeftBorder=5,RightBorder=103,UpBorder=1,DownBorder=27;
    if(Mouth.X<=LeftBorder || Mouth.X>=RightBorder || Mouth.Y<=UpBorder || Mouth.Y>=DownBorder) return true;
    return false;
}
bool checkSelfEating(COORD mouth)
{
    int i=top,j=bottom;
    while(i==j)
    {
        if(mouth.X==snake[j].coord.X && mouth.Y==snake[j].coord.Y) return true;
        else
        {
            if(i<j) j--;
            else j++;
        }
        if(j==upperArray) j=0;
    }
    return false;
}
void storringMouth(COORD mouth)
{
    snake[top++].coord=mouth;
    if(top==upperArray) top=0;
}
void makeNewFood()
{
    int x,y;
    food=FOOd[FooD++];
    if(FooD==80) FooD=0;
    setcolor(0,red);
    setconsole(food);
    cout<<"  ";
    setconsole(normal);
    setcolor(7);
    cout<<"1";
}
bool foodEated(COORD mouth)
{
    if(mouth.X==food.X && mouth.Y==food.Y){    makeNewFood(); Food++;  return true;}
    bottom++;
    if(bottom==upperArray) bottom=0;
    printting(false,bottom-1);
    return false;
}
void updateAllValue()
{
    COORD first;
    first.X=5; first.Y=28;
    setconsole(first);
    cout<<"Score : "<<Food;
    setconsole(normal);
}
bool gameCrash(COORD mouth)
{
    storringMouth(mouth);
    printting(true,top-1);
    if(checkBordering(mouth)) return true;
    if(checkSelfEating(mouth)) return true;
    if(foodEated(mouth)) ;
    updateAllValue();
     return false;
}
int main()
{
    rect(5,1,10,yellow,100,27);
    COORD mouth;
    mouth.X=21;
    mouth.Y=15;
    fillFood();
    char direction=RIGHT;
    makeNewFood();
    snake[0].coord.X=15; snake[0].coord.Y=15;
    while(!gameCrash(mouth))
    {
        while(kbhit())
        {
           direction=getch();
        }
        if(direction==UP) mouth.Y--;
        else if(direction==DOWN) mouth.Y++;
        else if(direction==LEFT) mouth.X-=2;
        else if(direction==RIGHT) mouth.X+=2;
        else ;
         wait(100);

    }
}
