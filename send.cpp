#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool checkOpertion(long long a,long long b,long long biggest){
    long long diff=abs(b-a);
    if(diff<biggest) return false;
    return true;

}

int main(){
    def();
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        long long a=1;
        for(int i=1; i<n; i++) if(arr[0]==arr[i]) a++;


        cout<<n-a<<endl;

    }
}