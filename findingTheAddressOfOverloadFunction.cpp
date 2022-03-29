#include<iostream>
using namespace std;
int myfunc(int a);
int myfunc(int a, int b);
int main()
{
    int (*fp)(int a);   //pointer to int f(int) and this is for first
    fp=myfunc;
    int (*fs) (int l,int m) ; //for second overloaded
    fs = myfunc;        // points to myfunc (int)
    cout<<fp(5);
    cout<<endl<<fs(5,4);
    return 0;
}
int myfunc(int a)
{
    return a;
}
int myfunc(int a , int b)
{
    return a*b;
}
