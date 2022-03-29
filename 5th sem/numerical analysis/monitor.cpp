#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int progress=0;
    double len,wid,dig,rat1,rat2,res1,res2;
    while(progress!=-1){
        cout<<"enter the Rectangle details\n Diagonal : ";
        cin>>dig;
        char c;
        if(dig!=-1){
            cout<<"enter length/width ratio : ";
            cin>>rat1>>c>>rat2;
            cout<<"enter length*width resolution : ";
            cin>>res1>>c>>res2;
            cout<<"Calculating.............................";
            double zzz=rat1/rat2;
            double res=zzz*zzz;
            res++;
            wid=dig/sqrt(res);
            len=wid*zzz;
            cout<<"Length : "<<len<<"   Width : "<<wid<<"  ppi : "<<len/res1<<endl;
        }else progress=dig;
    }
    cout<<"Exiting.....\n";
}
