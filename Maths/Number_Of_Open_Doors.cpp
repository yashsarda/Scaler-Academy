// Idea: The answer is not going to be a number which divides both A and B
// since we require the number B and answer to be co-prime
// So the answer will surely be less than the gcd of A and B (if it is > 1) because the gcd divides both of the number
// We keep on dividing until we don't get gcd(A,B) = 1
int Solution::solve(int A) {

    int lb = 1;
    int ub = A;
    int bans = 0;
    while(lb <= ub){
        int mid = lb + (ub - lb) / 2;
        if(1ll* mid * mid <= A){
            bans = mid;
            lb = mid + 1;
        }
        else
            ub = mid - 1;
    }
    return bans;
}
