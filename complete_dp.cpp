#include"default.h"
//////////////     Bounded or 0/1 Knapsack ////////////////////////////////////


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

////////////////////////// Unbounded Knapsack  //////////////////////////////////
int rod_cutting_problem(vector<int> &length,vector<int>&price,int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=0; i<n; i++) dp[0][i]=0,dp[i][0]=1;
    // for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
    //     dp[i][j]=dp[i-1][j];
    //     if(j>=price[])
    // }
    return 0;

}

int coin_change_1_number_of_ways(vector<int>&coins,int sum){
    return 0;

}

int coin_change_2_min_coin_to_make_sum(vector<int> &coins,int sum){
    return 0;
}

///////////////////////////// Longest Common subsequence  ///////////////////////////////////
int length_of_lcs_rec(string &a,string &b,int ind1,int ind2,vector<vector<int>> &dp){
    if(ind1==0 || ind2==0) return 0;
    if(dp[ind1][ind2]==-1){
        if(a[ind1-1]==b[ind2-1]) dp[ind1][ind2]=1+length_of_lcs_rec(a,b,ind1-1,ind2-1,dp);
        else dp[ind1][ind2]=max(length_of_lcs_rec(a,b,ind1-1,ind2,dp),length_of_lcs_rec(a,b,ind1,ind2-1,dp));
    }
    return dp[ind1][ind2];
}

int length_of_lcs(string &a,string &b){
    int n=a.length(),m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=0; i<=m; i++) dp[0][i]=0;

    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[n][m];
}

int longest_common_substring(string &a,string &b){
    int n=a.length(),m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int j=0; j<=m; j++) dp[0][j]=0;
    int ans=-1;

    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]=0;
        ans=max(ans,dp[i][j]);
    }
    return ans;
}

string get_longest_common_subsequence(string &a,string &b){
    int n=a.length(),m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int j=0; j<=m; j++) dp[0][j]=0;
    for(int i=1; i<=n; i++) for(int j=1; j<=m ;j++){
        if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    string ans="";
    while(n && m){
        if(a[n-1]==b[m-1]) ans+=a[n-1],n--,m--;
        else{
            if(dp[n][m-1]<dp[n-1][m]) n--;
            else m--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}

int shortest_common_super_sequence(string &a,string &b){
    
}




void solve(){
    string a,b;
    cin>>a>>b;
    cout<<length_of_lcs(a,b)<<nl;
    vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,-1));
    cout<<longest_common_substring(a,b)<<nl;
    cout<<get_longest_common_subsequence(a,b)<<nl;
}