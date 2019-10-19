int Solution::solve(vector<vector<int> > &A) {
    int rows = A.size();
    int col = A[0].size();
    
    int ans = 1;
    for(int i=1;i<rows;i++) {
        for(int j=1;j<col;j++) {
            ans &= (A[i][j] == A[i - 1][j - 1]);
        }
    }
    return ans;
}
