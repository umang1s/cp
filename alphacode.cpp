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
	string x;
	cin>>x;
	while(x!="0"){
		int len=x.length();
		vector<int> dp(len);
		dp[0]=1;
		for(int i=1; i<len; i++){
			if(x[i]>'0') dp[i]=dp[i-1];
			int val=10*(x[i-1]-'0')+(x[i]-'0');
			if(val>=10 && val<=26){
				if(i<2) dp[i]+=dp[0];
				else dp[i]+=dp[i-2];
			}
		} 
		cout<<dp[len-1]<<nl;
		cin>>x;
	}
}