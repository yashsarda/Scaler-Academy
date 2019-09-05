// The problem boils down to finding the MST for a graph
// We'll find a MST using Kruskal's algorithm
vector<int> parent;
int findset(int node)
{
    return (parent[node] == node) ? node : findset(parent[node]);
}
void merge(int a, int b)
{
    a = findset(a);
    b = findset(b);
    
    if(a == b)
        return;
    
    parent[a] = b;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<pair<int, pair<int,int>> > graph;
    int rows = B.size();
    int col = 3;
    
    // create a graph
    for(int i=0;i<rows;i++){
        int from = B[i][0];
        int to = B[i][1];
        int weight = B[i][2];
        
        graph.push_back({weight, {from,to}});
    }
    
    parent.resize(A + 1);
    for(int i=0;i<=A;i++)
        parent[i] = i;
    
    sort(graph.begin(), graph.end());
    
    int ans = 0;
    for(int i=0;i<rows;i++){
        int from = graph[i].second.first;
        int to = graph[i].second.second;
        int weight = graph[i].first;
        
        if(findset(from) != findset(to)){
            ans += weight;
            merge(from, to);
        }
    }
    
    return ans;
    
}
