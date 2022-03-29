#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<vector<int>>
#define spc ' '
#define nl '\n'
#define mod 1000000007
using namespace std;
#define scanA(arr,total) for(int i=0; i<total; i++) cin>>arr[i]
#define sortA(x) sort(x.begin(),x.end())
#define printA(z) for(auto in:z) cout<<in<<' '
#define dec(num,b) std::fixed<<std::setprecision(b)<<num
//Aurthor umang1s

void solve();   
int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    solve();
    cout<<endl;
}

void solve(){
    int n;
    cin>>n;
    vector<string> word(n);
    for(int i=0; i<n; i++) cin>>word[i];

    vector<char> ans;
    

    for(int i=0; i<word[0].length(); i++){

    }

    
    while(!ans.empty()){
        cout<<ans.back();
        ans.pop_back();
    }
}