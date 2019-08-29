int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    int l = 0;
    int h = n - 1;
    
    while(l <= h){
        int mid = l + (h - l) / 2;
        if(mid == 0){
            if(A[mid] >= A[mid + 1])
                return A[mid];
        }
        if(mid == n-1){
            if(A[mid] >= A[mid-1])
                return A[mid];
        }
        if(A[mid] >= A[mid - 1] && A[mid] >= A[mid+1])
            return A[mid];
        if(A[mid] >= A[mid - 1])
            l = mid + 1;
        else
            h = mid - 1;
    }
}
