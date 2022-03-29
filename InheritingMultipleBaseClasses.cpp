#include<iostream>
using namespace std;
class base1
{
protected:
    int a;
public:
    int set1(){ return a;}
};
class base2
{
protected:
    int b;
public:
    int set2(){return b;}
};
class derive:public base1, public base2
{
public:
    void set(int i, int j) {a=i; b=j;}
};
int main()
{
    derive ob;
    ob.set(12,34);
    cout<<ob.set1();
    cout<<endl<<ob.set2();
}
