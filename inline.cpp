//  use of inline function
//  it use for effecient code
#include<iostream>
using namespace std;
class Multiply
{
    int num1,num2;
public:
    void SetValue()
    {
        cout<<"enter the number to multiply : ";
        cin>>num1>>num2;
    }
    inline void mult()  // there is no need to define inline in class because it already assumed as inline funtion
    {
        cout<<" answer is : "<<num1*num2<<endl;
    }
};
class Addition
{
    int num1,num2;
public :
    void SetValue(int ,int);
    void GetResult();
};
inline void Addition::SetValue(int i,int j)     // defining inline outside
{
    num1=i; num2=j;
}
inline void Addition::GetResult()           // defining inline outside
{
    cout<<num1+num2<<endl;
}
int main()
{
    Multiply mult;
    mult.SetValue();
    mult.mult();
    Addition addd;
    addd.SetValue(23,43);
    addd.GetResult();
}
