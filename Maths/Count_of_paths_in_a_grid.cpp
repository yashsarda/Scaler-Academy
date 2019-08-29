// The answer is the nth catalan number
#define ll long long
#define pii pair<int, int>
#define f first
#define S second

const int N = 2e6 + 10, mod = 1e9 + 7;
int fact[N], invfact[N];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((ll) x) * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
void pre(int F){
    fact[0] = invfact[0] = 1;
    for(int i = 1;i < F; i++) fact[i] = mul(i, fact[i - 1]);
    invfact[F - 1] = inv(fact[F - 1]);
    for(int i = F - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
    assert(invfact[1] == 1);
}
inline int C(int n, int k){
    if(n < k || k < 0) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}
int Solution::solve(int A) {
    pre(2*A+1);

    int ans = 0;
    ans = (C(2*A,A) * 1ll * inv(A+1)) % mod;
    return ans;
}
