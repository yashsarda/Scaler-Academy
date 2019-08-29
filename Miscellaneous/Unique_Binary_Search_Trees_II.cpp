vector<int> dp;
int catalan(int A)
{
    if(A <= 1)
        return 1;
    if(dp[A] != -1)
        return dp[A];
    int sum = 0;
    for(int i=1;i<=A;i++){
        sum += catalan(i-1) * catalan(A - i);
    }
    dp[A] = sum;
    return sum;
}
int Solution::numTrees(int A) {
    if(A <= 1)
        return 1;
    dp.resize(A + 1,-1);
    int ans = catalan(A);
    return ans;
}
