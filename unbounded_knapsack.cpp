#include"default.h"


int rod_cutting_problem(vector<int> &length,vector<int>&price,int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=0; i<n; i++) dp[0][i]=0,dp[i][0]=1;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        dp[i][j]=dp[i-1][j];
        if(j>=price[])
    }

}

int coin_change_1_number_of_ways(vector<int>&coins,int sum){

}

int coin_change_2_min_coin_to_make_sum(vector<int> &coins,int sum){

}



////lcs




void solve(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    arr[0]=0;
    for(int i=1; i<=n; i++) cin>>arr[i];
    cout<<rod_cutting_problem(arr,n)<<nl;

}