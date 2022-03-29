#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    def();
    int t=1;
    cin>>t;
    long long arr[8];
    long mult=100;
    arr[0]=11;
    for(int i=1; i<8; i++){
        arr[i]=arr[i-1]+mult;
        mult*=10;
    }
    while(t--){
        long long val;
        cin>>val;
        bool isTrue=false;
        if(val>=11){
            int m=1; while(arr[m]<val) m++;

            for(int i=0; i<m && !isTrue; i++){
                for(int j=0; j<i && !isTrue; j++){

                }
            }
        }
        if(isTrue) cout<<"YES\n"<<endl;
        else cout<<"NO\n";
        
    }
}