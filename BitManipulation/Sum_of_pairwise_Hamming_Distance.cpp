const int mod = 1000000007;
int Solution::hammingDistance(const vector<int> &A) {
    int n = A.size();
    long long ans = 0;
    for(int i = 0;i<32;i++){
        int cnt0 = 0;
        int cnt1 = 0;
        for(int j=0;j<n;j++){
            if(A[j] & (1 << i))
                cnt1++;
            else
                cnt0++;
        }
        ans = (ans  % mod + (cnt0 * 2ll * cnt1) % mod) % mod;
    }
    return ans;
}
