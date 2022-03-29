#include"def.h"

void solve(int test){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(n));

    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>arr[i][j];

        for(int i=0; i<n; i++) for(int j=0; j<m; j++) cout<<arr[i][j]<<" ";
        cout<<endl;


}