int Solution::solve(int A) {
    int l = 1;
    int r = A;
    
    while(l <= r){
        int mid = l + (r - l) / 2;
        long long cal = (1ll * mid * (mid + 1)) >> 1;
        if(cal > A)
            r = mid - 1;
        else if(cal == A)
            return mid;
        else
        {
            long long cal2 = (1ll * (mid + 1) * (mid + 2)) >> 1;
            if(cal2 > A)
                return mid;
            l = mid + 1;
        }
    }
}
