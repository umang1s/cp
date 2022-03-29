//  this is use of friend class
//  keep in mind friend member and friend class are different
#include<iostream>
using namespace std;
class Addition
{
    int num1,num2;
public:
    void GetValue(int a,int b)
    {
        num1=a; num2=b;
    }
    friend class Add;
};
class Add
{
public:
    int answer(Addition u)
    {
        return u.num1+u.num2;
    }
};
int main()
{
    cout<<"enter two number : ";
    int num1,num2;
    cin>>num1>>num2;
    Addition number;
    number.GetValue(num1,num2);
    Add total;
    cout<<endl<<" answer is : "<<total.answer(number)<<endl;
}

