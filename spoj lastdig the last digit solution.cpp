#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve();
int32_t main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int n;cin>>n; while(n--) {solve(); cout<<endl;}
}
void solve(){
    int a,b;
    cin>>a>>b;
    if(b==0) {cout<<1; return;}
    int p=b%4, q=a%10;
    if(p==0) p=4;
    int temp=pow(q,p);
    cout<<temp%10;
}