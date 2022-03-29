//what's next



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

int reversed(int x){
    vector<int> arr;
    while(x>9){
        arr.push_back(x%10);
        x/=10;
    }
    arr.push_back(x);

    int y=0;
    int ten=1;
    int len=arr.size();
    for(int i=len-1; i>=0; i--){
        y+=ten*arr[i];
        ten*=10;
    }

    return y;
}

void solve(){
    int f,s;
    cin>>f>>s;
    cout<<reversed(reversed(f)+reversed(s));
}
