#include<iostream>
#include<cstring>
using namespace std;
class phoneBook
{
public:
    char name[80];
    int areacode;
    int prefix;
    int num;
    phoneBook(char *n, int a , int p, int nm)
    {
        strcpy(name, n);
        areacode =a;
        prefix= p;
        num =nm;
    }
    phoneBook() {}
    //we can also add friend function
    friend ostream &operator<<(ostream &stream, phoneBook o);  //this is inserters
    friend istream &operator<<(istream &stream, phoneBook &o);  //this is extractors
};

//display name and phone numebr
ostream &operator<<(ostream &stream, phoneBook o)
{
    stream<<o.name<<"  "<<"("<<o.areacode<<")"<<o.prefix<<"-"<<o.num<<endl;
    return stream;
}

//input name and telephome number and this is extractor
istream &operator>>(istream &stream , phoneBook &o)
{
    cout<<"enter name : ";
    stream>>o.name;
    cout<<"enter area code : ";
    stream>>o.areacode;
    cout<<"enter prefix : ";
    stream>>o.prefix;
    cout<<"enter the number : ";
    stream >>o.num;
    cout<<endl;
    return stream;
}
int main()
{
    phoneBook a("Ted",111,555,1234);
    phoneBook b("umang",321,555,3221);
    phoneBook c("uman",43,3423,4332);
    cout<<a<<b<<c<<endl<<endl;
    phoneBook C;
    cin>>c;
    cout<<c;
    return 0;
}
