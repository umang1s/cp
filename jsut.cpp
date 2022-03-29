#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool> arr(n+1,true);
    for(int i=3; i*i<=n; i++)
        if(arr[i]) for(int j=2; j*i<=n; j++) arr[j*i]=false;
    vector<int> ans;
    cout<<"[";
    for(int i=5; i<=n; i+=2)if(!arr[i])  ans.push_back(i);
    for(int i=0; i<ans.size()-1; i++) cout<<ans[i]<<",";
    cout<<ans[ans.size()-1];
    cout<<"]";
}