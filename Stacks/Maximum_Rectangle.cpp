int find_largest_rectangle(vector<int>& A)
{
    int n = A.size();
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
int Solution::solve(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    if(row == 1 && col == 1)
        return A[0][0];
    vector<int> arr(col);
    arr[0] = A[0][0];
    for(int i=1;i<col;i++){
        arr[i] = A[0][i];
    }
    int max_area = find_largest_rectangle(arr);
    for(int i=1;i<row;i++){
        for(int j=0;j<col;j++){
            if(A[i][j] == 1)
                A[i][j] += A[i-1][j];
            }
        for(int k=0;k<col;k++)
            arr[k] = A[i][k];
        int temp = find_largest_rectangle(arr);
        max_area = max(max_area,temp);
    }
    return max_area;
}
