//      this is parameterized Constructors
#include<iostream>
using namespace std;
class add
{
    int num1,num2;
public:
    add(int i,int j)    // this is parameterized constructors
    {
        num1=i; num2=j;
    }
    int Value()
    {
        return num1+num2;
    }
};
int main()
{
    add a(4,6);     //we can write this add a = add(4,6);
    cout<<a.Value();
}
