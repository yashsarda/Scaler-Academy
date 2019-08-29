vector<vector<int> > dp;
// Greedy will not work. eg: 3 100 2 1. 
// Here we have an element of choice. So we try to examine both the choices and whichever gives
// the maximum answer will be our answer
int findMax(vector<int>& A,int i,int j)
{
    if(i == j)
        return A[i];
    
    if(j == i + 1)
        return max(A[i],A[j]);
        
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int ans = 0;
    ans = max(A[i] + min(findMax(A,i + 2,j), findMax(A,i + 1,j - 1)), A[j] + min(findMax(A,i + 1,j - 1),findMax(A,i,j - 2)));
    dp[i][j] = ans;
    return ans;
}
int Solution::maxcoin(vector<int> &A) {
    int size = A.size();
    if(size == 0)
        return 0;
    if(size == 2)
        return max(A[0],A[1]);
    dp.clear();
    dp.resize(size + 1);
    for(int i=0;i<=size;i++)
        dp[i].resize(size + 1,-1);
    
    int ans = 0;
    ans = findMax(A,0,size-1);
    return ans;
}
