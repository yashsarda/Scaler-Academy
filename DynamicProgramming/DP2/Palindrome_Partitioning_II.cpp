int Solution::minCut(string A) {
    int n = A.size();
    if(n <= 1)
        return 0;
    
    if(n == 2){
        return (A[0] == A[1] ? 0 : 1);
    }
    // First compute the dp table to know whether substring (i,j) is a palindrome or not
    
    // If we have to calculate the answer for index i, and we already have the ans for values from [0,i)
    // Then we can partition at each index < i and check [index + 1,i] is palindrome or not
    // If it is then cost[i] = cost[k] + 1 (for all k < i)
    
    vector<vector<bool> > dp;
    dp.resize(n + 5);
    for(int i=0;i<n + 5;i++)
        dp[i].resize(n + 5,0);
    
    for(int i=0;i<n;i++)
        dp[i][i] = 1;
    
    for(int i=0;i<n - 1;i++)
        dp[i][i + 1] = (A[i] == A[i + 1]);
    
    for(int l=3;l<=n;l++){
        for(int i=0;i + l<=n;i++){
            int j = i + l - 1;
            if(A[i] == A[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    vector<int> cost(n + 1,10000000);
    
    cost[0] = 0;
    for(int i=1;i<n;i++){
        for(int j=-1;j<i;j++){
            // -1 indicates no cut is made and complete substring is a palindrome
            if(dp[j + 1][i] == 1){
                if(j == -1)
                    cost[i] = 0;
                else
                    cost[i] = min(cost[i], cost[j] + 1);
            }
        }
    }
    
    return cost[n - 1];
    
}
