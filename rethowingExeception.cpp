#include<iostream>
using namespace std;
void don()
{
    try{throw"Hello";}
    catch(const char*)
    {
        cout<<"caught char "<<endl;
        throw;
    }
}
int main()
{
    cout<<"Start\n";
    try
    {
        don();
    }
    catch(const char *)
    {
        cout<<"cought char inside main "<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}
