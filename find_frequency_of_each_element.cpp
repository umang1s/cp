#include"default.h"
int test=3;
int solve(){
    int n;
    cin>>n;
    unordered_map<int,int> m;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        m[x]++;
    }
    for(auto j: m) cout<<j.first<<" "<<j.second<<nl;

    return test--;
}