int Solution::solve(const string A) {
    
    int n = A.size();
    int count_ones = 0;
    int ans = INT_MAX;
    int forward_sum = 0;
    for(int i=0;i<n;i++){
        if(A[i] == '0')
            forward_sum += count_ones;
        else
            count_ones++;
    }
    int backward_sum = 0;
    count_ones = 0;
    for(int i=n-1;i>=0;i--){
        if(A[i] == '0')
            backward_sum += count_ones;
        else
            count_ones++;
    }
    ans = min(backward_sum,forward_sum);
    return ans;
}
