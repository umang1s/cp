#include"default.h"
#define Adj vector<vector<int>>

bool dfs_detect_cycle_in_directed_graph(Adj &adj,vector<bool> &vis,int ind){
}

bool detect_cycle_in_directed_graph(Adj &adj,int n){

}


bool dfs_detect_cycle_in_undirected_graph(Adj &adj,vector<int> &vis,int ind){
    if(vis[ind]==2) return true;
    vis[ind]=1;
    for(auto i: adj[ind]){
        if(vis[i]==1) vis[i]=2;
        else if(dfs_detect_cycle_in_undirected_graph(adj,vis,i)) return true;
    }
    return false;
}

bool detect_cycle_in_undirected_graph(Adj &adj,int n){
    vector<int> vis(n,0);
    for(int i=0; i<n; i++){
        vis[i]=1;
        for(int j=0; j<adj[i].size(); j++){
            if(dfs_detect_cycle_in_undirected_graph(adj,vis,adj[i][j])) return true;
        }
        vis[i]=0; 
    }
    return false;

}