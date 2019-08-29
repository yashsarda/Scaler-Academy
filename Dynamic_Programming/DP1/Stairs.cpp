int Solution::climbStairs(int A) {
    if(A <= 1)
        return 1;
    if(A == 2)
        return 2;
    vector<int> ans(A + 1);
    ans[1] = 1;
    ans[2] = 2;
    
    for(int i=3;i<=A;i++)
        ans[i] = ans[i-1] + ans[i-2];
    
    return ans[A];
}
