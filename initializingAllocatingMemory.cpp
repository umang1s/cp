#include<iostream>
using namespace std;
int main()
{
    int *p;
    try
    {
        p = new int (86);  //initialize to 87
    }catch(bad_alloc xa)
    {
        cout<<"Allocation Failure \n";
        return 1;
    }
    cout<<"At "<<p<<" ";
    cout<<"is the value "<<*p<<endl;
    delete p;
    return 0;
}
