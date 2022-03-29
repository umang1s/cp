#include<iostream>
using namespace std;
int Value(char R)
{
    int I=1,V=5,X=10,L=50,C=100,D=500,M=1000;
    if     (R=='I' || R=='i' ) return I;
    else if(R=='V' || R=='v' ) return V;
    else if(R=='X' || R=='x' ) return X;
    else if(R=='L' || R=='l' ) return L;
    else if(R=='C' || R=='c' ) return C;
    else if(R=='D' || R=='d' ) return D;
    else if(R=='M' || R=='m' ) return M;
    else   {   cout<<"Invalid Input "<<endl; return 0; }
}
int main()
{
    int val=0,j=0,length,val1,val2,check;
    string Roman;
    while(1){ val=0; j=0;
    cout<<"enter the roman digit  :  ";
    cin>>Roman;
    length=Roman.size();
    for(int i=0; i<length; i++)
    {
        if(i<length-1)
        {
            val1=Value(Roman[i]);   val2=Value(Roman[i+1]);
            if(i==0) check=val1;
            if(val1==val2)      {j++; val+=val1; }
            else if(val1<val2)  {j=0; val-=val1; if(i==0) check=val2;}
            else                {j=0; val+=val1;}
            if(check<val1) {cout<<"Invalid input "<<endl; return 0;}
            else check=val1;
        }
        else val+=Value(Roman[i]);
        if(j==3) {cout<<"Invalid input "<<endl; return 0;}      //no character will be more than thrice
    }
    cout<<val<<endl;}
}
