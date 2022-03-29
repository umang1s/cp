#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> getDivisior(int n,int maxx){
    vector<int> divisor;
    for (int i=1; i<=sqrt(n) && i<=maxx; i++)
    {
        if (n%i == 0)
        {
              divisor.push_back(i);
              if (n/i != i){
                  int j=n/i;
                  if(j<=maxx) divisor.push_back(j);
              }
 
        }
    }
    sort(divisor.begin(),divisor.end());

    return divisor;
}

int main(){
    def();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> fin(n);

        for(int i=0; i<n; i++){ cin>>arr[i]; fin[i]=arr[i];}

        sort(arr.begin(),arr.end());
        int mx=arr[n-1],mn=arr[0];

        vector<int> divisor=getDivisior(mx,mn);
        
        int val=-1;
        bool inv=false;
        for(int i=0; i<divisor.size() && !inv; i++){
            inv=false;
            for(int j=0; j<n; j++) if(fin[j]%divisor[i]!=0) inv=true;
            if(inv){ val=i; val=false;}

        }
        cout<<val<<endl;
        if(val==-1) for(int i=0; i<n; i++) cout<<fin[i]<<" ";
        else{
            val=divisor[val];
            for(int i=0; i<n; i++) cout<<fin[i]/val<<" ";
        }
        cout<<endl;
    }
}