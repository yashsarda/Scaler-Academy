int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> B,C;
    // First find the smallest element which will be 1. All the element which are greater can be kept in C
    int i = 0;
    while(i < n && A[i] != 1){
        C.push_back(A[i]);
        i++;
    }
    B.push_back(A[i]);
    i++;
    // Find if the array C contains elements 2,3,4.....
    int next = 2;
    while(!C.empty() && C.back() == next){
        B.push_back(next);
        next++;
        C.pop_back();
    }
    
    // Then look at the last element of B, the next element required will be the last element + 1 always
    // If the element is not next then we push it into C
    while(i < n){
        int next = B.back();
        if(A[i] == next + 1){
            B.push_back(next + 1);
        }
        else
            C.push_back(A[i]);
        i++;
    }
    // Empty C
    while(!C.empty()){
        B.push_back(C.back());
        C.pop_back();
    }
    // Just check if B is sorted
    for(int i=0;i<B.size()-1;i++){
        if(B[i] > B[i + 1])
            return 0;
    }
    return 1;
    
}
