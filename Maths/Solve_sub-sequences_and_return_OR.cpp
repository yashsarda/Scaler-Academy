int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n == 1){
        if(A[0] > 1)
            return 0;
        return 1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = __gcd(ans,A[i]);
    }
    if(ans == 1)
        return 1;
    return 0;
}
