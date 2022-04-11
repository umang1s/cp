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
    return a.length()+b.length()-length_of_lcs(a,b);
}
string get_shortest_common_super_sequence_dp(string&a, string &b){
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
            if(dp[n][m-1]<dp[n-1][m]) ans+=a[n-1],n--;
            else ans+=b[m-1],m--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string get_shortest_common_super_sequence(string&a, string &b){
    string ans="";
    string ls=get_longest_common_subsequence(a,b);
    int i=0,j=0,k=0;
    while(k<ls.length()){
        if(ls[k]==a[i] &&  ls[k]==b[j]) ans+=ls[k],k++,i++,j++;
        else{
            if(ls[k]==a[i]) ans+=b[j],j++;
            else ans+=a[i],i++;
        }
    }
    while(i<a.length()) ans+=a[i],i++;
    while(j<b.length()) ans+=b[j],j++;
    return ans;
}


int min_no_of_insertion_and_deletion_to_make_a_to_b(string &a,string &b){
    int ls=length_of_lcs(a,b);
    int insertion=a.length()-ls;
    int deletion=b.length()-ls;
    return insertion+deletion;
}

int largest_palindromic_subsequence(string &a){
    string rev=a;
    reverse(a.begin(),a.end());
    return length_of_lcs(a,rev);
}
int min_no_of_deletion_to_make_it_palindrome(string &a){
    return a.length()-largest_palindromic_subsequence(a);
}
int min_no_of_insertion_to_make_it_palindrome(string &a){
    return a.length()-largest_palindromic_subsequence(a);
}

int longest_repeating_sub_sequence(string &a){  
    //aabebcdd   //abc
    int n=a.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=0; i<=n; i++) dp[i][0]=dp[0][i]=0;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(i!=j && a[i-1]==a[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
    return dp[n][n];
}

int length_of_longest_increasing_subsequence_method_1(vector<int> &arr){
    vector<int> ans;
    for(int i: arr){
        auto it=lower_bound(ans.begin(),ans.end(),i);
        if(it==ans.end()) ans.push_back(i);
        else if(*it>i) *it=i;
    }
    return ans.size();
}
int length_of_longest_increasing_subsequence_method_2(vector<int> &arr){
    vector<int> dp(arr.size(),1);
    for(int i=0; i<arr.size(); i++) for(int j=0; j<i; j++){
        if(arr[i]>arr[j] && dp[i]<=dp[j]) dp[i]=1+dp[j];
    }
    int mx=0;
    for(auto i: dp) mx=max(mx,i);
    return mx;
}
vector<int> get_longest_increasing_subsequence(vector<int> &arr){
    vector<int> dp(arr.size(),1),ans;
    for(int i=0; i<arr.size(); i++) for(int j=0; j<i; j++) if(arr[i]>arr[j] && dp[i]<=dp[j]) dp[i]=1+dp[j];
    int mx=0;
    for(auto i: dp) mx=max(mx,i);
    int ind=arr.size()-1;
    while(mx){
        if(dp[ind]==mx) ans.push_back(arr[ind]),mx--;
        ind--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int number_of_longest_increasing_subsequene(vector<int> &arr){
    vector<int> dp(arr.size(),1),count(arr.size(),1);
    for(int i=0; i<arr.size(); i++) for(int j=0; j<i; j++) if(arr[i]>arr[j]){
        if(dp[j]+1>dp[i]) dp[i]=1+dp[j],count[i]=count[j];
        else if(dp[j]+1==dp[i]) count[i]+=count[j];
    }
    int mx=0,ans=0;
    for(auto i: dp) mx=max(mx,i);
    for(int i=0; i<arr.size(); i++) if(dp[i]==mx) ans+=count[i];
    return ans;
}

int maximum_number_of_bridge_can_connect(vector<pair<int,int>> &connections){
    //if duplicate is not allowed
    int n=connections.size();
    sort(connections.begin(),connections.end());
    vector<int> arr;
    for(auto i: connections) arr.push_back(i.second);
    return length_of_longest_increasing_subsequence_method_1(arr);
}

int box_stacking_problem(vector<vector<int>> &boxes){
    //height,width,length
    //not solved
    int ans=0;
    vector<vector<int>> allBoxes;
    for(auto i: boxes){
        allBoxes.push_back({i[0],i[1],i[2]});
        allBoxes.push_back({i[0],i[2],i[1]});
        allBoxes.push_back({i[1],i[2],i[0]});
        allBoxes.push_back({i[1],i[0],i[2]});
        allBoxes.push_back({i[2],i[1],i[0]});
        allBoxes.push_back({i[2],i[0],i[1]});
    }
    sort(allBoxes.begin(),allBoxes.end());
    int n=allBoxes.size();
    vector<int> dp(n,1);
    for(int i=0; i<n; i++)for(int j=0; j<i; j++){
        if(allBoxes[i][1]>allBoxes[j][1] && allBoxes[i][2]>allBoxes[j][2] && dp[i]<=dp[j])
            dp[i]=1+dp[j];
    }
    int mx=0;
    for(auto i: dp) mx=max(mx,i);
    int ind=n-1;
    while(mx){
        if(dp[ind]==mx) ans+=allBoxes[ind][0],mx--;
        ind--;
    }
    return ans;
}

bool envelop_sorting(vector<int> &a,vector<int>&b){
    if(a[0]<b[0]) return true;
    if(a[0]>b[0]) return false;
    return a[1]>b[1];
}
int russian_doll_problem_method1(vector<vector<int>> &envelopes){
    if(envelopes.size()==0) return 0;
    sort(envelopes.begin(),envelopes.end(),envelop_sorting);
    vector<int> second;
    for(auto i: envelopes) second.push_back(i[1]);
    return length_of_longest_increasing_subsequence_method_1(second);
}
int russian_doll_problem_method2(vector<vector<int>> &envelopes){
    int n=envelopes.size();
    if(n==0) return 0;
    sort(envelopes.begin(),envelopes.end());
    vector<int> dp(n,1);
    for(int i=0; i<n; i++) for(int j=0; j<i; j++){
        if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1] && dp[i]<=dp[j])
            dp[i]=1+dp[j];
    }
    int mx=0;
    for(auto i: dp) mx=max(mx,i);
    return mx;
}

int maximum_sum_increasing_subsequence(vector<int> &arr){
    //1 100 3 2 6  
    //(1+2+6=9), (1+3+6)=10, (1+100)=101  output 101
    int n=arr.size();
    vector<int> dp(n,1),sum(n);
    for(int i=0; i<n; i++) sum[i]=arr[i];
    for(int i=0; i<n; i++) for(int j=0; j<i; j++){
        if(arr[i]>arr[j] && dp[i]<=dp[j]) dp[i]=1+dp[j],sum[i]+=arr[j]; 
    }
    int mx=0;
    for(auto i:sum) mx=max(mx,i);
    return mx;

}



/////////////////////////////////////////////// MCM //////////////////////////////////////////////////////////
int matrix_chain_multiplication(vector<vector<int>> &dp, vector<int> &arr,int i,int j){
    //call from i=1, j=n-1
    if(i>=j) return 0;
    if(dp[i][j]==-1){
        int mn=INT_MAX;
        for(int x=i; x<j; x++){
            int temp=matrix_chain_multiplication(dp,arr,i,x)+matrix_chain_multiplication(dp,arr,x+1,j)+arr[i-1]*arr[x]*arr[j];
            mn=min(mn,temp);
        }
        dp[i][j]=mn;
    }
    return dp[i][j];
}

int matrix_chain_multiplication_table(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=0; i<=n; i++) for(int j=0; j<=n ;j++){
        if(i<=j) dp[i][j]=0;
        else{
            int mn=INT_MAX;
            for(int k=i; k<j; k++)
        }
    }
    return dp[0][n];
}

bool isPalindrome(string &s,int i,int j){
    while(i<j){if(s[i]!=s[j]) return false; i++,j--;}
    return true;
}

int palindrome_patiotioning(string &s,int i,int j,vector<vector<int>> &dp){
    //minimum number of partition to make all substring palindrome
    if(i>=j) return 0;
    if(isPalindrome(s,i,j)) return 0;
    if(dp[i][j]==-1){
        int ans=INT_MAX;
        for(int k=i; k<j; k++){
            int temp=1+palindrome_patiotioning(s,i,k,dp)+palindrome_patiotioning(s,k+1,j,dp);
            if(ans>temp) ans=temp;
        }
        dp[i][j]=ans;
    }
    return dp[i][j];
}
int evaluate_expression_to_true(string &s){
    //we have given a string made of "T, F, |, &, ^"
    //make bracket such that whole expression will fall true
    //count the number of ways it can 
    //example "T|F&T"
}

/////////////////////////////// DP on Tree /////////////////////////////////
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int v){
        val=v;
        left=right=NULL;
    }
};

