
int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n <= 2)
        return n;
        
    int max_len = 1;
    map<pair<int,long long>,int> dp;
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            long long diff = A[i] - A[j];
            dp[{i,diff}] = 1 + dp[{j,diff}];
            max_len = max(max_len, dp[{i,diff}]);
        }
    }
    return max_len + 1;
    
}
