#include<bits/stdc++.h>
#define int long long
#define pi vector<int>
#define mod 1000000007
#define loop(vrbl,inVl,lptl) for(int vrbl=inVl; vrbl<=lptl; vrbl++) 
using namespace std;

void solve();
int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--) solve();
}
vector<vector<int>> adj;
vector<pair<int,bool>> str;

void subtractData(int node,int val,bool initial=false){
    if(initial){
        if(val==0) return;
        for(auto p: adj[node]) subtractData(p,val-1);
        return;
    }
    if(str[node].second) return;
    str[node].first=max(str[node].first,val);
    if(val==0) return;
    for(auto p: adj[node]) subtractData(p,val-1);
}

void solve(){
    int n,r,m;
    cin>>n>>r>>m;

    adj=vector<vector<int>>(n+1);
    str=vector<pair<int,bool>>(n+1,{-1,false});

    for(int i=1; i<=r; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int,int>> tempD;

    for(int j=1; j<=m; j++){
        int x,y;
        cin>>x>>y;
        tempD.push_back({x,y});
        str[x].first=y;
        str[x].second=true;
    }

    for(auto q:tempD) subtractData(q.first,q.second,true);

    bool isRight=true;
    for(int i=1; i<=n; i++) if(str[i].first==-1) isRight=false;
    if(isRight)cout<<"Yes"<<'\n';
    else cout<<"No\n";
}