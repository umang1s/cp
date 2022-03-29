#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

vector<vector<int>> textData;
int disk=3;

void textDisplay();
void display(bool);
void towerOfHanoi(int,int,int,int);

int main(){
    towerOfHanoi(disk,3,1,2);
    //textDisplay();
    display(false);
}

void textDisplay(){
    for(auto i:textData) cout<<i[1]<<"--"<<i[0]<<"-->"<<i[2]<<endl;
}

void towerOfHanoi(int disk,int dest,int src,int aux){
    if(disk==1){
        textData.push_back({disk,src,dest});
        return ;
    }
    towerOfHanoi(disk-1,aux,src,dest);
    textData.push_back({disk,src,dest});
    towerOfHanoi(disk-1,dest,aux,src);
}

vector<int> disp[3];
void printDisk(int x){
    int len=7;
    for(int i=0; i<len-x; i++) cout<<' ';
    for(int i=0; i<x; i++) cout<<char(174);
    cout<<char(5);
    for(int i=0; i<x; i++) cout<<char(175);
    for(int i=0; i<len-x; i++) cout<<' ';
}
void makeDisplay(){
    vector<vector<int>> temp(3,vector<int>(disk,0));
    for(int j=0; j<3; j++){
        int bottom=disk-1;
        for(int i=0; i<disp[j].size(); i++) temp[j][bottom--]=disp[j][i];
    }

    cout<<endl;
    for(int i=0; i<3;i++) {printDisk(0); if(i<2) cout<<"   ";}
    cout<<endl;
    for(int i=0; i<disk; i++){
        printDisk(temp[0][i]);
        cout<<"   ";
        printDisk(temp[1][i]);
        cout<<"   ";
        printDisk(temp[2][i]);
        cout<<endl;
    }
    int len=7;
    for(int i=0; i<3; i++){
        for(int j=0; j<len; j++) cout<<char(205);
        cout<<char(202);
        for(int j=0; j<len; j++) cout<<char(205);
        cout<<"   ";
    }
    cout<<endl;
}
void printDiskAt(int x,int y,int len){
    //this will print disk to thir position
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    int p=7;
}
void animate(int src,int dest,int length){
    unsigned int sleep=100;
    //get position of top element

    //lift it to top

    //move it to right


    //get position of top element of destination

    //put down it to top
    //_sleep(sleep);
    //system("cls");
    
    //cout<<setw(10)<<"-";
}

void display(bool inAnimation=true){
    for(int i=disk; i>0; i--) disp[0].push_back(i);
    makeDisplay();
    //if(inAnimation) system("cls");
    for(auto i:textData){
        disp[i[1]-1].pop_back();
        if(inAnimation) animate(i[1]-1,i[2]-1,i[0]);
        disp[i[2]-1].push_back(i[0]);
        if(!inAnimation) makeDisplay();
    }
    //if(inAnimation)_sleep(20000);
    //if(inAnimation) system("cls");
}





