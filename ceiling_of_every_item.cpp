#include"default.h"

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    //I have to print all ceiling elements 
    ///100 50 30 60 55 32
    int res[n];
    set<int> s;

    for(int i=n-1; i>=0; i--){
        auto it=s.lower_bound(arr[i]);
        if(it==s.end()) res[i]=-1;
        else res[i]=*it;
        s.insert(arr[i]);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  "<<res[i]<<nl;
    }
}