int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int rows = A.size();
    int col = A[0].size();
    
    int dp[rows + 5][col + 5];
    memset(dp,0,sizeof(dp));
    
    dp[rows - 1][col - 1] = (A[rows - 1][col - 1] < 0 ? abs(A[rows - 1][col - 1]) + 1 : 1);
    
    for(int i=col-2;i>=0;i--){
        dp[rows - 1][i] = A[rows - 1][i] - dp[rows - 1][i + 1] < 0 ? dp[rows - 1][i + 1] - A[rows - 1][i] : 1;
    }
    
    for(int i=rows-2;i>=0;i--){
        dp[i][col-1] = A[i][col-1] - dp[i + 1][col-1] < 0 ? dp[i + 1][col - 1] - A[i][col - 1] : 1;
    }
    
    for(int i=rows - 2;i>=0;i--){
        for(int j=col-2;j>=0;j--){
            int val1 = A[i][j] - dp[i + 1][j];
            int val2 = A[i][j] - dp[i][j + 1];
            int t = max(val1,val2);
            if(t < 0)
                dp[i][j] = abs(t);
            else
                dp[i][j] = 1;
        }
    }
    return dp[0][0];
}
