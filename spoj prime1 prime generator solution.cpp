#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define psi pair<string,int>
#define vii vector<vector<int>>
#define spc ' '
#define nl '\n'
#define mod 1000000007
using namespace std;
#define scanA(arr,total) for(int i=0; i<total; i++) cin>>arr[i]
#define sortA(x) sort(x.begin(),x.end())
#define printA(z) for(auto in:z) cout<<in<<' '

void solve();
int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int n;
    cin>>n;
    while(n--) {solve(); cout<<nl;}
}

bool checkPrime(int num){
    if(num<2) return false;
    if(num==2) return true;
    if(num%2==0) return false;
    for(int i=3; i*i<=num; i+=2){
        if(num%i==0) return false;
    }
    return true;
}
void solve(){
    int lower,upper;
    cin>>lower>>upper;
    for(int i=lower; i<=upper; i++) if(checkPrime(i)) cout<<i<<"\n";
}
