int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    vector<int> diff(n);
    if(n == 1){
        if(A[0] >= B[0])
            return 0;
        return -1;
    }
    for(int i=0;i<n;i++)
        diff[i] = A[i] - B[i];
    
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += diff[i];
    
    if(sum < 0)
        return -1;
    
    int ans = 0;
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=i;j < i + n;j++){
            temp += diff[j % n];
            if(temp < 0)
                break;
        }
        if(temp >= 0){
            ans = i;
            break;
        }
    }
    return ans;
}
