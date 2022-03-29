#include<iostream>
using namespace std;
void converting(double ppp){
    char manager[90]="1234567890poiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ@#%$&=-_";
    char ret[50];
    int l=0,y[13],filled=0;
    int xx=ppp*1000000;


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
}

int main(){
    double x;
    while(1){
        cin>>x;
        converting(x);
    }
}
