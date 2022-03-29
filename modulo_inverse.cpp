#include"default.h"
//  (a+b)%c= (a%c + b%c) %c
//  (a*b)%c= (a%c * b%c) %c
//  (a-b)% ~ (a%c + b%c) %c
//  (a+b)%c ~(a%c + b%c) %c

int naive(int a,int m){
    for(int i=0; i<m;i++) if((a*i)%m==1) return i;
    return -1;
}

int gcdExtended(int a,int b,int &x,int &y){

    return 0;
}

int efficient(int a,int m){
    int x,y;

    if(gcdExtended(a,m,x,y)==1){
        cout<<x;
    }return -1;
}

int usingEulersTheorem(int a , int m){
    
    return -1;
}

int solve(){
    int a,b;
    cin>>a>>b;
    
    // if we have given a,m then this property must be hold. Here x is variable
    //  (a*x)%m=1%m

    int ans=naive(a,b);
    if(ans==-1) cout<<"Not founds\n";
    else cout<<ans<<nl;

    ans=efficient(a,b);
    if(ans==-1) cout<<"Not founds\n";
    else cout<<ans<<nl;

    ans=usingEulersTheorem(a,b);
    if(ans==-1) cout<<"Not founds\n";
    else cout<<ans<<nl;


    return 0;
}