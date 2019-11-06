vector<int> dp;
int ans;
bool check(char brace)
{
    if(brace == '[' || brace == '{' || brace == '(' || brace == '<')
        return 0;
    
    return 1;
}
void maximise(char brace, const string A, int i)
{
    if(A[i - 1] == brace) {
        if(i == 1)
            dp[i] = 2;
        else
            dp[i] = dp[i - 2] + 2;
        ans = max(ans, dp[i]);
    }
    if(check(A[i - 1])) {
        if(i - dp[i - 1] - 1 >= 0 && A[i - dp[i - 1] - 1] == brace) {
            dp[i] = dp[i - 1] + 2;
            if(i - dp[i - 1] - 2 >= 0)
                dp[i] += dp[i - dp[i - 1] - 2];
            ans = max(ans, dp[i]);
        }
    }
}
int Solution::LBSlength(const string A) {
       // dp[i] = length of the longest valid substring "ending" at index i;
    int n = A.size();
    dp.clear();
    dp.resize(n, 0);
    ans = 0;
    for(int i=1;i<n;i++) {
        if(!check(A[i]))
            continue;
        if(A[i] == ')') {
            maximise('(',A, i);
        }
        else if(A[i] == ']') {
            maximise('[',A, i);
        }
        else if(A[i] == '}') {
            maximise('{',A, i);
        }
        else if(A[i] == '>') {
            maximise('<',A, i);
        }
    }
    return ans;
    
}
