int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int row_to_be_searched = -1;
    int row = A.size();
    int col = A[0].size();
    int start = A[0][0],end = A[0][col-1];
    for(int i=0;i<row;i++){
        if(B >= start && B <= end){
            row_to_be_searched = i;
            break;
        }
        else{
            if(i == row - 1)
                break;
            start = A[i][col-1] + 1;
            end = A[i+1][col-1];
        }
    }
    if(row_to_be_searched == -1)
        return 0;
    
    int lb = 0;
    int ub = col - 1;
    
    while(lb <= ub){
        int mid = lb + (ub - lb) / 2;
        if(A[row_to_be_searched][mid] == B)
            return 1;
        if(A[row_to_be_searched][mid] > B)
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return 0;
}
