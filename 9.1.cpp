#include<iostream>
#include<cmath>
using namespace std;
class shape
{
protected:
    double a1,a2;
public:
    void get_data(int a,int b)
    {
        a1=a; a2=b;
    }
    virtual void displayArea()=0;   //this is pure virtual function
};
class Rectangle:public shape
{
public:
    void displayArea()
    {
        cout<<"area of rectangle : "<<(a1*a2)<<endl;
    }
};
class Triangle:public shape
{
public :
    void displayArea()
    {
        cout<<"area of trianlge : "<<(a1*a2*0.5)<<endl;
    }
};
int main()
{
    Rectangle x;
    Triangle p;
    p.get_data(4,5);
    x.get_data(3,5);
    x.displayArea();
    p.displayArea();
}
