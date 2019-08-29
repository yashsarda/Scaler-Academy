int Solution::search(const vector<int> &A, int B) {
    
    int n = A.size();
    int lb = 0;
    int ub = n - 1;
    int pivot = -1;
    int temp = A[n-1];
    // Pivot  = element whose left side as well as right side is smaller
    // First find the pivot element
    while(lb <= ub){
        int mid = lb + ((ub - lb) >> 1);
     //   cout << lb << ' ' << ub << '\n';
        if(A[mid] < temp)
            ub = mid - 1;
        else if(A[mid] >= temp){
            if(A[mid + 1] < A[mid]){
                  pivot = mid;
                }
            lb = mid + 1;
        }
    }
   // In this case the array might be sorted in increasing or decreasing order
   // To determine if it is in increasing or decreasing order check the last two elements
    if(pivot == -1){
        // Increasing order pivot = last element
        // Decreasing order pivot = first element
        if(A[n - 1] >= A[n - 2])
            pivot = n - 1;
        else
            pivot = 0;
    }
    // Apply binary search on an increasing array
    if(pivot == 0){
        lb = 0;
        ub = n - 1;
        while(lb <= ub){
                long long mid = lb + ((ub - lb) >> 1);
                if(A[mid] == B)
                    return mid;
                else if(A[mid] > B)
                    lb = mid + 1;
                else
                    ub = mid - 1;
            }
            return -1;
    }
    // Apply binary search on decreasing array
    else if(pivot == n - 1){
        lb = 0;
        ub = n - 1;
        while(lb <= ub){
                long long mid = lb + ((ub - lb) >> 1);
                if(A[mid] == B)
                    return mid;
                else if(A[mid] > B)
                    ub = mid - 1;
                else
                    lb = mid + 1;
            }
            return -1;
    }
    else{
        // look which subarray might contain the element
        // If our target is greater than first element of the array then it is a part of [first....pivot]
        // else it is part of [pivot+1....last]
        int search_in;
        if(B >= A[0])
            search_in = 0;
        else
            search_in = 1;
            
        if(!search_in){
            lb = 0;
            ub = pivot;
            while(lb <= ub){
                long long mid = lb + ((ub - lb) >> 1);
                if(A[mid] == B)
                    return mid;
                else if(A[mid] > B)
                    ub = mid - 1;
                else
                    lb = mid + 1;
            }
            return -1;
        }
        else{
            lb = pivot + 1;
            ub = n - 1;
            while(lb <= ub){
                long long mid = lb + ((ub - lb) >> 1);
                if(A[mid] == B)
                    return mid;
                else if(A[mid] > B)
                    ub = mid - 1;
                else
                    lb = mid + 1;
            }
            return -1;
        }
    }
    
    
}
