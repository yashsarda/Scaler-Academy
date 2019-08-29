int Solution::trailingZeroes(int A) {
    int ans = 0;
    int divide_by = 5;

    while(A / divide_by != 0){
        ans += A / divide_by;
        divide_by *= 5;
    }
    return ans;
}
