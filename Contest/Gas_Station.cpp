int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int sumA = accumulate(A.begin(), A.end(), 0);
    int sumB = accumulate(B.begin(), B.end(), 0);
    if(sumB > sumA)
        return -1;
    
    int sum = 0;
    int i,j;
    for(i=0,j=0;i<n && j<2*n;) {
        sum += A[j % n] - B[j % n];
        if(sum < 0) {
            i = j + 1;
            j = i;
            sum = 0;
            continue;
        }
        j++;
    }
    return i;
}
