int lowerBound(const vector<int>& A, int B)
{
    int lb = 0;
    int ub = A.size() - 1;
    
    while(lb <= ub) {
        int mid = lb + (ub - lb) / 2;
        if(A[mid] > B) {
            ub = mid - 1;
        }
        else if(A[mid] < B) {
            lb = mid + 1;
        }
        else {
            if(mid == 0)
                return 0;
            if(A[mid - 1] == B) {
                ub = mid - 1;
            }
            else {
                return mid;
            }
        }
    }
    return -1;
}
int upperBound(const vector<int>& A, int B)
{
    int lb = 0;
    int ub = A.size() - 1;
    
    while(lb <= ub) {
        int mid = lb + (ub - lb) / 2;
        
        if(A[mid] > B) {
            ub = mid - 1;
        }
        else if(A[mid] < B) {
            lb = mid + 1;
        }
        else {
            if(mid == A.size() - 1)
                return mid;
            if(A[mid + 1] == B)
                lb = mid + 1;
            else
                return mid;
        }
    }
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    
    // One solution using upper bound and lower bound function
    // auto l = lower_bound(A.begin(), A.end(), B);
    // if(l == A.end())
    //     return {-1,-1};
    
    // int index = l - A.begin();
    // if(A[index] != B)
    //     return {-1,-1};
    
    // int u = upper_bound(A.begin(), A.end(), B) - A.begin();
    // return {index, u - 1};
    
    int lower_index = lowerBound(A, B);
    if(lower_index == -1)
        return {-1,-1};
    
    int upper_index = upperBound(A, B);
    return {lower_index, upper_index};
    
}
