#include"default.h"

void DFS(vector<int> adj[],bool vis[],int current){
    cout<<current<<" ";
    vis[current]=true;
    for(auto j: adj[current])if(!vis[j])  DFS(adj,vis,j);
}

void dfsForDisConnectedComponents(vector<int> adj[],int n,int src){
    int connected_components=0;
    bool vis[n];
    for(int i=0; i<n; i++) if(!vis[i]){connected_components++; DFS(adj,vis,i);}

    cout<<"\nconnected components : "<<connected_components<<nl;

}

/// checking cycle in undirected graph
bool checkDFS(vector<int> adj[],bool vis[],int n,int p){
    vis[n]=true;
    for(auto j: adj[n]){
        if(!vis[j]){
            bool checking=checkDFS(adj,vis,j,n);
            if(checking) return true;
        }else if(j!=p) return true;
    }
    return false;

}

void checkingCycle(vector<int> adj[],int n){
    bool vis[n];
    bool cycleFound=false;
    for(int i=0; i<n; i++) if(!vis[i]) if(checkDFS(adj,vis,i,-1)){  cout<<"Found "; return; }
    cout<<"Not Found";
}

///////////////////////
///checking cycle in directed graph

bool checkDFSR(vector<int> adj[],bool vis[],bool rest[],int s){
    vis[s]=true;
    rest[s]=true;
    for(auto j: adj[s]){
        if(!vis[j] && checkDFSR(adj,vis,rest,j)) return true;
        else if(rest[j]) return true;
    }
    rest[s]=false;
    return false;
}

void checkingCycleInDIrected(vector<int> adj[],int n){
    bool vis[n],rest[n];
    for(int i=0; i<n; i++){
        if(!vis[i]) if(checkDFSR(adj,vis,rest,i)) { cout<<"Found "; return;}
    }
    cout<<"Not Found";
}



void solve(){
    int node,n;
    cin>>node>>n;
    vector<int> adj[node];
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }
    int src;
    cin>>src;
    dfsForDisConnectedComponents(adj,node,src);
    //checkingCycle(adj,node);
    checkingCycleInDIrected(adj,node);
}