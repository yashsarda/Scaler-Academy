int Solution::longestSubsequenceLength(const vector<int> &A) {
    int size = A.size();
    vector<int> LIS(size,1);
    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){
            if(A[j] < A[i]){
                LIS[i] = max(LIS[i],LIS[j] + 1);
            }
        }
    }
    vector<int> LDS(size,1);
    for(int i=size-2;i>=0;i--){
        for(int j=i+1;j<size;j++){
            if(A[j] < A[i])
                LDS[i] = max(LDS[i],LDS[j] + 1);
        }
    }
    int ans = 0;
    for(int i=0;i<size;i++){
        ans = max(ans,LIS[i] + LDS[i] - 1);
    }
    return ans;
}
