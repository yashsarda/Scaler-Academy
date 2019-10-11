int Solution::solve(vector<int> &A, int B, int C, int D) {
    int len = A.size();
    if(len == 0)
        return 0;
        
    if(len == 1) {
        return (A[0] * B + A[0] * C + A[0] * D);
    }
    
    vector<int> max_left(len, INT_MIN), max_right(len, INT_MIN);
    vector<int> min_left(len, INT_MAX), min_right(len, INT_MAX);
    
    max_left[0] = min_left[0] = A[0];
    max_right[len - 1] = min_right[len - 1] = A[len - 1];
    
    for(int i=1;i<len;i++) {
        max_left[i] = max(max_left[i - 1], A[i]);
        min_left[i] = min(min_left[i - 1], A[i]);
    }
    
    for(int i=len-2;i>=0;i--) {
        max_right[i] = max(max_right[i + 1], A[i]);
        min_right[i] = min(min_right[i + 1], A[i]);
    }
    
    int answer = INT_MIN;
    for(int i=0;i<len;i++) {
        int temp = A[i] * C;
        if(B >= 0)
            temp += max_left[i] * B;
        else
            temp += min_left[i] * B;
        
        if(D >= 0)
            temp += max_right[i] * D;
        else
            temp += min_right[i] * D;
        answer = max(answer, temp);
    }
    
    return answer;
}
