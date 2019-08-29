vector<int> dp;
int Solution::wordBreak(string A, vector<string> &B) {
    string s = A;
    int si = s.size();
    int size = B.size();
    
    if(size == 0)
        return 0;
    set<string> isPresent(B.begin(),B.end());
     
    dp.clear();
    dp.resize(si + 5, 0);
    dp[0] = 1;
    
    for(int i=1;i<=si;i++){
        int start = si - i;
        for(int j=1;j<=i;j++){
            string temp = s.substr(start,j);
            if(isPresent.find(temp) != isPresent.end()){
                dp[i] |= dp[i-j];
                if(dp[i])
                    break;
            }
        }
    }
    
    return dp[si];  
}
