int Solution::numDecodings(string A) {
    // dp[i] = number of ways to decode the string at index i
    // Two cases: 
    // Case 1: The character at index i, to be a single number
    // dp[i] = dp[i - 1];
    // Case 2: The character at index i, to be a double digit if it lies in range [10,26]
    // dp[i] += dp[i - 2];
    int n = A.size();
    vector<int> dp(n, 0);
    // If the first character is 0 then 0 ways else 1 way
    dp[0] = (A[0] != '0'); 
    for(int i=1;i<n;i++){
        // If any char is 0 then we cannot split it indiviually
        if(A[i] != '0')
            dp[i] = dp[i - 1];
        // range [10, 26]
        if(A[i - 1] == '1' || A[i - 1] == '2' && A[i] <= '6') {
            if(i - 2 >= 0)
                dp[i] += dp[i - 2];
            else
                dp[i] += 1;
        }
    }
    return dp[n - 1];
}
