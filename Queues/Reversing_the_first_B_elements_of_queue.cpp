vector<int> Solution::solve(vector<int> &A, int B) {
    queue<int> q;
    int n = A.size();
    vector<int> ans;
    if(n == 1)
        return A;
    for(int i=0;i<n;i++)
        q.push(A[i]);
    
    stack<int> s;
    int index = 1;
    while(index <= B){
        int no = q.front();
        q.pop();
        s.push(no);
        index++;
    }
    while(!s.empty()){
        int t = s.top();
        s.pop();
        ans.push_back(t);
    }
    
    while(!q.empty()){
        int no = q.front();
        q.pop();
        ans.push_back(no);
    }
    return ans;
}
