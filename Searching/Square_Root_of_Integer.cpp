int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lb = 0;
    int ub = A;
    
    while(lb <= ub){
        int mid = lb + ((ub - lb) >> 1);
       // cout << mid << ' ';
        if(1ll * mid * mid == A)
            return mid;
        else {
            if((1ll * mid * mid) > A)
                ub = mid - 1;
            else if((1ll * (mid + 1) * (mid + 1)) > A)
                return mid;
            else
                lb = mid + 1;
        }
     //   cout << lb << ' ' << ub << '\n';
    }
}
