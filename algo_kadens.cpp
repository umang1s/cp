// this algorithm help to find the greatest sum of subarray

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

 
#define int long long
 
 
void solve()
{
  int n,k;
  cin>>n>>k;
 
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
 
  int pre[n],suf[n];
 
  int ans=arr[0];
  int curr=0;
 
  for(int i=0;i<n;i++)
  {
    curr+=arr[i];
    ans=max(ans,curr);
    pre[i]=ans;
    if(curr<0)
      curr=0;
  }
 
  ans=arr[n-1];
  curr=0;
 
  for(int i=n-1;i>=0;i--)
  {
    curr+=arr[i];
    ans=max(ans,curr);
    suf[i]=ans;
    if(curr<0)
      curr=0;
  }
 
  ans=INT_MIN;
 
  for(int i=0;i<n-1;i++)
  {
    int temp=pre[i]+suf[i+1]*2;
    ans=max(ans,temp);
  }
  
 
  if(k==2)
    cout<<ans<<"\n";
  else
    exit(0);
}
 
int32_t main(){
 def();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
 
  while(t--)
  {
    solve();
  }
 
return 0;
}
