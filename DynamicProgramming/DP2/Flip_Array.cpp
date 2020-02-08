// This problem is converted into knapsack problem
// Sum of all resultant elements should be as close to zero as possible
// Therefore the sum of all non negative elements will be <= TotalSum / 2
int Solution::solve(const vector<int> &A) {
    int size = A.size();
    int sum = 0;
    for(int x: A)
        sum += x;
    sum /= 2;
    int dp[size + 1][sum + 1];
    // With 0 elements and 0 sum, the minimum # = 0
    dp[0][0] = 0;
    // With 0 elements and i as sum, we cannot chhose any anything so any big number will be answer
    for(int i=1;i<=sum;i++)
        dp[0][i] = 99999999;
    // With i elements and 0 as sum, just don't negate anything, the sum will be 0 and min # of elements required = 0
    for(int i=1;i<=size;i++)
        dp[i][0] = 0;
    // Now for elements from [1...i], and we are at ith element we have 2 choices
    // Either select which we can do only if value < sum or don't select(like in knapsack)
    // If we select the 1 element is added to our answer and we required the sum of 
    // remaining elements now to be current sum - element value
    // if we don't select the sum of elements from [1..i-1] should be current sum
    for(int i=1;i<=size;i++){
        for(int j=1;j<=sum;j++){
            if(j - A[i - 1] >= 0)
                dp[i][j] = min(1 + dp[i - 1][j - A[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // The most optimal case would be when sum would be 0(total sum / 2)
    // But it's not necessarily be 0 so we need to find the first sum which is achievable and that sum
    // would be the answer since we want it to be as close to 0 as possible
    for(int j=sum;j>=1;j--){
        for(int i=size;i>=1;i--){
            if(dp[i][j] > 0 && dp[i][j] != 99999999)
                return dp[i][j];
        }
    }
}
