void permutation(vector<int>& A,vector<vector<int> >& ans,int index)
{
    if(index == A.size() - 1){
        ans.push_back(A);
        return;
    }
    
    unordered_map<int,int> m;
    for(int i=index;i<A.size();i++)
        m[A[i]] = 1;
    
    for(int i=index;i<A.size();i++){
        if(m[A[i]] == 1){
            m[A[i]] = 0;
            swap(A[index],A[i]);
            permutation(A,ans,index + 1);
            swap(A[index],A[i]);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > ans;
    permutation(A,ans,0);
    return ans;
}
