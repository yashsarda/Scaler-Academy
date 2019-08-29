int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    if(n == 1)
        return A[0];
    
    int max_area = INT_MIN;
    stack<int> s;
    s.push(0);
    int i;
    for(i=1;i<n;i++){
        int current = A[i];
        // If the current element is not less than top of the stack, hence it's not a hindrance for us
        // So just push it into stack
        if(current >= A[s.top()])
            s.push(i);
        else{
            // If it is less then it hindrance to the top bar, so just calculate the area for top bar
            // For every bar, the element which is strictly smaller than that bar is present just below tht element
            // in the stack. This contributes to the leftmost bar, and the current bar the rightmost bar
            // If there is no leftmost bar then the top element is the smallest element
            while(!s.empty() && A[s.top()] > current){
                int t = A[s.top()];
                s.pop();
                int temp = 0;
                if(s.empty()){
                    temp = t * i;
                }
                else{
                    temp = t * (i - s.top() - 1);
                }
                max_area = max(max_area,temp);
            }
            s.push(i);
        }
    }
    
    while(!s.empty()){
        int t = A[s.top()];
        s.pop();
        int temp = 0;
        if(s.empty()){
            temp = t * n;
        }
         else{
             temp = t * (n - s.top() - 1);
        }
        max_area = max(max_area,temp);
    }
    
    return max_area;
    
}
