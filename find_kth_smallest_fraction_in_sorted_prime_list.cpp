#include"default.h"

pair<int,int> kth_smallest(vector<int> &arr,int k){
    //given a sorted list of prime number including 1 and we have to find kth smallest fraction
    //p/q
    //double,start,last
    priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> q;
    int n=arr.size();
    for(int i=0; i<n-1;i++){
        double frac=(arr[i]*1.0)/arr[n-1];
        q.push({frac,{i,n-1}});
    }
    k--;
    while(k && !q.empty()){
        auto top=q.top().second;
        q.pop();
        top.second--;
        if(top.first!=top.second){
            double frac=(arr[top.first]*1.0)/arr[top.second];
            q.push({frac,top});
        }
        k--;
    }
    if(q.empty()) return {0,0};
    return q.top().second;

}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    auto pr=kth_smallest(arr,6);
    cout<<arr[pr.first]<<spc<<arr[pr.second]<<nl;
}