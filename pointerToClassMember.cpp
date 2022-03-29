#include<iostream>
using namespace std;
class c1
{
public:
    c1(int i) {val=i;}
    int val;
    int doubleVal() {return val+val;}
};
int main()
{
    int c1::*data;  //data member to pointer
    int (c1::*func)();      //function member pointer
    c1 ob1(1),ob2(2);         // create objects
    data = &c1::val;        //get offset of val
    func = &c1::doubleVal;      // get offset of doubleval()

    cout<<"Here are values : ";
    cout<<ob1.*data<<"   "<<ob2.*data<<endl;
    cout<<"there double are here : ";
    cout<<(ob1.*func)()<<endl<<(ob2.*func)()<<endl;
}
