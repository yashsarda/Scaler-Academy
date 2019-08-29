int Solution::jump(vector<int> &A) {
    int size = A.size();
    if(size == 1)
        return 0;
    
    // dp solution
   /* vector<int> dp(size+1,INT_MAX);
    dp[0] = 0;
    
    for(int i=1;i<size;i++){
        for(int j=0;j<=i-1;j++){
            int k = i - j;
            if(A[j] >= k && dp[j] != INT_MAX){
                dp[i] = min(dp[i],dp[j] + 1);
                break;
            }
        }
    }
    if(dp[size - 1] == INT_MAX)
        return -1;
    return dp[size - 1];*/
    
    // Second one:- 
    // 1.We need to take the first step
    // 2. The first step will cover some part of the array. In this part if we have a number which covers more distance 
    // than this then it might be the next possible step.
    // 3. Now out of these choices which choice should we take, since we have to minimize the number of jumps we take the
    // number which covers the largest part of the array from its position

    if(A[0] == 0)
        return -1;
    
    int min_jumps = 1;
    // First numbers coveres A[0] steps
    int covered_part = A[0];
    int decrease_size_of_covered_part = A[0];
    
    for(int i=1;i<size;i++){
        if(i == size - 1)
            return min_jumps;
        // If the current number number covers more number of steps than current covered_part the
        // next jump would be to this part
        if(i + A[i] > covered_part)
            covered_part = i + A[i];
        // Decrease the number of elements the current covered_part has covered
        decrease_size_of_covered_part--;
        // If we have covered all the element then it's time to jump and we jump at the element which
        // has the maximum reach in already covered part
        if(decrease_size_of_covered_part == 0){
            ++min_jumps;
            decrease_size_of_covered_part = covered_part - i;
            if(decrease_size_of_covered_part == 0)
                return -1;
        }
    }
}
