typedef long long ll;
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    map<ll,int> m;
    ll sum = 0;
    m[0] = -1;
    int ans = -1;
    for(int i=0;i<n;i++){
        sum += A[i];
        if(m.find(sum) == m.end())
            m[sum] = i;
        if(m.find(sum-B) != m.end()){
            ans = max(ans, i - m[sum - B]);
        }
    }
    return ans;
}
