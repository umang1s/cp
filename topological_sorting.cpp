#include<bits/stdc++.h> 
#define int long long
#define spc ' '
#define nl '\n'
#define mod 1000000007
#define String string
using namespace std;
#define dec(num,b) std::fixed<<std::setprecision(b)<<num
#define google(i) "Case #"<<i<<": "
void solve(int i);
int32_t main(){ /* Author-Umang Maurya */
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    if(true){int t,p=0; cin>>t; while(p<t){ p++;solve(p); cout<<nl;}}
    else {solve(1); cout<<nl;}
}
void printArray(vector<int> &arr){
    for(auto i: arr) cout<<i<<spc;
}

void topologicalSorting(vector<vector<int>>&adj,vector<int>&ans,vector<int> &inc){
    queue<int> q;
    int n=inc.size();
    for(int i=0; i<n; i++) if(inc[i]==0) q.push(i);
    while(!q.empty()){
        int tp=q.front();
        q.pop();
        ans.push_back(tp);
        for(int j: adj[tp]){ 
            inc[j]--;
            if(inc[j]==0) q.push(j);
        }
    }
}
void solve(int t){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> arr(n);
    vector<int> inc(n,0);
    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        inc[b]++;
    }
    vector<int> ans;
    topologicalSorting(arr,ans,inc);
    printArray(ans);

}


/*
4
3 2
0 1
0 2

5 4
0 2
0 3
1 3
1 4

6 6
0 1
0 2
1 3
2 3
3 4
3 5

5 5
0 2
0 3
2 3
1 3
1 4

*/