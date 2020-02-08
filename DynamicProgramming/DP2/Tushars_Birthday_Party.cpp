const int INF = 99999999;
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int asize = A.size();
    int bsize = B.size();
    int csize = C.size();
    asize = *max_element(A.begin(),A.end());
    //dp[i][j] = minimum cost to make filling capacity to j using the first i elements
    
    int dp[bsize + 1][asize + 1];
    // Minimum cost to make filling capacity as 0 with 0 zero elements is 0
    dp[0][0] = 0;
    
    // Minimum cost to make filling capacity 0 with i elements is 0
    for(int i=1;i<=bsize;i++)
        dp[i][0] = 0;
    
    // Minimum cost to make filling capacity as i with 0 elements is INF
    for(int i=1;i<=asize;i++){
        dp[0][i] = INF;
    }
    
    // We can take every element value / capacity times
    // Check every possible value and take minimum of all these
    for(int i=1;i<=bsize;i++){
        for(int j=1;j<=asize;j++){
            int no = j / B[i - 1];
            int ans = dp[i - 1][j];
            for(int k=1;k<=no;k++){
                ans = min(ans,C[i - 1] * k + dp[i - 1][j - B[i-1] * k]);
            }
            dp[i][j] = ans;
        }
    }
    
    // To find the answer just find the minimum value in the respective columns
    int ans = 0;
    for(int i=0;i<A.size();i++){
        int column = A[i];
        int x = INF;
        for(int j=1;j<=bsize;j++){
            x = min(x,dp[j][column]);
        }
        
        ans += x;
    }
    return ans;
}
