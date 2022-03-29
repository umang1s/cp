#include<iostream>
using namespace std;
int main()
{
    int *p;
    try { p = new int;} catch(bad_alloc xa)
    {
        cout<<" Allocation Failure \n";
        return 1;
    }
    *p=100;
    cout<<"  AT  "<<p<<"   ";
    cout<<" is the value  "<<*p<<endl;
    delete p;
    return 0;
}
