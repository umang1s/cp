#include"default.h"
//not completed

pair<int,int> find_the_subarray_with_given_sum(vector<int> &arr,int sum){
    unordered_map<int,int> mp;
    int cnt=0;
    int n=arr.size();
    for(int i=0; i<n; i++){
        cnt+=arr[i];
        if(cnt==sum) return {0,i};
        auto it=mp.find(cnt-sum);
        if(it!=mp.end())return {it->second,i};
        mp[cnt]=i;
    }
    return {-1,-1};

}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    auto ans=find_the_subarray_with_given_sum(arr,k);
    if(ans.first==-1) cout<<"Not Found";
    else for(int i=ans.first; i<=ans.second; i++) cout<<arr[i]<<" ";

}