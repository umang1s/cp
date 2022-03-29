#include"def.h"
using namespace std;

void solved(int k){
    
        int n;
        cin>>n;
        int q=0,arr[n];
        while(q<n) cin>>arr[q++];

        int arr1[n],p=0;
        for(int i=0; i<n; i++){
            if(arr[i]%2) cout<<arr[i]<<" ";
            else arr1[p++]=arr[i];
        }
        for(int i=0; i<p; i++) cout<<arr1[i]<<" ";
}

void solve(int i){
    int n;
    cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        partition(a.begin(), a.end(), [&](const int u) {
            return u % 2;
        });
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
}