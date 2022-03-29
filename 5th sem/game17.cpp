#include<iostream>
#include"umang.h"
using namespace std;
int maxXu,maxXb,maxYl,maxYR;
class Box{
    int color[4];
    int filled=0;
    int positionX=0,positionY=0;
    int number=0;
    bool isSelected=false;
public:
    Box(int bottom=0,int bott=0,int to=0,int top=0){
        color[0]=top; color[1]=to; color[2]=bott; color[3]=bottom;
        if(bottom!=0) filled++;
        if(bott!=0) filled++;
        if(to!=0) filled++;
        if(top!=0) filled++;
    }
    void selected(bool which){
        isSelected=which;
        showBox();
    }
    void boxPosition(int X,int Y){
        positionX=X; positionY=Y;
    }
    void setNumber(int X){number=X;}
    bool fillColor(int temp){
        //show animation
        if(filled==4) return false;
        if(filled==0){
            color[filled++]=temp;
            return true;
        }
        if(color[filled]==temp){
            color[filled++]=temp;
            return true;
        } else return false;
    }
    void dropColor(){

    }
    void showBox(){

    }
};

bool showAnimation(Box first,Box second){
    //check color if available than animate other wise don't///////////////

}
int lastLevel(bool getLevel){
    if(getLevel){
        return 1; //last level
    }
    //set last level
    return 0;
}
void gameStart(int boxn,int level){
    Box box[boxn];
    //get level map
    //assign box coordinate
    //fill color
    //show box
    while(check)//take input and progress game

    //if game complete lastlevel false


}
int main(){gameStart(getLastLevel(true));}
