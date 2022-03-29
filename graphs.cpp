#include"default.h"











bool dfs_recursive(v<v<int>> &adj,int source,v<bool> &vis,int parent){
    vis[source]=true;
    for(auto k: adj[source]){
        if(!vis[k] && dfs_recursive(adj,k,vis,source)) return true;
        else if(k!=parent) return true;
    }
    return false;
}


bool detect_cycle_in_undirected(v<v<int>> &adj,int s){
    int node=adj.size();
    v<bool> visited(node,false);
    v[s]=true;
    for(int i=0; i<node; i++)
        if(!visited[i] && dfs_recursive(adj,i,vis,-1))
            return true;
    
    return false;

}

bool dfs_recursive_directed(v<v<int>> &adj,v<bool> &vis,v<bool> res,int s){
    vis[s]=true;
    res[s]=true;

    for(auto k: adj[s]){
        if(!vis[k] && dfs_recursive_directed(adj,vis,res,s)) return true;
        else if(res[k]) return true;
    }

    res[s]=false;
    return false;
}

bool detect_cycle_in_directed(v<v<int>> &adj,int s){
    //undirected will not work here
    int node=adj.size();
    v<bool> visited(node,false);
    v<bool> rest(node,false);
    for(int i=0; i<node; i++)
        if(!visited[i] && dfs_recursive_directed(adj,vis,rest,i))
            return true;
    
    return false;
}

v<int> shortest_path_one_to_all_in_undirected(v<v<int>> &adj,int s){
    int node=adj.size();
    v<int> dist(node,0);
    queue<int> q;
    v<bool> visited(node,false);
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int j : adj[top]){
            if(!visited[j]){
                q.push(j);
                visited[j]=true;
                dist[j]=dist[top]+1;
            }
        }
    }
}


void topological_sorting(){
    //given directed no cycle graph
}