int Solution::solve(int A) {
    int ans = 1;
    while(ans <= A){
        ans = ans * 2;
    }
    ans = ans / 2;
    return ans;
}
