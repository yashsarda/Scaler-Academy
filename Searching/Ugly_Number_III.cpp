class Solution {
public:
    typedef long long ll;
    int nthUglyNumber(int n, int a, int b, int c) {
        long long answer = 0;
        long long lb = 0;
        long long ub = (long long)1e18;
        
        ll l1 = (a * 1ll * b) / (__gcd(a,b));
        ll l2 = (b * 1ll * c) / (__gcd(b, c));
        ll l3 = (a * 1ll * c) / (__gcd(a, c));
        ll l4 = (a * 1ll * b) / (__gcd(a, b));
        l4 = (l4 * 1ll * c) / (__gcd(l4, 1ll*c));
        
        while(lb <= ub) {
            long long mid = lb + (ub - lb) / 2;
            long long div = mid / a + mid / b + mid / c - mid / l1 - mid / l2 - mid / l3 + mid / l4;
            if(div == n) {
                if(mid % a == 0 || mid % b == 0 || mid % c == 0) {
                    answer = mid;
                    break;
                }
                ub = mid - 1;
            }
            else {
                if(div > n) {
                    ub = mid - 1;
                }
                else {
                    lb = mid + 1;
                }
            }
        }
        return answer;
    }
};