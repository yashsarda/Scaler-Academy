vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > v(A+1,vector<int>(A+1));
    int total_iter = A / 2;
    int top_row = 1, top_column = 1;
    int right_column = A,right_row = 2;
    int bottom_row = A, bottom_column = A-1;
    int left_column = 1,left_row = A-1;
    int e = 1;
    for(int i=1;i<=total_iter;i++){
        for(int j=top_column;j<=right_column;j++){
            v[top_row][j] = e++;
        }
        for(int k=right_row;k<=bottom_row;k++){
            v[k][right_column] = e++;
        }
        for(int m=bottom_column;m>=left_column;m--){
            v[bottom_row][m] = e++;
        }
        for(int n=left_row;n>top_row;n--){
            v[n][left_column] = e++;
        }
        top_row++;
        top_column++;
        right_column--;
        right_row++;
        bottom_row--;
        bottom_column--;
        left_column++;
        left_row--;
    }
    if(A & 1){
        v[top_row][top_column] = e++;
    }
}
