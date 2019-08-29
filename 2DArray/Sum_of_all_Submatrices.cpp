int Solution::solve(vector<vector<int> > &A) {

    int rows = A.size();
    int column = A[0].size();
    int sum = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<column;j++){
            int left = (i+1) * (j + 1);
            int right = (rows - i) * (rows - j);
            int mul = left * right * A[i][j];
            sum = sum + mul;
        }
    }
    return sum;
}
