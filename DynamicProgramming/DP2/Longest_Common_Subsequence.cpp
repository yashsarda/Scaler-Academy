int Solution::solve(string A, string B) {
    int asize = A.size();
    int bsize = B.size();
    
    int dp[asize + 1][bsize + 1];
    for(int i=0;i<=asize;i++){
        for(int j=0;j<=bsize;j++){
            dp[i][j] = 0;
        }
    }
    
    int ans = 0;
    for(int i=1;i<=asize;i++){
        for(int j=1;j<=bsize;j++){
            if(A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            ans = max(ans, dp[i][j]);
        }
        
    }
    return ans;
}
