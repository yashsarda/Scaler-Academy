vector<vector<int> > Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    int n1 = A.size();
    int n2 = B.size();
    
    vector<int> prefixxor(n1+1);
    vector<int> prefixsum(n1+1);
    prefixsum[0] = 0;
    for(int i=1;i<=n1;i++)
        prefixsum[i] = prefixsum[i-1] + A[i-1];
        
    prefixxor[0] = 0;
    for(int i=1;i<=n1;i++)
        prefixxor[i] = prefixxor[i-1] ^ A[i - 1];
        
    vector<vector<int> > ans;
    ans.resize(n2);
    for(int i=0;i<n2;i++)
        ans[i].resize(2);
    for(int i=0;i<n2;i++){
        int l = B[i][0];
        int r = B[i][1];
        
        ans[i][0] = prefixxor[r] ^ prefixxor[l-1];
        ans[i][1] = (r - l + 1) - (prefixsum[r] - prefixsum[l-1]); 
    }
    return ans;
        
    
}
