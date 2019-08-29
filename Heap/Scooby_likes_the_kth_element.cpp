vector<int> Solution::solve(int A, vector<int> &B) {
    int size = B.size();
    vector<int> ans;
    if(A == 1 && size == 1)
        return B;
    if(A > 1 && size == 1){
        ans.push_back(-1);
        return ans;
    }
    if(A > size){
         int i=0;
        while(i < size){
            ans.push_back(-1);
            i++;
        }
        return ans;
    }
    // For all the subarrays of size less than K, push -1
    for(int i=0;i<A-1;i++)
        ans.push_back(-1);
    // Maintain a min priority queue whose root element will always be the answer
    priority_queue<int,vector<int>,greater<int> > pq;
    // Push the first K element in the min priority queue
    for(int i=0;i<A;i++)
        pq.push(B[i]);
    // The Kth largest element is equaivalent to the smallest element of subarray [1:K]
    ans.push_back(pq.top());
    for(int i=A;i<size;i++){
        // Now when we consider a subarray of greater size then we have 2 cases
        // Take an example where K = 4 and subarray size = 57
        // If the current element is greater than top, it means that top is smallest element still so we need to pop and 
        // push this current element into the heap to find the n - k + 1 smallest element
        if(B[i] > pq.top()){
            pq.pop();
            pq.push(B[i]);
        }
        // If the current element is less than top, then it is the smallest element for this subarray then, top will 
        // signify the n - k + 1 smallest element
        ans.push_back(pq.top());
    }
    return ans;
        
}