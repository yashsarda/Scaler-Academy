const int mod = 1e9 + 7;
int Solution::nTriang(vector<int> &A) {
    int n = A.size();
    if(n <= 2)
        return 0;
    long long ans = 0;
    sort(A.begin(),A.end());
    for(int i=0;i<n-2;i++){
        for(int k=n-1;k>i+1;k--){
            int first = A[i];
            int third = A[k];
            int second = A[k] - A[i] + 1;
            int index = lower_bound(A.begin() + i + 1,A.begin() + k,second) - (A.begin());
            ans = (ans % mod + (k - index) % mod) % mod;
        }
    }
    return ans;
}
