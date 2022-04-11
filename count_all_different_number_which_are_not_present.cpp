#include"default.h"

/*

we have a given an arr of length n. which is filled with with number from [1-n]. some number has 
missing and some are present twice. find those number which are not present.
*/

vector<int> count(vector<int> arr,int start,int last){
    for(auto i: arr){
        int absl=abs(i)-start;
        if(arr[absl]>0){
            arr[absl]*=-1; 
        }
    }
    vector<int> ans;
    for(int i=start; i<=last; i++) if(arr[i-start]>0) ans.push_back(i);
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> ans=count(arr,3,n+2);
    for(auto i: ans) cout<<i<<spc;
    cout<<nl;
}

