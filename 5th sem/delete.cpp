#include<iostream>
#include<cstring>
#include<stdio.h>
#include"umang.h"
using namespace std;

int main()
{
    char English[26];
    int k=0;
    for(int i=65; i<91; i++) English[k++]=i;
    for(int i=0; i<26; i++) cout<<English[i];
    cout<<endl;
    cout<<"compared the data"<<endl;
    cout<<(-65/3)<<endl;

}
