// this is another program of static
#include<iostream>
using namespace std;
class name
{
    static int value;
public:
    int getValue();
    void ResetValue();
};
int name::getValue()
{
    if(value) return 0;     // value aready is in use
    else { value =1; return 1;} // value allocated to this opbject
}
int name::value;    //define value
void name::ResetValue()
{
    value=0;
}
int main()
{
    name a1,a2;
    if(a1.getValue()) cout<<"a1 has value "<<a1.getValue()<<endl;
    if(!a2.getValue()) cout<<" a2 denid value "<<a2.getValue()<<endl;
    a1.ResetValue();    //let someone else use it
    if(a2.getValue()) cout<< "a2 can now use value"<<a2.getValue()<<endl;
    return 0;
}
