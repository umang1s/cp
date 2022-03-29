#include<iostream>
using namespace std;
// example 1
float dos(float i) {return i;}
double dos(double i) {return i;}
//example 2
char pos(unsigned char p) {return p-1;}
char pos(char p){return p+1;}
//example 3
int sum(int i,int j=9) {return i+j;}
int sum(int i) {return i;}
//example 4
int cal(int i){;}
int cal(int &i){;} //when we call it it shows error which fucntion has called
int main()
{
    cout<<dos(10.1)<<endl;   // unambiguous
    //cout<<dos(10)<<endl;     // ambiguous
    cout<<pos('c')<<endl;
   // cout<<pos(88)<<endl;        //ambiguous
   //cout<<sum(15)<<endl;            //ambiguous
   cout<<sum(20,14)<<endl;
}
