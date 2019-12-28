int dp[105][35000];
int findAnswer(int index, int sum1, int sum2, vector<int>& A)
{
    if(index == A.size()) {
        return sum1 * sum2;
    }
    
    if(dp[index][sum1] != -1)
        return dp[index][sum1];
    
    if(dp[index][sum2] != -1)
        return dp[index][sum2];
    
    int answer = -1;
    answer = max(findAnswer(index + 1, sum1 + A[index], sum2, A), findAnswer(index + 1, sum1, sum2 + A[index], A));
    return dp[index][sum1] = dp[index][sum2] = answer;
}
int Solution::solve(vector<int> &A) {
    int len = A.size();
    for(int i=0;i<105;i++) {
        for(int j=0;j<35000;j++) {
            dp[i][j] = -1;
        }
    }
    int answer = -1;
    answer = findAnswer(0, 0, 0, A);
    return answer;
}
