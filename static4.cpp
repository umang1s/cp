//  static member use
#include<iostream>
using namespace std;
class add
{
    static int num1,num2;
public:
    static void SetNum(int i, int j)
    {
        num1=i; num2=j;
    }
    void display()
    {
        cout<<" num1 : "<<num1<<" num2  : "<<num2<<"  num3  "<<num1+num2<<endl;
    }

};
int add::num1;
int add::num2;
int main()
{
    add Add;
    Add.display();
    Add.SetNum(32,34);
    Add.display();
    // or other word
    add::SetNum(12,345);
    add j;
    j.display();
    Add.display();
}
