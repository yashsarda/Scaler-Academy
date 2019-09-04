// Create a Directed graph and check if a cycle is present in  the graph
// If the cycle is present then we cannot complete all the courses
// The problem effectively boils down to finding a cycle in a Directed Graph
// And we can easily do this with a DFS

// We can detect a cycle in a Directed graph if there is a back edge in the graph
// For a back edge, the node is connected to one of the ancestors of that node
// So for a edge u --> v, if it is a back edge then the departure time of u < departure time of v
// Why? Beacuse u will be descendent of v, and first u will explore all its children and then v will explore all
// its children. Since u is a child of v, it's departure time will always be less than v

void dfs(vector<vector<int> >& graph,int node, vector<bool>& visited, vector<int>& departure, int& ti)
{
    visited[node] = true;
    
    for(auto child: graph[node]) {
        if(!visited[child])
            dfs(graph, child, visited, departure, ti);
    }
    
    departure[node] = ti++;
}
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    
    // Create a graph
    // The graph will contain A nodes and B.size() edges
    int n = B.size();
    vector<vector<int> > graph;
    graph.resize(A + 1);
    for(int i=0;i<n;i++){
        int from = B[i];
        int to = C[i];
        // create an edge
        graph[from].push_back(to);
    }
    
    vector<bool> visited(A + 1, false);
    vector<int> departure(A + 1);
    int ti = 0;
    // run a dfs and calculate the departure time
    for(int i=1;i<=A;i++){
        if(!visited[i])
            dfs(graph,i, visited, departure, ti);
    }
    
    for(int i=1;i<=A;i++){
        for(int j=0;j<graph[i].size();j++){
            int parent = i;
            int child = graph[i][j];
            if(departure[parent] <= departure[child])
                return 0;
        }
    }
    
    return 1;
    
    
    
}
