#include<iostream>
using namespace std;
void Xtest(int test)    //try throw outside the class
{
    if(test) throw test;
}
int main()
{
    cout<<" Lets begain "<<endl;
    try{throw 100;}
    catch(int i)
    {
        cout<<i<<endl;
    }
}
