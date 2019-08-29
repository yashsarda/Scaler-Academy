typedef long long ll;
const int mod = 1e9 + 7;
int Solution::nchoc(int A, vector<int> &B) {
    int size = B.size();
    if(A == 0)
        return 0;
    priority_queue<ll> pq;
    for(int i=0;i<size;i++)
        pq.push(B[i]);
    ll ans = 0;
    for(int i=0;i<A;i++){
        ll t = pq.top();
        pq.pop();
        ans = (ans % mod + t % mod) % mod;
        pq.push(t / 2);
    }
    
    return ans;
    
}
