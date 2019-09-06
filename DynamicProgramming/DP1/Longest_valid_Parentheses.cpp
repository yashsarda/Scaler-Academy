int Solution::longestValidParentheses(string A) {
    // dp[i] = length of the longest valid substring "ending" at index i;
    int n = A.size();
    
    // If A[i] = '(', then we can never form a valid substring ending at index i, since a valid substring
    // always ends with ')'
    // If A[i] = ')', then there are 2 cases
    // Case 1: A[i - 1] = '(' && A[i] = ')', so the string is of the from .....()
    // dp[i] = dp[i - 2] + 2
    // Case 2: A[i - 1] = ')' && A[i] = ')', so the string is of the form ....))
    // For the second last closing brace we find the length of longest substring at i - 1.
    // If the character before that is '(', then we can update i.e ((())). [1..4] is dp[i - 1], and 5 - 4 - 1 = s[0] = '('
    // then a valid substring can be formed
    // dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]. The last term is added for (())...(())) adjacent valid substrings
    
    vector<int> dp(n, 0);
    int ans = 0;
    for(int i=1;i<n;i++) {
        if(A[i] == '(')
            continue;
        if(A[i - 1] == '(') {
            if(i == 1)
                dp[i] = 2;
            else
                dp[i] = dp[i - 2] + 2;
            ans = max(ans, dp[i]);
        }
        if(A[i - 1] == ')') {
            if(i - dp[i - 1] - 1 >= 0 && A[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + 2;
                if(i - dp[i - 1] - 2 >= 0)
                    dp[i] += dp[i - dp[i - 1] - 2];
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
    
}
