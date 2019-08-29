// Idea : We already have an array of visited cities. Now from these visited cities we can go to their adjacent cities only
// So what we do is we group the chunk of consecutive unvisited cities together.
// We calculate in how many ways we can combine these consecutive cities.
// Suppose the size of chunk is k, and this chunk has visited cities on the left and the right side
// 1 2 3 4 5 6. 2 & 6 are visited, so the middle chunk is [3,4,5]. Now in first step we can choose from 3 or 5(2 choices)
// Now for each of these 2 choices we only have 1 choice left. If we take a larger chunk [3,4,5,6], then initially
// 2 choices 3 or 6. Then for each of these 2 choices we again have 2 choice and so on until we have one choice left.
// So the total possible combinations = 2^(k-1).
// For each group you can calculate it similarly and then multiply all of them. Now we can permuate in between [all the the groups
// but not each group], hence the total permuatation = (k1 + k2 + k3 + ... + kn)! / k1! * k2! * k3! * .... * kn!
// Multiply this to get the final ans
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

const int N = 2000 + 10, mod = 1e9 + 7;
int fact[N], invfact[N];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((ll) x) * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
void pre(){
    fact[0] = invfact[0] = 1;
    for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
    invfact[N - 1] = inv(fact[N - 1]);
    for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
    assert(invfact[1] == 1);
}
inline int C(int n, int k){
    if(n < k || k < 0) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}
int Solution::solve(int A, vector<int> &B) {
    pre();
    sort(B.begin(),B.end());
    int n = B.size();
    int size_of_last;
    int count = 0;
    int size_of_first = B[0] - 1;
    count += size_of_first;
    int in = 1;
    int ans = 1;
    in = mul(in,invfact[size_of_first]);
    for(int i=1;i<n;i++){
        int el = B[i] - 1;
        if(el - B[i-1] > 0){
             count += el - B[i-1];
             ans = mul(ans,powr(2,el-B[i-1]-1));
             in  = mul(in,invfact[el-B[i-1]]);
        }
    }
    size_of_last = A - B[n-1];
    count += size_of_last;
    in = mul(in,invfact[size_of_last]);
    in = mul(in,fact[count]);
    int final_ans = 1;
    final_ans = mul(in,ans);

    return final_ans;


}
