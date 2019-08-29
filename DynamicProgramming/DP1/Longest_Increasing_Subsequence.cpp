int Solution::lis(const vector<int> &A) {
    int n = A.size();
    if(n == 1)
        return 1;
    // LIS[i] = Longest increasing subsequence uptil i
    vector<int> LIS(n,1);
    int ans = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(A[i] > A[j])
                LIS[i] = max(LIS[i],LIS[j] + 1);
        }
        ans = max(ans,LIS[i]);
    }
    return ans;
    
}
