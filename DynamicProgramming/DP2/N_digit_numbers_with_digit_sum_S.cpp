const int mod = 1000000007;
vector<vector<int> > dp;
int add(int a,int b)
{
    a = (a % mod + b % mod) % mod;
    if(a >= mod)
        a -= mod;
    
    return a;
}
int F(int N,int S)
{
    // Base case
    if(N == 0 && S == 0)
        return 1;
    
    if(N == 0 || S < 0)
        return 0;
    // dp memoization
    if(dp[N][S] != -1)
        return dp[N][S];
    // hypothesis
    int ans = 0;
    if(N == 1){
        for(int i=1;i<=9;i++)
            ans = add(ans, F(N - 1,S - i));
    }
    else {
        for(int i=0;i<=9;i++)
            ans = add(ans, F(N - 1, S - i));
    }
    
    dp[N][S] = ans;
    
    return ans;
    // induction
}
int Solution::solve(int A, int B) {
    // A = N and B = S
    int N = A;
    int S = B;
    if(S == 0)
        return 1;
        
    // F(N,S) = #number of N digit numbers with sum = S
    // F(N,S) = sum(F(N-i, S-d[k])) for all 0<i<=N-1 && d[k] = {0,...,9}, for i=0 d[k] = {1,...,9}
    dp.resize(N + 5);
    for(int i=0;i<N + 5;i++)
        dp[i].resize(S + 5,-1);
    
    int ans = F(N,S);
    return ans;
    
}
