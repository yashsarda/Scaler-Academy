const int mod = 1000000007;
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int i = 0,j = n - 1;
    int ans = 0;
    while(i <= j){
        int prod = 1ll * A[i] * A[j];
        if(prod >= B)
            j--;
        else{
            int l = j - i + 1;
            ans = (ans % mod + (2ll * l - 1) % mod ) % mod;
            i++;
        }
    }
    return ans;

}
