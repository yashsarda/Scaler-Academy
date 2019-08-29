//use the difference array concept
vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> ans(A + 2);
    int row = B.size();
    int col = B[0].size();

    for(int i=0;i<row;i++){
        int first = B[i][0];
        int second = B[i][1];
        int value = B[i][2];

        ans[first] = ans[first] + value;
        ans[second+1] = ans[second+1] - value;
    }
    for(int i=1;i<A+2;i++)
        ans[i] = ans[i] + ans[i-1];
    vector<int> actual(A);
    for(int i=1;i<A+1;i++)
        actual[i-1] = ans[i];
    return actual;


}
