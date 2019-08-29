const int mod = 1e9 + 7;
typedef long long ll;
const int N = 105;
ll fact[N],inv[N];
inline ll add(ll a,ll b)
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
inline ll mul(ll a,ll b)
{
    return (a % mod * b % mod) % mod;
}
inline ll power(ll a,ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = mul(ans,a);
        }
        a = mul(a,a);
        b >>= 1;
    }
    return ans;
}
ll inverse(ll number)
{
    return power(number,mod - 2);
}
void precompute()
{
    inv[0] = fact[0] = 1;
    for(int i=1;i<N;i++)
        fact[i] = mul(fact[i - 1],i);
    
    inv[N - 1] = inverse(fact[N - 1]);
    
    for(int i=N - 2;i>=1;i--)
        inv[i] = mul(inv[i + 1],i + 1);
    assert(inv[1] == 1);
}
ll nck(int n,int k)
{
    if(k > n || k < 0)  return 0;
    
    return mul(fact[n],mul(inv[n -k],inv[k]));
}
// Reccurence relation
// l = # of elements in the left subtree, r = # of element in right subtree
// T(N) = (N - 1 C l) * T(l) * T(r)
// How to find l?
// All the levels of the binary heap will be filled except the last level
// if H = height og heap, then h = log2(N)
// h - 1 levels are completely filled, therefore 2 ^ h - 1 nodes must be there in the left subtree
// Now we need to find how many nodes are there in the last level which belong to the left subtree
// Last level will contain = 2^ h nodes in complete binary tree
// we will subtract the total nodes that we are given from 2 ^ h and add 1 so that we get number of nodes
// in the last level
// Now the last level can be completely in the left subtree or some part of it might be in the right subtree
// if number of nodes in last level >= 2^(h / 2) then some will be in the right subtree
// So just take min of (number of nodes, 2 ^ (h / 2))
ll findTotalHeaps(int A)
{
    if(A <= 2)
        return 1;
    int number_of_element_in_left = 0;
    int number_of_element_in_right = 0;
    
    int height = log2(A);
    number_of_element_in_left = sub((1 << (height - 1)), 1);
    ll extra = A - (1 << height) + 1;
    if(extra == 0)
        extra = (1 << (height - 1));
    int first = (1 << (height - 1));
    number_of_element_in_left += min(first,(int)extra);
    number_of_element_in_right = A - 1 - number_of_element_in_left;
    ll ans = 0;
    ans += nck(A - 1,number_of_element_in_left);
    ans = mul(ans,mul(findTotalHeaps(number_of_element_in_left),findTotalHeaps(number_of_element_in_right)));
    return ans;
}
int Solution::solve(int A) {
    
    if(A <= 1)
        return 1;
    precompute();
    ll ans = findTotalHeaps(A);
    return ans;
}
