#include<iostream>
using namespace std;
int main()
{
    cout.precision(4);
    cout.width(10);
    cout<<234.43<<endl; //here it is implemented
    cout.fill('*');
    cout.width(10);
    cout<<234.43<<endl;
    cout.width(10);
    cout<<"heybuddy"<<endl;
    cout.width(10);
    cout.setf(ios::left);
    cout<<10.2343;
    return 0;
}
