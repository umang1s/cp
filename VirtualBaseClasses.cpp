#include<iostream>
using namespace std;
class base
{
public:
    int i;
};
class sec1:public base  // class sec1: virtual public base // than not showing ambiguous
{
public:
    int j;
};
class sec2:public base
{
public:
    int k;
};
class last:public sec1,public sec2
{
public:
    int p;
};
int main()
{
    last q;     // written down is problem
    //q.i=5;    it shows error because ambiguous we write this q.sec1::i=5
    q.sec1::i=5;
    q.j=6;
    q.k=66;
}
