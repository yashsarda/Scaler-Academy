int Solution::longestConsecutive(const vector<int> &A) {
    int n = A.size();
    int ans = 0;
    map<int,int> m;
    for(int i=0;i<n;i++)
        m[A[i]] = 1;
    for(int i=0;i<n;i++){
        if(m.find(A[i] - 1) != m.end())
            continue;
        int x = A[i];
        int count = 0;
        while(m.find(x) != m.end()){
            x++;
            count++;
        }
        ans = max(ans,count);
    }
    return ans;
}
