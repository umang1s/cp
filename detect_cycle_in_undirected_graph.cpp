#include"default.h"

///using dfs

bool checkCycleDFS(const vii & adj,int n){
    
}


///using bfs
bool checkCycleBFS(const vii &adj,int n){
    vector<bool> visited(n,false);
    visited[0]=true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int c=q.back();
        q.pop();
        for(auto j: adj[c]){
            if(visited[j]) return true;
            q.push(j);
            visited[j]=true;
        }
    }

    return false;
}

void printTF(bool a){
    if(a) cout<<"TRUE\n";
    else cout<<"FALSE\n";
}
NULL



int solve(){
    int n;
    cin>>n;
    vii adj(n);
    int k;
    cin>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printTF(checkCycleBFS(adj,n));
    
    return 0;
}