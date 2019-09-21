vector<int> Solution::solve(vector<int> &A) {
    int len = A.size();
    
    // Max-heap to store the lower half of the input array
    // Min-heap to store the larger half of the input array
    vector<int> C(len);
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    
    for(int i=0;i<len;i++) {
        // Push it into the max-heap
        max_heap.push(A[i]);
        int top_of_max = max_heap.top();
        max_heap.pop();
        min_heap.push(top_of_max);
        if(max_heap.size() == min_heap.size()) {
            C[i] = max_heap.top();
        }
        else {
            int top_of_min = min_heap.top();
            min_heap.pop();
            max_heap.push(top_of_min);
            C[i] = max_heap.top();
        }
    }
    return C;
}
