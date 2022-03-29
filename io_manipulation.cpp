#include<bits/stdc++.h>
using namespace std;

int main(){
    //in this program we are using io manipulation 

    int a=32;

    //using setw
    cout<<std::setw(5)<<std::setfill('*')<<a<<"\n"; //***32

    cout<<std::left<<std::setw(5)<<std::setfill('*')<<a<<'\n';

    cout<<std::fixed<<std::setprecision(5)<<43.0<<'\n';

    string name="umang";

    cout<<std::uppercase<<name<<'\n';
}