string Solution::solve(string A) {
    int n = A.size();
    queue<int> q;
    vector<int> freq(26,0);
    string ans = "";
    for(int i=0;i<n;i++){
        freq[A[i] - 'a']++;
        q.push(i);
        while(!q.empty() && freq[A[q.front()] - 'a'] > 1){
            q.pop();
        }
        if(q.empty())
            ans += "#";
        else
            ans += A[q.front()];
    }
    return ans;
}
