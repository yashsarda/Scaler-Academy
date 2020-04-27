/*
There are N poles and height of the poles are given by an integer array A.
You have to connect two poles such that all the poles between them have height smaller than the minimum height of the two poles.

Find the total number of pairs of such poles.

Note: The height of the given poles are distinct.   
*/

int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    stack<int> s;
    int answer = 0;
    s.push(A[0]);
    for(int i = 1; i < n; i++) {
        int current = A[i];
        
        while(!s.empty() && s.top() < current) {
            s.pop();
            answer++;
        }
        
        if(!s.empty()) {
            answer++;
        }
        s.push(current);
    }
    
    return answer;
}