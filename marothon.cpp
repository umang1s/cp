#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    def();
    int t;
    cin>>t;
    int arr[1100][1100];
    long long xxx=0;

    for(int i=1; i<1090; i++){
        xxx+=i;
        
        arr[i][0]=xxx;
        for(int j=0; j<1090; j++) arr[i][j]=arr[i][j-1]+j+i;
    }

    while(t--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        long long sum=0;

        for(int j=y1; j<=y2; j++) sum+=arr[j][x1];
        for(int i=x1; i<=x2; i++) sum+=arr[y2][i];
        
        cout<<sum<<endl;

    }
}