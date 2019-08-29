int Solution::maxProfit(const vector<int> &A) {
    int size = A.size();
    if(size <= 1)
        return 0;
    
    int max_profit = 0;
    int max_from_right = A.back();
    
    for(int i=size-2;i>=0;i--){
        max_profit = max(max_profit, max_from_right - A[i]);
        max_from_right = max(max_from_right, A[i]);
    }
    
    return max_profit;
}
