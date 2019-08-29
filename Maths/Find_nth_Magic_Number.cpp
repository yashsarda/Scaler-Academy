int Solution::solve(int A) {

    int ans = 1;
    int mul_f = 1;
    while(A){
        if(A & 1){
            ans = ans * mul_f;
        }
        A >>= 1;
        mul_f = mul_f * 5;
    }

    return ans;
}
