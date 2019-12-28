const int mod = 1e9 + 7;
typedef long long ll;
int Solution::solve(int A, int B, int C) {
    if(B > C) swap(B,C);
    ll lcm = (B * 1ll * C) / (__gcd(B, C));
    
    ll lower = 0;
    ll upper = 1e15;
    
    while(lower <= upper) {
        ll mid = lower + (upper - lower) / 2;
        ll number = mid / B + mid / C - mid / lcm;
        if(number == A) {
            ll first = mid / B;
            ll second = mid / C;
            if(B * first > C * second)
                return (B * first) % mod;
            return (C * second) % mod;
        }
        if(number > A) 
            upper = mid - 1;
        else
            lower = mid + 1;
    }
    
}
