int Solution::solve(string A) {
    
    int size = A.size();
    if(size == 0)
        return 0;
    
    if(size == 1)
        return 1;
    
    vector<vector<int> > dp;
    dp.resize(size + 5);
    for(int i=0;i<size + 5;i++)
        dp[i].resize(size + 5,0);

    int max_len = 1;
    dp[0][0] = 0;
    
    for(int i=0;i<size;i++)
        dp[i][i] = 1;
    
    for(int i=0;i<size-1;i++){
        if(A[i] == A[i + 1])
            dp[i][i + 1] = 2;
        else
            dp[i][i + 1] = 1;
        max_len = max(max_len, dp[i][i + 1]);
    }
    
    for(int l=3;l<=size;l++){
        for(int i=0;i + l <=size;i++){
            int j = i + l - 1;
            if(A[i] == A[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            max_len = max(max_len, dp[i][j]);
        }
    }
    
    
    return max_len;
}

