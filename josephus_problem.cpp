#include"default.h"

// You have given n,k and and you have to find the index of last person who can survive last. There are a circular
//ring and there are n people stand at there(0-indexed)

int josephus(int n,int k){
    if(n==1) return 0;
    return (josephus(n-1,k)+k)%n; //0 1 2 3 4--> 0 2 3 4-->0 2 4-->4 2--> 
}


void solve(){
    int n,k;
    cin>>n>>k;
    cout<<josephus(n,k);
}