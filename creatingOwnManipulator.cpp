#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
ostream &sethex(ostream &stream)
{
    stream.setf(ios::showbase);
    stream.setf(ios::hex, ios::basefield);
    return stream;
}
ostream &ra(ostream &stream) //in second example
{
    stream<<"------>";
    return stream;
}
ostream &la(ostream &stream)    //in seoond example
{
    stream<<"<----------";
    return stream;
}
istream &getpass(istream &stream )  //in third example
{
    cout<<'\a'; //sound bell
    cout<<"enter password : ";
    return stream;
}
int main()
{
    cout<<256<<"  "<<sethex<<256;
    cout<<"high balance "<<ra<<123.32<<endl;    //second example
    cout<<"over draft "<<ra<<322.43<<la<<endl;  //second example
    //in third example using istream
    char pw[80];
    do  {   cin>>getpass>>pw;   }
    while(strcmp(pw,"password"));
    cout<<"Logon complete "<<endl;
    return 0;
}
