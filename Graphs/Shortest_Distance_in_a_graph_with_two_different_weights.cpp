// Basically 0-1 BFS
// Whenever we encounter an edge length of 2, split it into 2 edges of length 1 each
// After doing this modification we have a graph with all its edges of equal weight
// And to find the shortest path in an undirected graph with equal weights of all the vertices
// we use BFS
int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
    vector<vector<int> > graph;
    graph.resize(3 * A);
    int n = B.size();
    int increase = A;
    for(int i=0;i<n;i++){
        int from = B[i][0];
        int to = B[i][1];
        int weight = B[i][2];
        if(weight == 2){
            graph[from].push_back(A);
            graph[A].push_back(from);
            graph[A].push_back(to);
            graph[to].push_back(A);
            A += 1;
        }
        else {
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
    }
    queue<int> q;
    vector<bool> visited(A, false);
    vector<int> distance(A, 0);
    distance[C] = 0;
    q.push(C);
    if(C == D)
        return 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto child: graph[node]){
            if(!visited[child]){
                visited[child] = true;
                distance[child] = distance[node] + 1;
                if(child == D)
                    return distance[child];
                q.push(child);
            }
        }
    }
    
    return -1;
}
