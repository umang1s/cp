#include<iostream>
using namespace std;
class x
{
private:
    int p;
public:
    int i;
};
class xx: private x //inherit x as a private
{
public:
    x::i;   // make i public again
    //x::p;  we can't this access
};
int main()
{
    xx u;
    //u.p=7;    illegal because it is private
    u.i=8;      //legal because it is public in xx
}
