vector<vector<int> > graph;
unordered_map<int,int> compression;
vector<int> tree;
// initilize all the variable and DS
void init(int A)
{
    compression.clear();
    graph.clear();
    graph.resize(A + 1);
    tree.clear();
    tree.resize(70005);
}
// update the fenwick tree
void update(int idx, int value)
{
    for(int i=idx;i<70005;i+=i&(-i)) {
        tree[i] += value;
    }
}
// Sum all the elements from [1...idx]
int query(int idx)
{
    int sum = 0;
    for(int i=idx;i>0;i-=i&(-i)) {
        sum += tree[i];
    }
    return sum;
}
void dfs(int node, int parent, int number, vector<int>& answer, vector<int>& c)
{
    // update the tree with compressed value at that particular node
    update(compression[c[node - 1]], 1);
    // Number of element less than equal to given value is answer of query.
    // Just subtract it from total number of nodes visited till now from root
    answer[node - 1] = number - query(compression[c[node - 1]]);
    for(int child: graph[node]) {
        if(child == parent) continue;
        dfs(child, node, number + 1, answer, c);
    }
    // when we leave the current node, then update the value again
    update(compression[c[node - 1]], -1);
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    init(A.size());
    int edges =B.size();
    // Since the value of nodes is pretty big, we compress the nodes
    int val = 1;
    // First copy the array in another array
    vector<int> c(A.begin(), A.end());
    // Sort it and give the numbers to every element
    sort(A.begin(), A.end());
    compression[A[0]] = val;
    for(int i=1;i<A.size();i++) {
        if(A[i] != A[i - 1])
            val++;
        compression[A[i]] = val;
    }
    // Create the graph
    for(int i=0;i<edges;i++) {
        int from = B[i];
        int to = C[i];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vector<int> answer(A.size());
    dfs(1, 0, 1, answer, c);
    return answer;
}
