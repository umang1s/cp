#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void solve(int i){
    int n;
    cin>>n;
    char a[n];
    cin>>a;

    cout<<"Case #"<<i<<": 1 ";
    int cnt=1;
    for(int i=1; i<n; i++){
        if(a[i]>a[i-1]) cnt++;
        else cnt=1;
        cout<<cnt<<" ";
    }

    cout<<endl;
}


int main(){
    def();
    int t;
    cin>>t;
    for(int i=1; i<=t; i++) solve(i);
}