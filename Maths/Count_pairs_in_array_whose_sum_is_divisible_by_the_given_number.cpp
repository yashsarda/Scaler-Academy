const int mod = 1e9 + 7;

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> cnt(B,0);
    for(int i=0;i<n;i++)
        cnt[A[i] % B]++;
    int ans = (1ll * cnt[0] * (cnt[0]-1)) >> 1;
    for(int i=1;i<B/2;i++){
        ans += (1ll * cnt[i] * cnt[B-i]);
        ans %= mod;
    }
    if(B % 2 == 0)
        ans += ((1ll * cnt[B/2]  * (cnt[B/2] -1)) >> 1);
    else{
        ans += 1ll * cnt[B/2] * cnt[B/2+1];
        ans %=mod;
    }

    return ans;
}
