int Solution::countMinSquares(int A) {
    if(A == 0)
        return 0;
    int max_square = 0;
    for(int i=1;i*i<=A;i++){
        max_square = i * i;
    }
    // dp[i] = minimum number required to represent N as sum of squares
    vector<int> dp(A + 5,INT_MAX);
    // to represent 0 we require 0 numbers
    dp[0] = 0;
    // To represent prefect squares we just require 1 number
    for(int i=1;i*i<=max_square;i++)
        dp[i * i] = 1;
    // For a number N, we can break it down as N - perfect square for all perfect squares <= N 
    // for eg: 23 = 23 - 1, 23 - 4, 23 - 9, 23 - 16
    // The optimal answer will be the minimum of all the above
    for(int i=2;i<=A;i++){
        for(int j=1;j*j<=i;j++){
            dp[i] = min(dp[i],dp[i-j*j] + 1);
        }
    }
    return dp[A];
    
}
