// Think up of a constant space solution
int Solution::solve(string A) {
    int n = A.size();
    if(n == 1){
        if(A[0] == '1')
            return 1;
        return 0;
    }
    vector<int> left(n,0);
    vector<int> right(n,0);
    int count_ones = 0;
    for(int i=0;i<n;i++)
        count_ones += (A[i] == '1');
    int count_left = 0;
    left[0] = (A[0] == '1') ? 1 : 0;
    for(int i=1;i<n;i++){
        if(A[i] == '0')
            left[i] = 0;
        else
            left[i] = left[i-1] + 1;
    }
    
    right[n-1] = (A[n - 1] == '1') ? 1 : 0;
    for(int i=n-2;i>=0;i--){
        if(A[i] == '0')
            right[i] = 0;
        else
            right[i] = right[i+1] + 1;
    }
    int ans = INT_MIN;
    if(A.size() - count_ones == 0)
        return A.size();
    for(int i=0;i<n;i++){
        int temp  = 0;
        if(A[i] == '0'){
            if(i - 1 >= 0 && i + 1 < n)
                temp = left[i-1] + right[i + 1];
            else if(i - 1 >= 0)
                temp = left[i - 1];
            else if(i + 1 < n)
                temp = right[i + 1];
            temp += (count_ones > temp) ? 1 : 0;
            ans = max(ans,temp);
        }
    }
    return ans;
}
