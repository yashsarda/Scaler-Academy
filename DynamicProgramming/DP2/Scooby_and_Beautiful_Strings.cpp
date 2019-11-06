int LCS(string A, string B)
{
    int m = A.length();
    int n = B.length();
    
    int dp[m + 1][n + 1];
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            dp[i][j] = 0;
        }
    }
    
    int len = 0;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            len = max(len, dp[i][j]);
        }
    }
    return len;
}
int Solution::getMaxLengthOfBeautifulString(string A) {
    
    int len = A.size();
    if(len <= 1)
        return 0;
    
    int ans = 0;
    for(int i=1;i<len;i++) {
        string first = A.substr(0, i);
        string second = A.substr(i);
        ans = max(ans, LCS(first, second));
    }
    
    return ans * 2;
}
