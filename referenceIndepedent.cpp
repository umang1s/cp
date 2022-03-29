#include<iostream>
using namespace std;
int main()
{
    int a;
    int &j=a;  // indepedent reference
    a=10;
    cout<<a<<"     "<<j<<endl;
    j=12;
    cout<<a<<"     "<<j<<endl;
    int k=23;
    j=k;        // this put k's value in j;
    cout<<a<<"      "<<j<<"    "<<k<<endl;
    j--;
    cout<<a<<"      "<<j<<"    "<<k<<endl;
}
