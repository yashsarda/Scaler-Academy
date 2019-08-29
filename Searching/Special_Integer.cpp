const int N = 100005;
vector<long long> pref(N);
// We can also use sliding window
bool f(int check,int n,int B)
{
    bool flag = false;
    for(int i=0;i<=n - check;i++){
        long long sum = 0;
        sum = pref[i + check] - pref[i];
        if(sum > B){
            flag = true;
        }
    }
    if(flag)
        return false;
    return true;
    
}
int Solution::solve(vector<int> &A, int B) {
    pref[0] = 0;
    int n = A.size();
    for(int i=1;i<=n;i++)
        pref[i] = pref[i-1] + A[i-1];
    int lb = 0;
    int ub = n;
    int ans = 0;
    while(lb <= ub){
        int mid = (lb) + (ub - lb) / 2;
        if(!f(mid,n,B))
            ub = mid - 1;
        else{
            ans = mid;
            lb = mid + 1;
        }
    }
    return ans;
}
