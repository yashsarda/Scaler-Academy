int Solution::solve(vector<int> &A) {
    
    int ans = 0;
    int size = A.size();
    priority_queue<int,vector<int>,greater<int> > pq;
    if(size == 1)
        return 0;
    if(size == 2)
        return A[0] + A[1];
    
    for(int i=0;i<size;i++)
        pq.push(A[i]);
    
    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        ans += min1 + min2;
        pq.push(min1 + min2);
    }
    return ans;
}
