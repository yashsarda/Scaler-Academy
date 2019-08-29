int Solution::lengthOfLongestSubstring(string A) {
    int n = A.size();
    if(n == 1)
        return 1;
    int start = 0,en = 0;
    int ans  = 0;
    int len = 0;
    map<char,int> m;
    for(int i=0;i<n;i++)
        m[A[i]] = -1;
    while(start < n && en < n){
        if(m[A[en]] == -1){
            m[A[en]] = en;
            en++;
        }
        else{
            len = en - start;
            ans = max(ans,len);
            for(int j=start;j<m[A[en]];j++)
                m[A[j]] = -1;
            start = m[A[en]] + 1;
            m[A[en]] = en; 
            en++;
        }
    }
    len = en - start;
    ans = max(ans,len);
    return ans;
}
