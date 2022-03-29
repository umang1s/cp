#include"default.h"

//single source shortest path    N^2+M
void dijkstra(vector<vector<pair<int,int>>> &adj,vector<int> &path,vector<int>&dist,int src){
    const int inf=10000000;
    int n=adj.size();
    dist.assign(n,inf);
    path.assign(n,-1);
    vector<bool> vis(n,false);
    dist[src]=0;
    for(int i=0; i<n; i++){
        int vs=-1;
        for(int j=0; j<n; j++) if(!vis[j]){
            if(vs==-1 || dist[vs]>dist[j]) vs=j;
        }
        if(dist[vs]==inf) break;
        vis[vs]=true;
        for(auto j: adj[vs]){ //src, weight
            int sum=dist[vs]+j.second;
            if(sum<dist[j.first]) dist[j.first]=sum,path[j.first]=vs;
        }
    }
}

vector<int> restore_path(vector<int> paths,int src,int dest){
    vector<int> ans;
    while(dest!=src){
        ans.push_back(dest);
        dest=paths[dest];
    }
    ans.push_back(src);
    reverse(ans.begin(),ans.end());
    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }
    vector<int> paths,dist,pth;
    dijkstra(adj,paths,dist,0);
    pth=restore_path(paths,0,n-1);
    for(auto i: pth) cout<<i+1<<spc;
}