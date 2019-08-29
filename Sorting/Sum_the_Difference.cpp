// Polynomial = c1* x^(3) + c2 * x^(2) + c3 * x^(1) + c4 * x^(0)
// (c1 * x + c2)*x^(2) + c3 * x^(1) + c4 * x^(0)
// ((c1 * x + c2) * x + c3) * x + c4 * x^0
typedef long long ll;
const int mod = 1e9 + 7;
int Solution::solve(vector<int> &A) {
    ll ans = 0;
    int n = A.size();
    sort(A.begin(),A.end());
    ll minSum,maxSum;
    minSum = maxSum = 0;
    for(int i=0;i<n;i++){
        minSum = (2 * minSum) + A[i];
        minSum %= mod;
        maxSum = (2 * maxSum) + A[n - 1 - i];
        maxSum %= mod;
    }
    
    return (maxSum - minSum + mod) % mod;
    
}
