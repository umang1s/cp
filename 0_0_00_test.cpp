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

void merge(vector<pair<int,int>> &arr,int low,int high,vector<int>&ans){
    int mid=(low+high)/2;
    vector<pair<int,int>> temp;
    int i=low,j=mid+1;
    int counter=0;
    while(i<=mid && j<=high){
        if(arr[i].first<arr[j].first) temp.push_back(arr[j]),j++,counter++;
        else temp.push_back(arr[i]),ans[arr[i].second]+=counter, i++;
    }
    while(i<=mid) ans[arr[i].second]+=counter, temp.push_back(arr[i]),i++;
    while(j<=high) temp.push_back(arr[j]),j++;
    for(int i=low; i<=high; i++) arr[i]=temp[i-low];
}

void mergeSort(vector<pair<int,int>> &arr,int low,int high,vector<int>&ans){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid,ans);
    mergeSort(arr,mid+1,high,ans);
    merge(arr,low,high,ans);
}
void solve(int t){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr[i]={a,i};
    }
    vector<int> ans(n);
    for(auto i: arr) cout<<i.first<<spc;
    cout<<nl;
    mergeSort(arr,0,n-1,ans);
    for(auto i: arr) cout<<i.first<<spc;
    cout<<nl;
    for(auto i: ans) cout<<i<<spc;
    cout<<nl;

}
// void printArray(vector<int> &arr){
//     for(auto i: arr) cout<<i<<spc;
// }

// void topologicalSorting(vector<vector<int>>&adj,vector<int>&ans,vector<int> &inc){
//     queue<int> q;
//     int n=inc.size();
//     for(int i=0; i<n; i++) if(inc[i]==0) q.push(i);
//     while(!q.empty()){
//         int tp=q.front();
//         q.pop();
//         ans.push_back(tp);
//         for(int j: adj[tp]){ 
//             inc[j]--;
//             if(inc[j]==0) q.push(j);
//         }
//     }
// }

// bool cycleDetection(vector<vector<int>> &adj,vector<int> &inc){
//     queue<int> q;
//     int n=inc.size();
//     for(int i=0; i<n; i++) if(inc[i]==0) q.push(i);
//     int cnt=0;
//     while(!q.empty()){
//         int top=q.front();
//         q.pop();
//         cnt++;
//         for(int i: adj[top]){
//             inc[i]--;
//             if(inc[i]==0) q.push(i);
//         }
//     }
//     return cnt!=n;
// }




// void solve(int t){
//     int n,k;
//     cin>>n>>k;
//     vector<vector<int>> arr(n);
//     vector<int> inc(n,0);
//     for(int i=0; i<k; i++){
//         int a,b;
//         cin>>a>>b;
//         arr[a].push_back(b);
//         inc[b]++;
//     }
//     vector<int> ans;
//     cout<<cycleDetection(arr,inc);

// }
