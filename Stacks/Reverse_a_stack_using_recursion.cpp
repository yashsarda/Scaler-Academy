void reverseStack(vector<int>& A,vector<int>& ans)
{
    // Base case
    if(A.size() == 1){
        ans.push_back(A[0]);
        return;
    }
    int top = A.back();
    A.pop_back();
    
    // Hypothesis
    reverseStack(A,ans);
    
    
    // Induction
    vector<int> temp;
    while(!ans.empty()){
        int x = ans.back();
        ans.pop_back();
        temp.push_back(x);
    }
    
    ans.push_back(top);
    
    while(!temp.empty()){
        int x = temp.back();
        temp.pop_back();
        ans.push_back(x);
    }
    
}
vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans;    
    if(A.size() == 1){
        return A;
    }

    reverseStack(A,ans);
    return ans;
}
