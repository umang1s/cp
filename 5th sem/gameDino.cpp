#include<iostream>
#include<stdio.h>
#include"umang.h"
int velocity=5,ground=12;
bool footMove=false;
bool pause=false;
class Enemy{
public:
    int x,color,block[2][3];
    Enemy(int f1=0,int f2=0,int f3=0,int f4=0,int f4=0 ,int f5=0,int f6=0,int X=0,int c=0)
    {
         x=X; color=c;
         block[0][0]=f1; block[]
    }
};
void loadMaps()
{
    //loading road
    $$$
    $$$ $$
    setConsole(2,10);
    setcolor(green,black);
    char x=-33;
    for(int i=0; i<100; i++) cout<<x;
    setcolor(7);
}
void showEnemy(Enemy enemy)
{
    setConsole(enemy.x,9);
    setcolor(enemy.color);
    cout<<"###";
    setConsole(enemy.x+3,9);
    setcolor(7);
    cout<<"    ";
    setConsole(2,9);
    cout<<"   ";
    setConsole(102,10);
}
bool gameProgress()
{
    //if object is collided to dino than say game over
    return true;
}
void jumpDino(int position)
{
    if(position==6) return;

    int px,delet;// 012 3 456 0-9.1-8,2-7,3-6
    if(position<6){px=9-position; delet=px+1;}
    else{px=position-2; delet=px-1;}
    bool deleteNeeded=true;
    if(position==0 ) deleteNeeded=false;

    setConsole(8,px);
    setcolor(yellow);
    char cc=178;
    cout<<cc<<cc;
    setcolor(7);
    if(deleteNeeded){
       setConsole(8,delet);
        cout<<"  ";
    }
    setConsole(102,10);
}
Enemy getEnemy()
{
    Enemy en=Enemy(rand()%3,rand()%2,0,100,red);
    return en;

}
void startGame()
{
    int frame=1,jumpPosition=0;
    int point=0;
    char key;
    Enemy object[5];
    int currentEnemy=0;
    bool jumpCompletion=true;
    while(gameProgress()){
        while(!kbhit()){
            if(pause) getch();
            frame++;
            //if(point%20==0) velocity--;
            if( frame%velocity==0 && jumpPosition<ground ){
                jumpDino(jumpPosition++);

            }
            for(int i=0; i<5; i++){
                if(object[i].x>2){
                    object[i].x--;
                    showEnemy(object[i]);
                }
            }
            wait(10);
        }
        frame=1;
        if(jumpPosition==ground) jumpPosition=0;
        key=getch();
        if(rand()%2==0){
            for(int i=0; i<5; i++) if(object[i].x<3){object[i]=getEnemy(); point++;
                cout<<point; i=5;}
        }
    }
}
int main(){
    char key='a';
    while(key!='Q')
    {
        loadMaps();
        key=getch();
        if(key==SPACE) startGame();
    }
}
