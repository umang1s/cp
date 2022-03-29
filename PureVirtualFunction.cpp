#include<iostream>
using namespace std;
class number
{
protected:
    int j;
public:
    void setVal(int i) {j=i;}
    virtual void show() = 0;        //this show pure virtual function
};
class hextype : public number
{
public:
    void show()
    {
        cout<<"Hex "<<j<<endl;
    }
};
class dectype: public number
{
public:
    void show()
    {
        cout<<"Dec  "<<j<<endl;
    }
};
class octtype: public number
{
public:
    void show()
    {
        cout<<" Oct "<<j<<endl;
    }
};
int main()
{
    dectype d;
    octtype o;
    hextype h;
    d.setVal(20);
    d.show();
    h.setVal(23);
    h.show();
    o.setVal(24);
    o.show();
}
