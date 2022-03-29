//      use of static
#include<iostream>
using namespace std;
class mult
{
    public:
    static int a;
    int b;

    void SetData(int i, int j)
    {
        a=i; b=j;
    }
    void Mult();
};
int mult::a;    //define a
void mult::Mult()
{
    cout<<"answer is : "<<a<<"   "<<b<<endl;
}
int main()
{
    mult u,b;
    u.SetData(12,10);   //  a=12 and b=10
    b.SetData(13,23);   // a=12 and b=23
    u.SetData(34,12);   // a=34 and b=12
    cout<<" values of 12,10"<<endl;
    u.Mult();   //  a=34    b=12    a will be last changes
    b.SetData(14,34);   // a=14 and b=34
    cout<<" values of 14,34"<<endl;
    b.Mult();
    cout<<"now value of 12,10"<<endl;
    u.Mult();
    cout<< " we can initialize static in main";
    mult::a=290;
    cout<<"\nafter initilizing a=290 "<<mult::a<<" " <<u.a<<endl;
    mult j;
    cout<<" this is j.a : "<<j.a<<endl;
}
