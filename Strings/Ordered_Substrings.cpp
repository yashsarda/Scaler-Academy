bool cmp(string A,string B)
{
    if(A.size() == B.size())
        return A < B;
    return A.size() < B.size();
}
vector<string> Solution::solve(vector<string> &A) {
    // Order by size
    sort(A.begin(),A.end(),cmp);
    vector<string> ans;
    if(A.size() == 1){
        ans.push_back(A[0]);
        return ans;
    }
    // Just look if the previous string occurs as a substring in current string
    for(int i=1;i<A.size();i++){
        int found = A[i].find(A[i-1]);
        if(found == string::npos){
            ans.clear();
            ans.push_back("NO");
            break;
        }
        ans.push_back(A[i-1]);
        if(i == A.size() - 1)
            ans.push_back(A[i]);
    }
    return ans;
    
}
