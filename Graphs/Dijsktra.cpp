// Implementation of dijkstra's algorithm using sets
// For a proof of this : https://www.youtube.com/watch?v=NR0qG64gZUs&list=PLBF3763AF2E1C572F&index=35

struct edge
{
    int weight;
    int to;
    
};
vector<int> dijkstra(vector<vector<edge> >& graph, int source)
{
    int vertices = graph.size();
    vector<int> ans(vertices, INT_MAX);
    ans[source] = 0;
    set<pair<int,int> > active_vertices;
    active_vertices.insert({ 0, source });
    
    while(!active_vertices.empty()){
        int from = active_vertices.begin() -> second;
        active_vertices.erase(active_vertices.begin());
        for(auto child: graph[from]) {
            if(ans[child.to] > ans[from] + child.weight){
                active_vertices.erase({ ans[child.to], child.to });
                ans[child.to] = ans[from] + child.weight;
                active_vertices.insert({ ans[child.to], child.to });
            }
        }
    }
    
    for(int i=0;i<vertices;i++){
        if(ans[i] == INT_MAX)
            ans[i] = -1;
    }
    return ans;
}
vector<int> Solution::solve(int A, vector<vector<int> > &B, int C) {
    int rows = B.size();
    vector<vector<edge> > graph;
    graph.resize(A);
    for(int i=0;i<rows;i++){
        int from = B[i][0];
        int to = B[i][1];
        int weight = B[i][2];
        
        graph[from].push_back({weight, to});
        graph[to].push_back({weight, from});
    }
    vector<int> ans = dijkstra(graph, C);
    return ans;
}
