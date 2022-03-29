#include"default.h"

int kth_smallest(vector<int> &arr,int n){
    multiset<int> ms;
    for(int i=0; i<n; i++) ms.insert(arr[i]);
    for(int i=n; i<arr.size(); i++){
        ms.insert(arr[i]);
        auto it=ms.end();
        it--;
       ms.erase(it);
    }
    auto it=ms.end();
    it--;
    return *it;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    cout<<kth_smallest(arr,k);
}