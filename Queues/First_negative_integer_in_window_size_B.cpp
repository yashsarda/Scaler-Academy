typedef long long ll;
vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> ans;
    if(B == 1){
        for(int i=0;i<n;i++){
            if(A[i] < 0)
                ans.push_back(A[i]);
            else
                ans.push_back(0);
        }
        return ans;
    }
    
    queue<ll> dq;
    for(int i=0;i<B;i++){
        if(A[i] < 0)
            dq.push(i);
    }
    if(dq.empty())
        ans.push_back(0);
    else
        ans.push_back(A[dq.front()]);
    
    for(int i=B;i<n;i++){
        if(!dq.empty()){
            int x = dq.front();
            if(x + B - 1 < i)
                dq.pop();
            if(A[i] < 0)
                dq.push(i);
            if(dq.empty())
                ans.push_back(0);
            else
                ans.push_back(A[dq.front()]);
        }
        else{
            if(A[i] < 0)
                dq.push(i);
            if(dq.empty())
                ans.push_back(0);
            else
                ans.push_back(A[dq.front()]);
        }
    }
    return ans;
}
