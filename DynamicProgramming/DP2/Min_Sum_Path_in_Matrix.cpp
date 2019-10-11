int Solution::minPathSum(vector<vector<int> > &A) {
    if(A.empty()) return 0;
    
    int rows = A.size();
    int col = A[0].size();
    
    vector<vector<int> > dp;
    dp.resize(rows);
    for(int i=0;i<rows;i++)
        dp[i].resize(col);
    
    dp[0][0] = A[0][0];
    for(int i=1;i<col;i++)
        dp[0][i] = A[0][i] + dp[0][i - 1];
        
    for(int i=1;i<rows;i++)
        dp[i][0] = dp[i - 1][0] + A[i][0];
    
    for(int i=1;i<rows;i++) {
        for(int j=1;j<col;j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + A[i][j];
        }
    }
    return dp[rows - 1][col - 1];
}
