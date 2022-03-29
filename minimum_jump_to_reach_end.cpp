/*
You have given an array and you have to find minimum jump to reach the end of the array.
You can jump upto given a[i].

2
6
3 4 2 1 2 1
9
4 1 5 3 1 3 2 1 8


op-
2
3 

ex-> on first position you can jump upto three position.similarly all.

3->4->1







*/

void minimum_jump_to_reach_end(int arr[],int n){
    int dp[n];
    for(int i=0; i<n; i++) dp[i]=INT_MAX;
    dp[0]=0;

    for(int i=0; i<n-1; i++){
        for(int j=1; j<=arr[i]; j++){
            if(j+i<n)
                dp[j+i]=min(dp[j+i],dp[i]+1);
        }
    }

    for(int i=0; i<n; i++) cout<<dp[i]<<spc;
    cout<<nl<<dp[n-1]<<nl;
}