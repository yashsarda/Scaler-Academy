int Solution::solve(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    map<int,bool> m;
    for(int i=0;i<n;i++)
        m[A[i]] = true;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(m.find(A[i] + A[j]) != m.end())
                ans++;
        }
    }
    return ans;
}
