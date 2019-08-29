int Solution::solve(vector<vector<int> > &A, int B) {

    int rows = A.size();
    int column = A[0].size();
    int i = 0;
    int j = column - 1;
    while(i < rows && j >= 0){
        if(A[i][j] > B)
            j--;
        else if(A[i][j] < B)
            i++;
        else if(A[i][j] ==  B)
         return (i + 1) * 1009 + j + 1;
    }
    return -1;
}
