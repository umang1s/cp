#include<iostream>
using namespace std;
int main()
{
    long long millis=1703045800000;
    cout<<"enter time : ";
    cin>>millis;
    long seconds=millis/1000;
    cout<<"Seconds : "<<seconds<<endl;
    long minuts=seconds/60;
    cout<<"minuts : "<<minuts<<endl;
    long hrs=minuts/60;
    cout<<"hrs : "<<hrs<<endl;
    long days=hrs/24;
    cout<<"days : "<<days<<endl;
    cout<<"year : "<<days/365.25<<endl;
}
