#include"umang.h"
using namespace std;
class Box{
public:
    int color,locX,locY;
    bool filled;
    Box(int c=0,int l=0,int y=0,bool fil=false){
        color=c; locX=l; locY=y; filled=fil;
    }
};
Box box[10][20],str[7];
char key='a';
bool lock=false;
int lastColor=1;
int boxNumber=1;
void squareBox(int x,int y,int color,int fo=red){
    setcolor(color,fo);
    char a=178;
    setConsole(x,y++);
    cout<<a<<a<<a<<a;
    setConsole(x,y);
    cout<<a<<a<<a<<a;
    setConsoleNormal();
}
void deleteStructure(){
    for(int i=0; i<7; i++){
        if(str[i].filled){
            squareBox(str[i].locY,str[i].locX,black,black);
        }
    }
}
void showStucture(){
    for(int i=0; i<7; i++){
        if(str[i].filled){
            squareBox(str[i].locY,str[i].locX,str[i].color);
        }
    }
}
void destroy(int from ,int till){
    //destroy and upper will be fall down
}
void loadMaps(){

}
bool gameOver(){
    //if new stucture has no
    return false;
}

bool reachedAtMax(){
    int z=0;
    int temp=0,temp1=0;
    for(int i=0; i<7; i++){
        if(str[i].filled){
            temp=str[i].locX+1;temp1=str[i].locY;
            if(!box[temp][temp1].filled) z++;
        }
    }
    if(z==boxNumber) return true;
    return false;
}
bool horizontalFilled(){
    //check horizontal filled
}
void deleteHorizontal(){

}
void falldown(){
    deleteStructure();
    for(int i=0; i<7; i++){
        if(str[i].filled){
            str[i].locX++;
        }
    }
    showStucture();
    wait(300);
}
void createNewStructure(){

    //first reset all structure
    for(int i=0; i<7; i++) str[i].filled=false;
    lastColor++;
    if(lastColor==10) lastColor=1;
    int j=0;///rand()%10;
    int pos=rand()%5;

    //create new structre and fill
    //  0000    000     00  0   00  00  000      0      0000    0000
    //                           0  0    0      000        0    0
    //create a temp
    switch(j){
        case 0:  Box temp(lastColor,pos+4,1,true);
                str[0]=temp;
                break;
    }

    showStucture();
}
void changeStructure(char k){
    //check first stucture
    //check left empty
    bool movable=false;
    if(k==LEFT){
        for(int i=0; i<7; i++){
            if(str[i].filled){
                    lastColor++;
            }
        }
        if(movable)for(int i=0; i<7; i++){
                if(str[i].filled)   str[i].locX--;
        }
        showStucture();
    } else if(k==RIGHT){
        //for checking
    } else if(k==UP){
        //for turn
    }
}
void gameProgress(){
    char k;
    lock=false;
    while(!gameOver()){
        while(!kbhit()){
            if(lock){
                if(!reachedAtMax()){
                    lock=false;
                    for(int i=0; i<7; i++){
                        //if(str[i].filled) box[str]
                    }
                    if(horizontalFilled())  deleteHorizontal();
                } else falldown();
            } else{
                createNewStructure();
                lock=true;
            }
        }
        k=getch();
        changeStructure(k);
    }
}
void showgameOver(){
    //game over message and next (20,5)
}


int main()
{
    char option='A';
    while(option!='Q'){
        makePartition();
        setConsole(20,10);
        cout<<"press any key to continue    Q for exit  ";
        option=getch();
        if(option!='Q'){
            loadMaps();
            gameProgress();
            showgameOver();
        }
    }
}
