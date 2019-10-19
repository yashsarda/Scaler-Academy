// A bipartite graph can be colored with 2 colors. all the nodes in same set will have the same color
// tree is bipartite graph.
// A graph which has cycle containing odd number of nodes cannot be bipartite
// A graph which has cycle containing even number of nodes is still bipartite
vector<vector<int> > graph;
vector<int> color;
vector<bool> visited;
void init(int A)
{
    graph.clear();
    visited.clear();
    color.clear();
    graph.resize(A);
    color.resize(A);
    visited.resize(A, false);
}
int dfs(int node) 
{
    visited[node] = true;
    for(int i=0;i<graph[node].size();i++) {
        int child = graph[node][i];
        if(visited[child] && color[child] == color[node])
            return 0;
        if(!visited[child]) {
            color[child] = color[node] ^ 1;
            if(!dfs(child)) return 0;
        }
    }
    return 1;
    
}
int Solution::solve(int A, vector<vector<int> > &B) {
    init(A);
    int edges = B.size();
    // construction of a graph
    for(int i=0;i<edges;i++) {
        int source = B[i][0];
        int dest = B[i][1];
        graph[source].push_back(dest);
        graph[dest].push_back(source);
    }
    // check if we color it with 2 colors using dfs
    color[0] = 0;
    int answer = 1;
    // Forgot the graph could also be not connected
    for(int i=0;i<A;i++) {
        if(!visited[i])
            answer &= dfs(i);
    }
    return answer;
}
