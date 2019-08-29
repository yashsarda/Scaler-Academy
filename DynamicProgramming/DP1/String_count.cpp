const int mod = 1000000007;
int Solution::solve(int A) {
    if(A == 1)
        return 2;
    if(A == 2)
        return 3;
    // number of binary string that end with 0
    int y = 2;
    // number of binary string that end with 1
    int z = 1;
    
    for(int i=3;i<=A;i++){
        int temp1 = (y % mod + z % mod) % mod;
        int temp2 = (y) % mod;
        y = temp1;
        z = temp2;
    }
    return (y % mod + z % mod) % mod;
}
