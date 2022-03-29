#include<iostream>
using namespace std;
template <class Y>void swaps(Y &a, Y &b)
{
    Y temp;
    temp =a;
    a=b;
    b=temp;
}
// second example
template <class a, class b> void show(a c, b d)
{
    cout<<c<<" "<<d<<endl;
}
int main()
{
    int i=10, j=20;
    double x=10.1 , y=23.3;
    char a='s' , b='t';

    cout<<"Original i,j:"<<i<<" "<<j<<endl;
    cout<<"Original i,j:"<<x<<" "<<y<<endl;
    cout<<"Original i,j:"<<a<<" "<<b<<endl;
    swaps(i,j);
    swaps(x,y);
    swaps(a,b);

    cout<<"final i,j:"<<i<<" "<<j<<endl;
    cout<<"final i,j:"<<x<<" "<<y<<endl;
    cout<<"final i,j:"<<a<<" "<<b<<endl;
    cout<<" multiple ttype "; show(i,j);    //in second example
}
