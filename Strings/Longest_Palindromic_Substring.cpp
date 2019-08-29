string Solution::longestPalindrome(string A) {
    int n = A.size();
    if(n == 0)
        return "";
    if(n == 1)
        return A;
    // dp[i][j] = The substring [i...j] is a palindrome
    // dp[i][j] = true if (s[i) == s[j]) && dp[i+1][j-1] is true
    vector<vector<bool> > dp;
    dp.resize(n + 2);
    for(int i=0;i<n + 2;i++)
        dp[i].resize(n + 2);
    for(int i=0;i<n+2;i++)
        for(int j=0;j<n+2;j++)
            dp[i][j] = false;
    // All substring of length 1 form a palindrome
    for(int i=0;i<n+2;i++)
        dp[i][i] = true;
    int max_len = 1;
    int len = 0;
    int start = 0,end = 0;
    
    // Those substring which have same adjacent characters form a palindorme of length 2
    for(int i=0;i<n-1;i++){
        if(A[i] == A[i + 1]){
            dp[i][i+1] = true;
            len = 2;
        }
        if(len > max_len){
            max_len = len;
            start = i;
            end = i + 1;
        }
    }
    
    // Iterate over all the length from 3 to n
    for(int i=3;i<=n;i++){
        for(int j=0;j<n - i + 1;j++){
            int k = j + i - 1;
            // If this forms a palindrome then update maximum length 
            if(A[j] == A[k] && dp[j + 1][k - 1] == true){
                dp[j][k] = true;
                 if(i > max_len){
                    max_len = i;
                    start = j;
                    end = k;
                }
            }
            else
                dp[j][k] = false;
        }
    }
    
    string ans = "";
    for(int i=start;i<=end;i++)
        ans += A[i];
    return ans;
}
