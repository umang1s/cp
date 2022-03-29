#include"default.h"

/*
    You are given a number n cut it to length a,b,c such that max cut happens.
    n,a,b,c

    14  1 4 5

    14  //1x14

    14 5 9 3

    2   //5x1,9x1
*/

int makeCut(int len,int a,int b,int c){
    if(len==0) return 0;
    if(len<0) return -1;

    int cnt=max({makeCut(len-a,a,b,c),makeCut(len-b,a,b,c),makeCut(len-c,a,b,c)});

    if(cnt==-1) return -1;
    return cnt+1;

}

void solve(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;

    int cut=makeCut(n,a,b,c);
    cout<<cut<<nl;
}