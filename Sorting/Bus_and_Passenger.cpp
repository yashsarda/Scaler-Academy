const int N = 100005;
vector<int> Solution::solve(vector<int> &A, string B) {
    
    int n = A.size();
    unordered_map<int,int> mapping;
    // No issues since all array elements are distinct
    for(int i=0;i<n;i++)
        mapping[A[i]] = i;
        
    // Minimum priority queue for all elements with count = 2
    priority_queue<int,vector<int>,greater<int> > pq1;
    // Maximum priority queue for all the elements with count = 1;
    priority_queue<int> pq2;
    for(int i=0;i<n;i++)
        pq1.push(A[i]);
    
    int s = B.size();
    vector<int> temp(s);
    for(int i=0;i<s;i++){
        if(B[i] == '0'){
            int t = pq1.top();
            pq1.pop();
            temp[i] = t;
            pq2.push(t);
        }
        else{
            int t = pq2.top();
            pq2.pop();
            temp[i] = t;
        }
    }
    for(int i=0;i<s;i++){
        int value = temp[i];
        int index = mapping[value];
        temp[i] = index + 1;
    }
    return temp;
}
