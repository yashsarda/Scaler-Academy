int Solution::adjacent(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    if(col == 1)
        return max(A[0][0],A[1][0]);
    
    vector<vector<int> > dp;
    dp.resize(col);
    for(int i=0;i<col;i++)
        dp[i].resize(2);
    
    // dp[i][j] = maximum answer upto ith column
    // j = 0 include the column, j = 1 exclude the column
    // If we include then maximum number from that column will  be the answer
    dp[0][0] = max(A[0][0],A[1][0]);
    dp[0][1] = 0;
    for(int i=1;i<col;i++){
        // If we include then maximum number from that column + the maximum answer we get when we exclude the previous column
        dp[i][0] = max(A[0][i],A[1][i]) + dp[i - 1][1];
        // If we exculde then maximum will be maximum we get from the previous column
        dp[i][1] = max(dp[i - 1][1],dp[i - 1][0]);
    }
    return max(dp[col-1][0],dp[col-1][1]);
}
