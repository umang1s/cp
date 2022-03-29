//  passing objects to function 08feb
#include<iostream>
using namespace std;
class myclass
{
    int i;
public:
    myclass(int j){i=j; cout<<"constructor\n";} //constructors
    ~myclass()      {cout<<"distructors\n";}
    void SetVal(int k) {i=k;}
    int GetVal() {return i;}
};
void fun(myclass n)
{
    cout<<"value of i is :"<<n.GetVal()<<endl;
}
int main()
{
    myclass lab(23);
    cout<<"value of lab : "<<lab.GetVal()<<endl;
    fun(lab);
}
