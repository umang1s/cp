#include<iostream>
using namespace std;
void otherOverload()
{
    cout.setf(ios::hex , ios::basefield);   //basefield dec,oct,hex
    cout<<100<<endl;    //this display 64
}
void OtherOverload1()
{
    cout.setf(ios::showpos, ios::hex);  //error,showpos not set
    cout<<100<<endl;    //this will be not set to +100
    cout.setf(ios::showpos , ios::showpos); //this is correct
    cout<<100<<endl;    // this will show 100
}
void showflags()
{
    ios::fmtflags f;
    long i;
    f =  cout.flags();    //get flag settings
    for(i=0x4000; i; i=i>>1) if(i & f) cout<<"1"; else cout<<"0"; //check each flag
    cout<<endl;
}
ExaminingTheFormattingFlags()
{
    showflags();    //for showing default flag condition
    cout.setf(ios::right | ios::showpoint | ios::fixed);
    showflags();
    return 0;
}
void settingAllflags()
{
    cout<<endl;
    showflags();
    ios::fmtflags f= ios::showpos | ios::showbase | ios::oct | ios::right;
    cout.flags(f);  //set all flags
    showflags();
}
int main()
{
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);    //it shows positive
    cout<<100.0<<endl;
    cout.setf(ios::uppercase | ios::scientific);    // for showing in E formate
    cout<<100.12<<endl;
    cout.unsetf(ios::uppercase);    // clear uppercase
    cout<<100.12<<endl;
    cout.unsetf(ios::scientific);
    cout.unsetf(ios::showpos);
    cout.setf(ios::showpoint | ios::showpos , ios::showpoint);  // overload function
    cout<<100.0<<endl;
    otherOverload();
    OtherOverload1();
    ExaminingTheFormattingFlags();
    settingAllflags();
    return 0;
}
