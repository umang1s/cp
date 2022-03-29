#include<iostream>
#include<cstring>
using namespace std;

typedef struct coord{
    double x;
    double y;
} Coord;

string converting(Coord z){
    char manager[90]="1234567890poiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ@#%$&=-_";
    char ret[50];
    int l=0,y[13],filled=1;
    int xx=z.x*1000000,yy=z.y*1000000;

    if(xx>0 && yy>0) ret[0]='W';
    else if(xx<0 && yy>0) {ret[0]='A'; xx*=-1;}
    else if(xx>0 && yy<0) {ret[0]='D'; yy*=-1;}
    else {ret[0]='S'; xx*=-1; yy*=-1;}

    l=0;
    while(xx>70){
        y[l++]=xx%70;
        xx/=70;
    }
    y[l++]=xx;

    while(l!=0) {
            ret[filled++]=manager[y[l-1]];
            l--;
    }

    cout<<ret<<endl;

    while(yy>70){
        y[l++]=yy%70;
        yy/=70;
    }
    y[l++]=yy;
    while(l!=0) {ret[filled++]=manager[y[l-1]]; l--;}

    return ret;
}
Coord deConvert(string z){
    Coord p;
    char manager[90]="1234567890poiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ@#%$&=-_";

    return p;
}
int main(){
    Coord p;
    int q=0;
    char pxx[15];
    while(q!=6){
        cout<<"choose option for do next 1.... 2......6............."<<endl;
        cin>>q;
        if(q==1){
            cout<<"enter the First Coordinates :  ";
            cin>>p.x;
            cout<<"enter the seconds Coordinate :  ";
            cin>>p.y;
            cout<<endl<<converting(p)<<endl<<endl;
        } else if(q==2){
            cout<<"enter the code : ";
            cin>>pxx;
            Coord l=deConvert(pxx);
            cout<<l.x<<"  "<<l.y<<endl;
        }

    }
}
