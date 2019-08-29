// Sliding window maximum and minimum for all subarrays od size k using deque
const int mod  = 1e9 + 7;
typedef long long ll;
inline ll add(ll a,ll b) { a += b;if(a >= mod) a-=mod; return a; }
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    deque<int> dq(B);
    ll max_sum = 0;
    for(int i=0;i<B;i++){
        while(!dq.empty() && A[dq.back()] < A[i])
             dq.pop_back();
        dq.push_back(i);
    }
    max_sum = add(max_sum,(ll)A[dq.front()]);
    for(int i=B;i<n;i++){
        int element = A[i];
        int x = dq.front();
        if(x + B - 1 < i){
            dq.pop_front();
        }
        while(!dq.empty() && A[dq.back()] < A[i])
            dq.pop_back();
        dq.push_back(i);
      //  cout << dq.front() << '\n';
         max_sum = add(max_sum,(ll)A[dq.front()]);
         // Check for negative number since mod is different
         if(max_sum < 0)
            max_sum += mod;
    }
    while(!dq.empty())
        dq.pop_front();
    
    ll min_sum = 0;
    for(int i=0;i<B;i++){
        while(!dq.empty() && A[dq.back()] > A[i])
            dq.pop_back();
        dq.push_back(i);
    }
    
    min_sum = add(min_sum,(ll)A[dq.front()]);
    for(int i=B;i<n;i++){
        int x = dq.front();
        if(x + B - 1 < i){
            dq.pop_front();
        }
        while(!dq.empty() && A[dq.back()] > A[i])
            dq.pop_back();
        dq.push_back(i);
        min_sum = add(min_sum,(ll)A[dq.front()]);
        if(min_sum < 0)
            min_sum += mod;
    }
    ll ans = add(min_sum,max_sum);
    if(ans < 0)
        ans += mod;
    return ans;
}
