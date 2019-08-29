const int mod = 1000000007;
int Solution::solve(int A) {
    if(A == 1)
        return 1;
    // dp[i] = number of ways to tile 2 X A board using 2 X 1 tiles
    vector<int> dp(A + 1,0);
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3;i<=A;i++)
        dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
    
    return dp[A];
}
