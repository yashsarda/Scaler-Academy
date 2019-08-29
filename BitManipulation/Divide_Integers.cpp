//lots and lots of corner cases
// submitted a ton of wrong solutions but anyways its 1:00 AM
int Solution::divide(int A, int B) {
    long long d = A;
    if(B == 1){
        if(d == INT_MIN)
            return INT_MIN;
        if(d == INT_MAX)
            return INT_MAX;
    }
    if(B == -1){
        if(d == INT_MIN)
            return INT_MAX;
        if(d == INT_MAX)
            return INT_MAX;
    }
    int cnt = 0;
    if(A == 0)
        return 0;
    if(B == 1 || (B == -1 && A > 0))
        return A;
    if(B == -1 && A < 0)
        return -1*A;
    long long X = abs((long long)A);
    long long Y = abs(B);
        while(X > Y){
            cnt++;
            X-= Y;
        }
    if(B < 0 && A > 0 || A <0 && B > 0)
        return -1*cnt;
    return cnt;
    
    
}
