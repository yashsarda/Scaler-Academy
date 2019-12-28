const int mod = 1e9 + 7;
typedef long long ll;
inline ll add(ll a, ll b)
{
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
inline ll sub(ll a,ll b)
{
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}
inline ll mul(ll a, ll b)
{
    return (a * 1ll * b) % mod;
}
int Solution::solve(vector<int> &A) {
    int len = A.size();
    vector<int> greater_right(len, len);
    vector<int> greater_left(len, -1);
    
    stack<int> s;
    s.push(0);
    for(int i=1;i<len;i++) {
        int element = A[i];
        while(!s.empty() && element >= A[s.top()]) {
            greater_right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(len - 1);
    for(int i=len - 2;i>=0;i--) {
        int element = A[i];
        while(!s.empty() && element >= A[s.top()]) {
            greater_left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    ll answer = 0;
    // x = number of elements greater than current element on the right hand side
    // y = number of elements less than current element on the left hand side
    
    for(int i=0;i<len;i++) {
        ll x = greater_right[i] - i - 1;
        ll y = i - greater_left[i] - 1;
        answer = add(answer, mul(x, 1ll * A[i]));
        answer = add(answer, mul(y,  1ll *A[i]));
        answer = add(answer, mul(mul(x,y), 1ll * A[i]));
    }
    greater_right.clear();
    greater_right.resize(len, len);
    greater_left.clear();
    greater_left.resize(len, -1);
    s.push(0);
     for(int i=1;i<len;i++) {
        int element = A[i];
        while(!s.empty() && element <= A[s.top()]) {
            greater_right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(len - 1);
    for(int i=len - 2;i>=0;i--) {
        int element = A[i];
        while(!s.empty() && element <= A[s.top()]) {
            greater_left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=0;i<len;i++) {
        ll x = greater_right[i] - i - 1;
        ll y = i - greater_left[i] - 1;
        ll temp = add(mul(x, 1ll * A[i]), mul(y, 1ll * A[i]));
        ll t1 = mul(x, y);
        temp = add(temp, mul(t1, A[i]));
        answer = sub(answer, temp);
    }
    return answer; 
}
