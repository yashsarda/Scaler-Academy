int Solution::solve(string A) {
    int len = A.size();
    if(len == 1)
        return 1;
    
    int answer = 0;
    bool dp[len][len];
    for(int i=0;i<len;i++)
        dp[i][i] = true;
    
    for(int i=0;i<len - 1;i++)
        dp[i][i + 1] = A[i] == A[i + 1];
    
    for(int l=3;l<=len;l++){
        for(int j=0;j<=len-l;j++) {
            int k = j + l - 1;
            dp[j][k] = (A[j] == A[k] && dp[j + 1][k - 1]);
        }
    }
    for(int i=0;i<len;i++) {
        for(int j=i;j<len;j++) {
            answer += (dp[i][j] == true);
        }
    }
    return answer;
}
