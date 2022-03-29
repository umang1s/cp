#include<iostream>
using namespace std;
void Hand(int test)
{
    try
    {
        if(test==0) throw test;
        if(test==1) throw 'a';
        if(test==2) throw 123.23;
    }
    catch(int i) {cout<<"integer "<<endl;}  // we can use like this
    catch(...) {cout<<"Caught one "<<endl;} // it handle all throw execpt int cause
                                            // integer has defined
}
int main()
{
    cout<<"lets begain"<<endl;
    Hand(1);
    Hand(2);
    Hand(0);
}
