const int mod = 1e9 + 7;
typedef long long ll;
inline ll add(ll a, ll b)
{
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
inline int mul(int a, int b)
{
    return (a * 1ll * b) % mod;
}
vector<vector<int> > graph;
vector<vector<long long> > dp;
int dfs(int V, int pV, int g, int B)
{
    if(dp[V][g] != -1)
        return dp[V][g];
    
    if(graph[V].size() == 1) {
        int ans = 0;
        for(int i=1;i<=B;i++) {
            ans += (__gcd(i, g) == 1);
        }
        dp[V][g] = ans;
        return ans;
    }
    int answer = 0;
    for(int i=1;i<=B;i++) {
        int gd = __gcd(g, i);
        int ways = 1;
        for(int child: graph[V]) {
            if(child == pV) continue;
            ways = mul(ways, dfs(child, V, gd, B));
        }
        answer = add(answer, ways);
    }
    dp[V][g] = answer;
    return answer;
}
int Solution::solve(int A, int B, vector<int> &parent) {
    graph.clear();
    dp.clear();
    dp.resize(A + 1);
    for(int i=1;i<=A;i++)
        dp[i].resize(B + 1, -1);
    graph.resize(A + 1);
    for(int i=0;i<A;i++) {
        graph[i + 1].push_back(parent[i]);
        if(i != 0)
            graph[parent[i]].push_back(i + 1);
    }
    int answer = 0;
    answer = dfs(1, 1, 0, B);
    return answer;
}
