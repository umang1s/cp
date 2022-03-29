/*
You have given an array of coins and a sum. You have to choose minimum no of coins to make it equal to sum.

n,k
n[...]


3 5
3 4 1

o/p
2








*/

void minimum_coin_to_make_it_sum(int arr[],int n,int val){
    int dp[val+1];
    for(int i=0; i<=val; i++) dp[i]=INT_MAX;
    dp[0]=0;

    for(int i=1; i<=val; i++){
        for(int j=0; j<n; j++){
            if(arr[j]<=i){
                int rem=i-arr[j];
                if(dp[rem]!=INT_MAX) dp[i]=min(dp[i],dp[rem]+1);
            }
        }
    }
    for(int i=0; i<=val; i++) cout<<dp[i]<<spc;
    cout<<nl;
    cout<<dp[val]<<nl;
}