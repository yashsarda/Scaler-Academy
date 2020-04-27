/*
Given a tree with N nodes numbered from 1 to N. Each node has a lowercase character associated with it. 
You are given Q queries, in each query you are given two integers u and v and you are required to find the character with a 
minimum non-zero frequency in a simple path from u to v.
 NOTE:
If there is more than one character with minimum frequency, then output the lexographically smallest character.
Each edge in the tree is bi-directional.
*/

vector<vector<int> > graph, table, pre;
vector<int> depth;
int D;
// initliaze all the ds
void init(int nodes)
{
    graph.clear();
    depth.clear();
    table.clear();
    pre.clear();
    pre.resize(nodes);
    for(int i = 0; i < nodes; i++)
        pre[i].resize(26, 0);
    depth.resize(nodes);
    graph.resize(nodes);
}
// The highest jump we can take
int findLog(int nodes)
{
    int i;
    for(i = 31; i >= 0; i--) {
        if(nodes & (1LL << i)) 
            break;
    }
    
    return i;
}
// Walk up the tree k edges from node
int walk(int node, int k)
{
    for(int d = 0; d <= D && node != -1; d++) {
        if(k & (1 << d)) {
            node = table[d][node];
        }
    }
    return node;
}
// Find the LCA of two nodes
int LCA(int u, int v)
{
    // Make both the nodes at the same level
    if(depth[u] > depth[v]) 
        u = walk(u, depth[u] - depth[v]);
        
    if(depth[v] > depth[u])
        v = walk(v, depth[v] - depth[u]);
    
    
    // cout << u << ' ' << v << '\n';
    
    if(u == v)
        return u;
    
    for(int d = D; d >= 0; d--) {
        if(table[d][u] != table[d][v]) {
            u = table[d][u];
            v = table[d][v];
        }
    }
    
    return table[0][u];
}
// Precompute the frequency of characters from root to that particular node
void dfs(int V, int pV, vector<int>& info, vector<char>& A)
{
    info[A[V] - 'a']++;
    pre[V] = info;
    for(int child : graph[V]) {
        if(child == pV)
            continue;
        dfs(child, V, info, A);
    }
    info[A[V] - 'a']--;
}
string Solution::solve(vector<char> &A, vector<vector<int> > &B, vector<vector<int> > &C) {
    int nodes = A.size();
    int edges = B.size();
    init(nodes);
    // Find the max depth 
    D = findLog(nodes);
    // Init the table
    table.resize(D + 1);
    for(int d = 0; d <= D; d++) {
        table[d].resize(nodes, -1);
    }
    // Create the tree
    for(int i = 0; i < edges; i++) {
        int from = B[i][0] - 1;
        int to = B[i][1] - 1;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    // Compute the depth information
    vector<bool> seen(nodes, false);
    depth[0] = 0;
    seen[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int child : graph[node]) {
            if(!seen[child]) {
                table[0][child] = node;
                seen[child] = true;
                depth[child] = depth[node] + 1;
                q.push(child);
            }
        }
    }
    // table[d][i] = node at which we will land if we made a jump of 2^k from node i
    for(int d = 1; d <= D; d++) {
        for(int v = 0; v < nodes; v++) {
            int mid = table[d - 1][v];
            if(mid != -1)
                table[d][v] = table[d - 1][mid];
        }
    }
    vector<int> info(26, 0);
    dfs(0, -1, info, A);
    
    
    int queries = C.size();
    string answer = "";
    for(int i = 0; i < queries; i++) {
        int from = C[i][0] - 1;
        int to = C[i][1] - 1;
        
        int lca = LCA(from, to);
        int mini = INT_MAX;
        char ans = '\0';
        for(int i = 0; i < 26; i++) {
            int inter = pre[from][i] + pre[to][i] - 2 * (pre[lca][i]) + (A[lca] - 'a' == i);
            
            if(inter == 0)
                continue;
            if(inter < mini) {
                ans = i + 'a';
                mini = inter;
            }
        }
        
        answer += ans;
    }
    return answer;
}

/*
12 a b c a x e f d a c b c
11 2 1 2 2 4 1 3 2 5 5 6 5 7 3 8 8 9 3 12 9 10 9 11
3 2 10 12 6 7 4 11
1 2 4 11

10 h g o z x i w p j s 
9 2 6 2 10 5 5 2 8 2 2 1 3 1 9 8 7 6 4 1 
8 2 8 1 7 4 9 3 8 1 10 8 7 4 8 1 10 5 

*/