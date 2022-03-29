#include<iostream>
using namespace std;
string PES(string pass)
{
    char Pass[32];
    int length=pass.size();
    if(length<33)  for(int i=0; i<32; i++)     //size maintaining
    {
        if(i<length) Pass[i]=pass[i];
        else if(i==length) Pass[i]='a';
        else Pass[i]=='z';
    }
    return Pass;
}
