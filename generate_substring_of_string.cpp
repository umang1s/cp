#include"default.h"

/*
    You are given a string and you have to generate all substrings.

    ex-
        abc

        '',a ,b,c,ab,ac,bc,abc

*/


void solve(){
    string x;
    cin>>x;
    int len=x.length();
    int c=0;
    int loop=pow(2,len);
    while(c<loop){
        int current=c;
        for(int i=0; i<len; i++){
            if(current&1) cout<<x[i];
            current=current>>1;
        }
        cout<<nl;
        c++;
    }
}