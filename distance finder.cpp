#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double x1,y1,x2,y2,result;
    int x=1;
    while(1){
        cout<<"enter your number   ";
        cin>>x1>>y1>>x2>>y2;
        x1-=x2; y1-=y2;
        x1*=x1; y1*=y1;
        result=x1+x2;
        result=sqrt(result);
        cout<<x++<<"  "<<result<<endl;
    }
}
