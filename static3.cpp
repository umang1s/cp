#include<iostream>
using namespace std;
class Counter
{
public:
    static int store;
    Counter()    {store++;} //constructor
    ~Counter()  {store--;}  //distructor
};
int Counter::store; //define store
void func()
{
    Counter temp;
    cout<<" Objects in existence :"<<Counter::store<<endl;
    //temp is destroyed when func() returns
}
int main()
{
    Counter a1;
    cout<<" Objects in existence : "<<Counter::store<<endl;
    Counter a2;
    cout<<" Objects in existence : "<<Counter::store<<endl;
    func();
    Counter a3;
    cout<<" Objects in existence : "<<Counter::store<<endl;
    return 0;
}
