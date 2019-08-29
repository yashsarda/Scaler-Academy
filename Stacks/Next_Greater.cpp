vector<int> Solution::nextGreater(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n);
    if(n == 1){
        ans[0] = -1;
        return ans;
    }
    stack<int> s;
    for(int i=0;i<n;i++){
        int element = A[i];
        if(s.empty())
            s.push(i);
        else{
            int el = A[s.top()];
            if(element < el)
                s.push(i);
            else{
                while(!s.empty() && el < element){
                    int index = s.top();
                    ans[index] = A[i];
                    s.pop();
                    if(!s.empty())
                        el = A[s.top()];
                }
                s.push(i);
            }
        }
    }
    while(!s.empty()){
        int index = s.top();
        s.pop();
        ans[index] = -1;
    }
    return ans;
}
