#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double x,y,z;
    cout<<"enter the number "<<endl;
    cin>>x;
    y = modf(x, &z);
    cout<<y<<"   "<<z<<endl;
}
