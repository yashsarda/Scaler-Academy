
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    
    if(n <= 1)
        return 0;
    
    int ans = 0;
    for(int i=1;i<n;i++){
        ans += max(abs(A[i] - A[i - 1]), abs(B[i] - B[i - 1]));
    }
    
    return ans;
}
