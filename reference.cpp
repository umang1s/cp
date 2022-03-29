#include<iostream>
using namespace std;
void negative(int *x)   // this is passing call by value
{
    *x =-*x;
}
void Negative(int &z)   // this is reference
{
    z=-z;
}
int main()
{
    int z=90;
    negative(&z);
    cout<<"value of negative by value is :"<<z<<endl;
    Negative(z);
    cout<<" value of Negative by reference is : "<<z<<endl;
}
