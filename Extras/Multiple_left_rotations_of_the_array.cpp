vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    int asize = A.size();
    int bsize = B.size();
    vector<vector<int> > ans;
    if(asize == 0 || bsize == 0)
        return ans;
    ans.resize(bsize);
    for(int i=0;i<bsize;i++)
        ans[i].resize(asize);
    vector<int> new_array(2 * asize);
    for(int i=0;i<asize;i++)
        new_array[i] = A[i];

    for(int i=asize;i<2*asize;i++)
        new_array[i] = A[i - asize];

    for(int i=0;i<bsize;i++){
        vector<int> temp;
        int element = B[i] % asize;
        for(int j=element;j<element + asize;j++)
            temp.push_back(new_array[j]);
        ans[i] = temp;
    }

    return ans;
}
