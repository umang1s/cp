/*
We have given value and corresponding their weight. You have to find maximum weight with corresponding 
to given value or maximum value corresponding to given weights.

2
4 10
10 40 30 50
5 4 6 3

3 50
60 100 120
10 20 30

o/p
10
50

//Variation of Knapsack




*/
#include"default.h"

bool check_subset_sum(vector<int> &arr,int sum){
    int ind=arr.size();
    vector<vector<bool>> dp(ind+1,vector<bool>(sum+1));
    for(int i=0; i<=ind; i++) dp[i][0]=1;
    for(int i=1; i<=sum; i++) dp[0][i]=0;
    for(int i=1; i<=ind; i++) for(int j=1; j<=sum; j++){
        dp[i][j]=dp[i-1][j];
        if(j>=arr[i-1]) dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]];

    }
    return dp[ind][sum];
}

bool can_be_partition_into_two_subset_with_equal_sum(vector<int> &arr){
    //equal sum partition
    int sum=0;
    for(auto i: arr) sum+=i;
    if(sum&1) return false;
    sum/=2;
    //or return checkSubsetSum(arr,sum);
    vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum+1));
    for(int i=0; i<=sum; i++) dp[0][i]=0;
    for(int i=0; i<=arr.size(); i++) dp[i][0]=1;
    for(int i=1; i<=arr.size(); i++) for(int j=1; j<=sum; j++){
        dp[i][j]=dp[i-1][j];
        if(j>=arr[i-1]) dp[i][j]=dp[i][j]|| dp[i-1][j-arr[i-1]];
    }
    return dp[arr.size()][sum];
}

int count_the_total_no_of_way_of_given_sum(vector<int> &arr,int sum){
    int ind=arr.size();
    vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1));
    int cnt=0;
    for(int i=0; i<=sum; i++) dp[0][i]=0;
    for(int i=0; i<=arr.size(); i++)dp[i][0]=1;
    for(int i=1; i<=arr.size(); i++) for(int j=1; j<=sum; j++){
        dp[i][j]=dp[i-1][j];
        if(j>=arr[i-1]) dp[i][j]+=dp[i-1][j-arr[i-1]];
    }
    return dp[arr.size()][sum];
}

int find_min_difference_of_sum_of_two_subset(vector<int> &arr){
    int sum=0;
    for(auto i: arr) sum+=i;
    int half=sum/2;
    vector<vector<bool>> dp(arr.size()+1,vector<bool>(half+1));
    for(int i=0; i<=half; i++) dp[0][i]=0;
    for(int i=0; i<=arr.size(); i++) dp[i][0]=1;

    for(int i=1; i<=arr.size(); i++) for(int j=1; j<=half; j++){
        dp[i][j]=dp[i-1][j];
        if(j>=arr[i-1]) dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]];
    }
    int mn=sum;
    for(int i=0; i<=half; i++) if(dp[arr.size()][i]) mn=min(mn,sum-2*i);
    return mn;
}

int count_the_number_of_way_to_make_dif_equal_of_two_subset(vector<int> &arr,int dif){
    int total=0;
    for(auto i: arr) total+=i;
    int a=(total-dif)/2;
    return count_the_total_no_of_way_of_given_sum(arr,a);
}

int count_target_sum_by_applying_plus_minus(vector<int> &arr,int sum){
    return count_the_number_of_way_to_make_dif_equal_of_two_subset(arr,sum);
}




void solve(){
    int n;
    cin>>n;
    int sum;
    cin>>n>>sum;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    cout<<count_the_number_of_way_to_make_dif_equal_of_two_subset(arr,sum)<<nl;
    cout<<count_target_sum_by_applying_plus_minus(arr,sum)<<nl;

}