#include<iostream>
using namespace std;
void getDegreeInTime(int hrs,int mint=0,int sec=0){
    if(hrs>23 || hrs<0) cout<<"Error in hrs\n";
    else if(mint<0 || mint>59) cout<<"Error in minutes \n";
    else if(sec<0 || sec>59) cout<<"Error in seconds \n";
    else{
        if(hrs>12) hrs-=12;
        double secA=6*sec;
        double minA=sec/60 + mint*6;
        double hrsA=hrs*30 + mint*0.5 +sec*5/600 ;

        cout<<"Hrs to min : "<<minA-hrsA<<endl;
        cout<<"Hrs to sec : "<<secA-hrsA<<endl;
        cout<<"Min to sec : "<<secA-minA<<endl;
    }
}

int main(){
    int mint,sec,hrs;
    bool progress=true;
    while(progress){
        cout<<"For exit enter 99 99 99\nEnter Time hrs,min,sec  -->";
        cin>>hrs>>mint>>sec;
        if(hrs==99 && sec==99&& mint==99) progress=false;
        if(progress) getDegreeInTime(hrs,mint,sec);
        else cout<<"exiting.....";
        cout<<endl;
    }

}
