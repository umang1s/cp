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
	double a,b,c;
    cin>>a>>b>>c;
    while(a!=0 || b!=0 || c!=0){
        bool isAp=true;
        int v,diff;
        if(b-a==c-b){
            v=2*c-b;
            isAp=true;
        }else{
            v=c*c/b;
            isAp=false;
        }
        isAp?cout<<"AP ":cout<<"GP ";
        cout<<v<<nl;
        cin>>a>>b>>c;
    }
}