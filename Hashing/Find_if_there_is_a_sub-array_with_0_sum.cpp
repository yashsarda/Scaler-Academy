typedef long long ll;
int Solution::solve(vector<int> &A) {
    int n = A.size();
    map<ll,int> m;
    m[0] = -1;
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += A[i];
        if(m.find(sum) != m.end())
            return 1;
        else
            m[sum] = i;
    }
    return 0;
}
