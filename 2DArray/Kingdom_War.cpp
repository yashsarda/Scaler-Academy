int Solution::solve(vector<vector<int> > &A) {
    int row = A.size();
    int column = A[0].size();

    int pref[row][column];
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++)
            pref[i][j] = 0;
    }
    for(int i=row-1;i>=0;i--)
        pref[i][column-1] = A[i][column-1];
    for(int i=row-1;i>=0;i--){
        for(int j=column-2;j>=0;j--){
            pref[i][j] = pref[i][j+1] + A[i][j];
        }
    }
    for(int j=column-1;j>=0;j--){
        for(int i=row-2;i>=0;i--){
            pref[i][j] = pref[i+1][j] + pref[i][j];
        }
    }


    int ans = INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            ans = max(ans,pref[i][j]);
        }
    }
    return ans;
}
