vector<int> Solution::solve(int A, int B, vector<int> &C) {
    int size = C.size();
    vector<int> ans;
    
    priority_queue<int> max_pq;
    priority_queue<int,vector<int>,greater<int>> min_pq;
    for(int i=0;i<size;i++){
        max_pq.push(C[i]);
        min_pq.push(C[i]);
    }
    int max = 0;
    for(int i=0;i<A;i++){
        int x = max_pq.top();
        max += x;
        max_pq.pop();
        if(x - 1)
            max_pq.push(x - 1);
    }
    int min = 0;
    for(int i=0;i<A;i++){
        int x = min_pq.top();
        min += x;
        min_pq.pop();
        if(x - 1)
            min_pq.push(x - 1);
    }
    ans.push_back(max);
    ans.push_back(min);
    return ans;
}
