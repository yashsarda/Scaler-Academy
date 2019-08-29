int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    sort(A.begin(),A.end());
    int total = accumulate(A.begin(),A.end(),0);
    int sum = 0;
    if(B <= n / 2){
        for(int i=0;i<B;i++)
            sum += A[i];
        return (total - 2 * sum);
    }
    else{
        for(int i=n-1;i>=n-B;i--)
            sum += A[i];
        return abs(total - 2 * sum);
    }
}
