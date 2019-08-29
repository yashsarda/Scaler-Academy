const int mod = 1e9 + 7;
typedef long long ll;
inline ll mul(ll a,ll b)
{
    return (a % mod * b % mod) % mod;
}
inline ll add(ll a,ll b)
{
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    unordered_map<int,int> xmap;
    unordered_map<int,int> ymap;
    for(int i=0;i<n;i++){
        xmap[A[i]]++;
        ymap[B[i]]++;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        int xpoint = A[i];
        int ypoint = B[i];
        int n1 = xmap[xpoint];
        int n2 = ymap[ypoint];
        ans = add(ans,mul(n1-1,n2-1));
    }
    return ans;
}
