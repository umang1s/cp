#include"default.h"

void solve(){
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sortA(arr);
    int mx=1;
    int current=1;
    for(int i=1; i<n; i++){
        if(arr[i]-arr[i-1]==1) current++;
        else{
            mx=max(mx,current);
            current=1;
        }
    }

    cout<<mx<<nl;


}