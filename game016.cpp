#include<iostream>
#include"graphic.h"
using namespace std;
int maps[10][20];
char key='a';
void loadMaps(){
    for(int i=0; i<10; i++) for(int j=0; j<20; j++) maps[i][j]=-1;
    setconsole()
    //draw a squar box
    //and than set all charecter
}
void gameProgress(){

}
bool gameOver(){
    return false;
}
void showgameOver(){
}

int main()
{
    char option='A';
    while(option!='Q'){
        cout<<"\n\n\n\n\n\n\t\tpress any key to start game and Q for exit\n";
        option=getch();
        if(option!='Q'){
            loadMaps();
            gameProgress();
            showgameOver();
        }
    }
}
