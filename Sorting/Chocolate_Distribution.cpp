int Solution::solve(vector<int> &A, int B) {
    
    int ans = INT_MAX;
    int n = A.size();
    sort(A.begin(),A.end());
    if(n == 0 || B == 0)
        return 0;
    if(B == 1)
        return A[0];
    for(int i=0;i<=n - B;i++){
        ans = min(ans, A[i + B - 1] - A[i]);
    }
    return ans;
}