int diameter_of_a_tree(TreeNode* root,int &ans){//initial ans=INT_MIN;
    if(root==NULL) return 0;
    int l=diameter_of_a_tree(root->left,ans);
    int r=diameter_of_a_tree(root->right,ans);
    ans=max(ans,1+l+r);
    return 1+max(l,r);
}

int maximum_path_sum_from_any_node_to_any_node(TreeNode*root,int &ans){
    if(root==NULL) return 0;
    int l=maximum_path_sum_from_any_node_to_any_node(root->left,ans);
    int r=maximum_path_sum_from_any_node_to_any_node(root->right,ans);
    ans=max(ans,root->val+l+r);
    return max(root->val, max(l,r)+root->val);
}

int maximum_path_sum_from_leaf_node_to_leaf_node(TreeNode *root,int &ans){
    if(root==NULL) return 0;
    int l=maximum_path_sum_from_leaf_node_to_leaf_node(root->left,ans);
    int r=maximum_path_sum_from_leaf_node_to_leaf_node(root->right,ans);
    ans=max(ans,root->val+l+r);
    return max(l,r)+root->val;
}

void solve(){
    string a,b;
    cin>>a>>b;
    cout<<length_of_lcs(a,b)<<nl;
    vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,-1));
    cout<<longest_common_substring(a,b)<<nl;
    cout<<get_longest_common_subsequence(a,b)<<nl;
    cout<<shortest_common_super_sequence(a,b)<<nl;
    cout<<get_shortest_common_super_sequence(a,b)<<nl;
    cout<<get_shortest_common_super_sequence_dp(a,b)<<nl;
    cout<<min_no_of_insertion_and_deletion_to_make_a_to_b(a,b)<<nl;
    string c;
    cin>>c;
    cout<<largest_palindromic_subsequence(c)<<nl;
    cout<<min_no_of_deletion_to_make_it_palindrome(c)<<nl;
    cout<<longest_repeating_sub_sequence(c)<<nl;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    cout<<length_of_longest_increasing_subsequence_method_1(arr)<<nl;
    cout<<length_of_longest_increasing_subsequence_method_2(arr)<<nl;
    vector<int> lisArray=get_longest_increasing_subsequence(arr);
    for(auto i: lisArray) cout<<i<<spc;
    cout<<nl;
    cout<<number_of_longest_increasing_subsequene(arr)<<nl;
    cout<<maximum_sum_increasing_subsequence(arr)<<nl;
}