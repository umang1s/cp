#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    cout<<hex<<100<<endl;
    cout<<setfill('?')<<setw(10)<<2343.4<<endl;;
    cout.setf(ios::hex, ios::basefield);
    cout<<100<<endl;
    cout.fill('*');
    cout.width(10);
    cout<<324.43<<endl;
    cout<<332<<endl;
    cout<<setiosflags(ios::showpos);
    cout<<setiosflags(ios::showbase);
    cout<<123<<endl<<hex<<123<<endl;
    //using boolalpha
    bool b=true;
    cout<<b<<"  "<<boolalpha<<b<<endl;
    cin>>boolalpha>>b; //for taking boolapha
    cout<<"here is what you enterd :  "<<b<<endl;
}
