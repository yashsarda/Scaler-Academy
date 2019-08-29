void sort(vector<int>& A,vector<int>& ans)
{
    // Base case
    if(A.size() == 1){
        ans.push_back(A[0]);
        return;
    }
    
    int x = A.back();
    A.pop_back();
    
    // Hypothesis
    sort(A,ans);
    
    // Induction
    vector<int> temp;
    while(x <= ans.back()){
        int y = ans.back();
        ans.pop_back();
        temp.push_back(y);
    }
    ans.push_back(x);
    while(!temp.empty()){
        int y = temp.back();
        temp.pop_back();
        ans.push_back(y);
    }
}
vector<int> Solution::solve(vector<int> &A) {
    int a = A.size();
    vector<int> ans;
    if(a == 1){
        ans.push_back(A[0]);
        return ans;
    }
    sort(A,ans);
    return ans;
}
