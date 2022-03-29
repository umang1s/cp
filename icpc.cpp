#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void solve();

int main(){
    def();
    int t;
    while(t--) solve();
}

typedef struct graph{
    bool marked;
    vector<int> connection;
    int val;
    int weight;
}Graph;


void solve(){
    int n,temp,k;
    cin>>n;
    vector<int> newMarked;
    vector<Graph> arr(n+1);
    vector<vector<int>> found_path;
    for(int i=1; i<=n; i++){
        cin>>arr[i].weight;
        arr[i].marked=false;
        arr[i].val=i;
    }
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>temp;
        arr[temp].marked=true;
    }
    int m,x,y;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        arr[x].connection.push_back(y);
    }
    //solution
    

    


    //answer
    int len_new=newMarked.size();
    cout<<len_new<<" ";
    for(int i=0; i<len_new; i++) cout<<newMarked[i]<<" ";
    cout<<endl;
    long long len_path=found_path.size();
    cout<<len_path<<endl;
    for(long long i=0; i<len_path; i++){
        long long len2=found_path[i].size();
        cout<<len2<<" ";
        for(long long j=0; j<len2; j++) cout<<found_path[i][j]<<" ";
        cout<<endl;
    }

}