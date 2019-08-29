struct comp
{
    bool operator()(pair<int,int>& pa,pair<int,int>& pb)
    {
        return pa.first > pb.first;
    }
};
int Solution::solve(vector<int> &A, int B) {
    int size = A.size();
    if(size == 1){
        return A[0] * (B + 1);
    }
    if(B == 0)
        return *max_element(A.begin(),A.end());
    // first = value , second = index
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp > pq;
    for(int i=0;i<size;i++)
        pq.push({A[i] + A[i],i});
    
    int ans = *max_element(A.begin(),A.end());
    for(int i=0;i<B;i++){
        pair<int,int> t = pq.top();
        int value = t.first;
        pq.pop();
        ans = max(ans,value);
        pq.push({value + A[t.second],t.second});
    }
    
    return ans;
}
