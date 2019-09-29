// Rishik has a very special Ukulele with A frets. He can use atmost 4 fingers to play a chord. Find total number of different chords Rishik can play mod 1000000007. 
// Two chords are different if one of the fret that is pressed in one of the chord is not pressed in other chord. Note: 1 finger can press atmost 1 fret at a time.
const int mod = 1e9 + 7;
typedef long long ll;
inline int add(int a,int b) { a += b; if(a >= mod) a -= mod; return a; }
inline int sub(int a,int b) { a -= b; if(a < 0) a += mod; return a; }
inline ll mul(int a, int b) { return ((ll) a * b) % mod; }
inline ll power(int base, int exp)
{
    ll ans = 1;
    while(exp) {
        if(exp & 1)
            ans = mul(ans, base);
        exp >>= 1;
        base = mul(base, base);
    }
    return ans;
}
int arr[] = { 0, 1, 2, 6, 24 };
ll ncr(ll N, int r)
{
    ll ans = 1;
    ll t = N;
    for(int i=1;i<=r;i++) {
        ans = mul(ans, t);
        t--;
    }
    ans = mul(ans, power(arr[r], mod - 2));
  
    return ans;
}
int Solution::solve(int A) {
    if(A == 1)
        return 2;
    if(A == 2)
        return 4;
    if(A == 3)
        return 8;
    
    // A >= 4
    ll ans = 1;
    for(int i=1;i<=4;i++) {
        ans = add(ans, ncr(A, i));
    }
    return ans;
}
