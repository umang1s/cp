#include<iostream>
#include<cstdlib>
#include<exception>
using namespace std;
void my_Thandler()
{
    cout<<"Inside new terminate handler "<<endl;
    abort();
}
int main()
{
    set_terminate(my_Thandler);
    try{cout<<"inside try block "<<endl; throw 100;}
    catch(double i) {}
    return 0;
}
