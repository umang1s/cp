// this is hash encryptions
#include<iostream>
#include"md5.h"
using namespace std;
int main(int argc , char *argv[])
{
    string input;
    cout<<"enter the passwords :  ";
    cin>>input;
    cout<<md5("umang")<<endl;
}
