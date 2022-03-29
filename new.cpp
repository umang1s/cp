#include"default.h"


void solve(){
    int n;
    cin>>n;
    vi arr(n);
    scanA(arr,n);
    //sortA(arr);

    auto j=upper_bound(arr.begin(),arr.end(),3);
    auto k=lower_bound(arr.begin(),arr.end(),3);
    if(j==arr.end()) cout<<"Not found\n";
    else if(j==arr.begin()) cout<<"Not found-\n";
    else cout<<*j<<nl;

    if(k==arr.end()) cout<<"Not found\n";
    else if(k==arr.begin()) cout<<"Not found-\n";
    else cout<<*k<<nl;
    
    
}