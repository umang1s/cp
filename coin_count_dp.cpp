#include"default.h"

int cnt=0;
int count(vector<int> &arr,vector<vector<int>> &dp,int index,int sum){
    cnt++;
    if(index<0) return 0;
    if(sum==0) return 1;
    if(dp[sum][index]!=-1) return dp[sum][index];
    int ret=count(arr,dp,index-1,sum);
    if(arr[index]<=sum) ret+=count(arr,dp,index,sum-arr[index]);
    return dp[sum][index]=ret;

}
int test=2;
int solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(),arr.end());

    cout<<count(arr,dp,n-1,k)<<spc<<cnt<<spc;
    reverse(arr.begin(),arr.end());

    //with table
    cnt=0;
    vector<vector<int>> dp2(k+1,vector<int>(n+1,-1));
    for(int i=0; i<=n; i++) dp2[0][i]=1;
    for(int i=1; i<=k ; i++) dp2[i][0]=0;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            cnt++;
            dp2[i][j]=dp2[i][j-1];
            if(arr[j-1]<=i)dp2[i][j]+=dp2[i-arr[j-1]][j];
        }
    }


    cout<<"--"<<dp2[k][n]<<spc<<cnt;
    test--;
    return test;
}


/*
no of coins type,sum . Find all way

2
3 4
1 2 3

4 10
2 5 3 6

o/p
4
5


*/