// AC in one go :)
typedef long long ll;
const int mod = 1e9 + 7;
inline ll add(ll a,ll b)
{
    a += b;
    if(a >= mod)
        a-= mod;
    return a;
}
inline ll mul(ll a,ll b)
{
    return (a % mod * b % mod) % mod;
}
int Solution::getSum(int A, int B, int C, vector<int> &D, vector<int> &E, vector<int> &F) {
    sort(D.begin(),D.end());
    sort(E.begin(),E.end());
    sort(F.begin(),F.end());
    
    ll ans = 0;
    vector<ll> pref1(A),pref2(C);
    pref1[0] = D[0];
    for(int i=1;i<A;i++)
        pref1[i] = pref1[i-1] + D[i];
    pref2[0] = F[0];
    for(int i=1;i<C;i++)
        pref2[i] = pref2[i-1] + F[i];
    
    for(int i=0;i<B;i++){
        int el = E[i];
        int x1 = upper_bound(D.begin(),D.end(),el) - D.begin();
        int x2 = upper_bound(F.begin(),F.end(),el) - F.begin();
        ll temp = (1ll * x1 * x2);
        ll square = 1ll * el * el;
        ans = add(ans,mul(temp,square));
        ll sum1,sum2;
        sum1 = sum2 = 0;
        if(x1 > 0)
            sum1 = pref1[x1 - 1];
        if(x2 > 0)
            sum2 = pref2[x2 - 1];
        
        temp = add(mul(x1,sum2),mul(x2,sum1));
        ans = add(ans,mul(el,temp));
        
        temp = mul(sum1,sum2);
        ans = add(ans,temp);
    }
    
    return ans;
    
}
