#include"default.h"
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
string alienOrder(vector<string> &arr){
    string ans="";
    int n=arr.size();
    if(n==1) return arr[0];
    vector<vector<int>> adj(26);
    vector<int> chr(26,0);
    vector<int> inc(26,0);
    for(auto i: arr[0]) chr[i-'a']++;
    for(int i=1; i<n; i++){
        int k=0;
        for(auto m: arr[i]) chr[m-'a']++;
        while(k<arr[i].size() && k<arr[i-1].size() && arr[i][k]==arr[i-1][k]) k++;
        if(k<arr[i].size() && k<arr[i-1].size()) adj[arr[i-1][k]-'a'].push_back(arr[i][k]-'a'),inc[arr[i][k]-'a']++;
    }
    vector<int> sorted;
    topologicalSorting(adj,sorted,inc);
    for(auto i: sorted) if(chr[i]) ans+=('a'+i);
    return ans;

}

string alienOrder_online(vector<string> &arr){
    unordered_map<char,list<char>> adjList;
    unordered_map<char,int> indegree;
    for(auto i: arr){
        for(auto j: i){
            indegree[j]=0;
            list<char> li;
            adjList[j]=li;
        }
    }
    for(int i=0; i<arr.size()-1; i++){
        string w1=arr[i];
        string w2=arr[i+1];
        auto temp=mismatch(w2.begin(),w2.end(), w1.begin());
        if(w1.length()>w2.length() && temp.first==w2.end()) {
            return "";
        }

        for(int j=0; j<min(w1.length(),w2.length()); j++){
            if(w1[j]!=w2[j]){
                adjList[w1[j]].push_back(w2[j]);
                indegree[w2[j]]++;
            }else break;
        }

    }

    string res="";
    //topological sorting
    queue<char> q;
    for(auto i: indegree) if(i.second==0) q.push(i.first);
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        res+=top;
        for(auto j: adjList[top]){
            indegree[j]--;
            if(indegree[j]==0) q.push(j);
        }
    }
    if(res.length()<indegree.size()) return "";
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<alienOrder(arr)<<nl;
}

/* Test Cases
2
5
wrt
wrf
er
ett
rftt
2
z
x
3
z
x
z


*/