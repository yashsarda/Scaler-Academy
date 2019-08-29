int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    
    vector<int> current_window(m,0);
    
    // Make the numbers from 0 to m - 1
    for(int i=0;i<n;i++)
        A[i]--;
    
    int total = 0;
    
    
    // How many do I require
    for(int i=0;i<m;i++)
        total += B[i];
    
    set<int> s;
    
    // Only insert those in the set which have count greater than 0
    for(int i=0;i<m;i++){
        if(B[i] > 0)
            s.insert(i);
    }
    
    int ans = INT_MAX;
    int l = 0;
    // Use two pointer
    for(int i=0;i<n;i++){
        int x = A[i];
        current_window[x]++;
        if(current_window[x] == B[x]) 
            s.erase(x);
        while(s.empty()){
            ans = min(ans, i - l + 1 - total);
            int y = A[l];
            --current_window[y];
            if(current_window[y] == B[y] - 1)
                s.insert(y);
            l++;
        }
    }
    if(ans == INT_MAX)
        return -1;
    return ans;
}
