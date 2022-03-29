#include"default.h"
//using dp
vii dp;
//Using Memoization methods
int longest_common_subsequence(string s1,string s2,int a,int b){
    if(dp[a][b]!=-1) return dp[a][b];
    if(a<1 || b<1) dp[a][b]=0;
    else{
        if(s1[a-1]==s2[b-1]) dp[a][b]=1+longest_common_subsequence(s1,s2,a-1,b-1);
        else dp[a][b]= max(longest_common_subsequence(s1,s2,a-1,b),
                           longest_common_subsequence(s1,s2,a,b-1));
    }
    return dp[a][b];
}

///Using tabulation methods
int longest__common_subsequence(string s1,string s2,int a,int b){
    int dpt[a+1][b+1];
    for(int i=0; i<=a; i++) dpt[i][0]=0;
    for(int i=0; i<=b; i++) dpt[0][i]=0;
    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++){
            if(s1[i-1]==s2[j-1])
                dpt[i][j]=1+dpt[i-1][j-1];
            else
                dpt[i][j]=max(dpt[i-1][j],dpt[i][j-1]);
        }
    
    return dpt[a][b];

}

/*  Where we use this methods

1.  Diff utility
2.  Minimum insertion and deletion to convert s1=s2
3.  Shortest common subsequence



*/

int solve(){
    string s1,s2;
    cin>>s1>>s2;
    dp=vii(s1.length()+1,vi(s2.length()+1,-1));
    cout<<longest_common_subsequence(s1,s2,s1.length(),s2.length())<<nl;
    cout<<longest__common_subsequence(s1,s2,s1.length(),s2.length());
    return 0;

}