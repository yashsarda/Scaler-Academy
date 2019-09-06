int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n <= 1)
        return 0;
    
    int res = 0;
    vector<int> min_from_left(n), max_from_right(n);
    min_from_left[0] = A[0];
    for(int i=1;i<n;i++)
        min_from_left[i] = min(min_from_left[i - 1], A[i]);
    
    max_from_right[n - 1] = A.back();
    for(int i=n - 2;i>=0;i--)
        max_from_right[i] = max(max_from_right[i + 1], A[i]);
    
    // Perform one transaction from left, where we sell at ith index
    vector<int> perform_one(n);
    perform_one[0] = 0;
    for(int i=1;i<n;i++)
        perform_one[i] = max(perform_one[i - 1], A[i] - min_from_left[i - 1]);
    
    // If we perform the second transaction at ith index, then we take first transaction should happen before ith index
    for(int i=n - 2;i>=0;i--){
        res = max(res, max_from_right[i + 1] - A[i] + ((i > 0) ? perform_one[i - 1] : 0));
    }
    return res;
}
