#include"default.h"

int fibNum(int pre[],int n){
    if(pre[n]!=-1) return pre[n];
    if(n==0 || n==1) return n;
    pre[n]=fibNum(pre,n-1)+fibNum(pre,n-2);
    return pre[n];
}

















void solve(){
    int j[200];
    for(int i=0; i<200; i++) j[i]=-1;
    int n=3;
    int ans=fibNum(j,n);
    cout<<ans;
}