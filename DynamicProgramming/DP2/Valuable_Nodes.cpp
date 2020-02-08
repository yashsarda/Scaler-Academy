const int mod = 1000000007;
typedef long long ll;
int N;
vector<ll> include;
vector<ll> exclude;
vector<ll> grand_exclude;
vector<vector<int> > adj;
vector<int> values;
void init(int N)
{
    include.clear();
    exclude.clear();
    grand_exclude.clear();
    values.clear();
    adj.clear();
    include.resize(N + 5, 0);
    exclude.resize(N + 5, 0);
    grand_exclude.resize(N + 5, 0);
    adj.resize(N + 5);
	values.resize(N + 5);
}
inline ll add(ll a, ll b)
{
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
void dfs(int node, int parent)
{
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    for(int child: adj[node]) {
         if(child == parent)
            continue;
        dfs(child, node);
        sum1 = add(sum1, grand_exclude[child]);
        sum2 = add(sum2, max(exclude[child], include[child]));
        sum3 = add(sum3, exclude[child]);
    }
    include[node] = add(values[node],sum1);
    exclude[node] = sum2;
    grand_exclude[node] = sum3;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    N = A.size();
	init(N + 5);
	for(int i=0;i<N;i++) {
	    int node_number = i + 1;
	    int parent = A[i];
	    adj[node_number].push_back(parent);
	    adj[parent].push_back(node_number);
	}
	for(int i=0;i<N;i++)
	    values[i + 1] = B[i];
	dfs(1, 0);
	ll ans = max(include[1], exclude[1]);
	return ans;
}

/*

        1(90)
       / \ \
     2-2 100-3 4-4
         / \
         5-5  6-6
           / \
           7-7  8-8
*/
