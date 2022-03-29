#include<iostream>
using namespace std;
class convert
{
protected:
    double val1;    //initial value
    double val2;    //converted value
public:
    convert(double i)       {val1= i;}
    double getConv() {return val2; }
    double getInit() {return val1;}
    virtual void compute() = 0; //using virtual function
};
class LitersToGallons:public convert
{
public:
    LitersToGallons(double i):convert(i) {}
    void compute()  {   val2 = val1/3.7854; }
};
class FahrenheitToCelsius:public convert
{
public:
    FahrenheitToCelsius(double i) : convert(i) {}
    void compute() {val2 = (val1-32)/1.8;}
};
int main()
{
    convert *p;     //point to base class
    LitersToGallons r(34);
    FahrenheitToCelsius q(50);
    // using virtual function to convert
    p=&r;
    cout<<p->getInit()
}
