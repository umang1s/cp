#include<iostream>
#include"graphic.h"
using namespace std;

int line=0;
void print(char *x){
    COORD x11;
    line++;
    int ls=line;
    if(line>30) ls=line%30;
    x11.X=70; x11.Y=2+ls;
    setconsole(x11);
    cout<<line<<"  "<<x;
}
bool compare(char *x,char *y){
    int k=0;
    if(strlen(x)==strlen(y)){
        for(int i=0; i<strlen(x); i++){
            if(x[i]==y[i]) k++;
        }
        if(k=strlen(x)-1) return true;
    }
    return false;
}
void initState(){print("initState"); }
class StatefulWidget{

};

class StatelessWidget{

};

class Screen{
    bool Drawer=false;
    bool AppBar=false;
    bool BottomNamvigation=false;
    int bgc=red;
    int  height=25,width=30;
    Screen(){
        COORD z001,coord1;
        coord1.X=30; coord1.Y=1;
        setcolor(0,bgc);
        setconsole(z001);
        for(int i=0; i<width; i++) cout<<" ";
        for(int i=0; i<height; i++){
            cout<<" ";
            z001.Y++;
            setconsole(z001);
        }
        z001=coord1;
        z001.X=width;
        for(int i=0; i<height; i++){
            cout<<" ";
            z001.Y++;
            setconsole(z001);
        }
        z001=coord1;
        z001.Y=height;
        for(int i=0; i<width; i++) cout<<" ";
    }
public:
    void drawer(){
        Drawer=true;
    }

    //screen show
    void show(){

    }
};
class String{
    char val[1000];
    String(char *pz){for(int i=0; i<strlen(pz); i++) val[i]=pz[i];}
    ~String(){}
    int length(){
        return strlen(val);
    }
    void add(char *x){
        int i=strlen(val);
        for(int j=0; j<strlen(x); j++) val[i+j]=x[j];
    }
};
