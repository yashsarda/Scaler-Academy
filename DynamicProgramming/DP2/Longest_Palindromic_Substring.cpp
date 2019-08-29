string Solution::longestPalindrome(string A) {
    int size = A.size();
    if(size == 0)
        return "";
    if(size == 1)
        return A;
    
    string ans = "";
    int max_len = 0;
    vector<vector<bool> > dp;
    dp.resize(size + 5);
    for(int i=0;i<=size + 4;i++)
        dp[i].resize(size + 5);
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<size;i++){
        dp[i][i] = 1;
        if(max_len < 1){
            max_len = 1;
            ans += A[i];
        }
    }
        
    for(int i=0;i<size - 1;i++){
        dp[i][i + 1] = (A[i] == A[i + 1]);
        if(dp[i][i + 1] == 1 && max_len < 2){
            max_len = 2;
            ans = "";
            ans = A.substr(i,2);
        }
    }
    
    for(int l=3;l<=size;l++){
        for(int i=0;i + l <= size;i++){
            int j = i + l - 1;
            if(dp[i + 1][j - 1] == 1)
                dp[i][j] = (A[i] == A[j]);
            else
                dp[i][j] = 0;
            if(dp[i][j] == 1){
                if(max_len < l){
                    max_len = l;
                    ans = "";
                    ans = A.substr(i,l);
                }
            }
        }
    }
    return ans;
}
