vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> diff_array(A + 1);
    int row = B.size();
    for(int i=0;i<row;i++){
        int start = B[i][0] - 1;
        int en = B[i][1];
        int value = B[i][2];
        
        diff_array[start] += value;
        diff_array[en] -= value;
    }
    
    for(int i=1;i<A;i++)
        diff_array[i] += diff_array[i-1];
    diff_array.erase(diff_array.begin() + A);
    return diff_array;
}
