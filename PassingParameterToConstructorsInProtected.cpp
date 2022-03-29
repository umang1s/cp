#include<iostream>
using namespace std;
class x1
{
protected:
    int a;
public:
    x1(int b){a=b; cout<<"x1C"<<endl;}
    ~x1(){cout<<"x1D"<<endl;}
};
class x2
{
protected:
    int b;
public:
    x2(int c){b=c; cout<<"X2C"<<endl;}
    ~x2(){cout<<"X2D"<<endl;}
};
class deri: public x1, public x2
{
    int p;
public:
    deri(int m, int n , int o):x1(n),x2(o)
    {
        p=m;
        cout<<"last c"<<endl;
    }
    ~deri() {cout<<"deco"<<endl;}
};
int main()
{
    deri(4,2,6);
}
