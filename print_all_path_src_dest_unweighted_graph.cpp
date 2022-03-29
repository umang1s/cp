#include"default.h"
//Print all paths from a given source to a destination using BFS

vector<vector<int>> getAllPathFromSrcDestBfs(vector<vector<int>> &adj,int src,int dest){
    vector<vector<int>> path;
    int total=adj.size();
    vector<bool> visited(total,false);
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        if(top==dest) print(top);

        for(auto j: adj[top]){
            if(!visited[j]){
                q.push(j);
                visited[j]=true;
            }
        }
    }


    

    return path;
}

void solve(){
    int n,e;
    scan(n);
    scan(e);
    vii adj=scanAdjList(n,e,false);
    vii path= getAllPathFromSrcDestBfs(adj,2,3);
}