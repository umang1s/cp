#include"default.h"

int solve(){
    int n,k;
    cin>>n>>k;

    unordered_map<int,int> m;
    int val;
    for(int i=0; i<k; i++){
        cin>>val;
        m[val]++;
    }

    cout<<m.size()<<nl;
    for(int i=k; i<n; i++){
        m.find(arr[i-k]);

        cin>>val;

    }


    return 0;
}