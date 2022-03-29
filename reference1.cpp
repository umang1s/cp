#include<iostream>
using namespace std;
class c1
{
    int id;
public:
    int i;
    c1(int i);
    ~c1();
    void neg(c1 &o) {o.i = -o.i; }  //  no temporary created
};
c1::c1(int num)
{
    cout<< " Constructing "<<num<<"\n";
    id = num;
}
c1::~c1()
{
    cout<<" Destructing "<<id <<"\n";
}
int main()
{
    c1 o(1);
    o.i = 10;
    o.neg(o);
    cout<<o.i<<"\n";
    return 0;
}
// we can use return reference like this int &name(int num){}
