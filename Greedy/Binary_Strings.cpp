int Solution::solve(string A, int B) {
    int size = A.size();
    int ans = 0;
    for(int i=0;i<=size - B;i++){
        // if we have a 1 it does not make sense to flip it
        if(A[i] == '1')
            continue;
        // If we have a zero then we need to flip k consecutive number
        for(int j = i;j < i + B;j++)
            A[j] = (A[j] == '1') ? '0' : '1';
        ans++;
    }
    for(int i=0;i<size;i++){
        if(A[i] == '0')
            return -1;
    }
    return ans;
}
