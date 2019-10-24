const int LARGE = 1e6;
typedef long long ll;
struct edge
{
    int to;
    ll regular_cost;
    ll taxi_cost;
};
vector<vector<edge> > graph;
// initilization
void init(int nodes)
{
    graph.clear();
    graph.resize(nodes + 1);
}
// dijkstra template
void dijkstra(int source, vector<ll>& min_distance)
{
    // distance from source to source is 0
    min_distance[source] = 0;
    // this denotes the set of active vertices. The set will only contain those elements
    // which have the their shortest path computed from source
    set<pair<ll,int> > active_vertices;
    active_vertices.insert({0, source});
    
    // While all the vertices are not visited
    while(!active_vertices.empty()) {
        int where = active_vertices.begin() -> second;
        // remove the vertex with the smallest cost
        active_vertices.erase(active_vertices.begin());
        // Relax every edge from this node
        for(auto e: graph[where]) {
            if(min_distance[e.to] > min_distance[where] + e.regular_cost) {
                active_vertices.erase({min_distance[e.to], e.to});
                min_distance[e.to] = min_distance[where] + e.regular_cost;
                active_vertices.insert({min_distance[e.to], e.to});
            }
        }
    }
}
int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
    init(A);
    int edges = B.size();
    vector<ll> min_distance_from_source(A + 1, LARGE);
    vector<ll> min_distance_from_dest(A + 1, LARGE);
    // Create the graph
    for(int i=0;i<edges;i++) {
        int from = B[i][0];
        int to = B[i][1];
        ll rc = B[i][2];
        ll tc = B[i][3];
        graph[from].push_back({to, rc,tc});
        graph[to].push_back({from, rc, tc});
    }
    // Run dijkstra from considering the source as starting and second one as dest as starting
    dijkstra(C, min_distance_from_source);
    dijkstra(D, min_distance_from_dest);
    ll ans = min_distance_from_source[D];
    // If unreacable then -1
    if(ans == LARGE) return -1;
    for(int i=0;i<edges;i++) {
        ll compare = 0;
        // If we have a direct edge then just consider the taxi cost
        if((B[i][0] == C && B[i][1] == D) || (B[i][0] == D && B[i][1] == C)) 
            compare = B[i][3];
        // break down the  path into parts min of [Source to A] + taxi_cost(A - B) + [Dest to B]
        // or [Source to B] + taxi_cost(A - B) + [Dest to A]
        else {
            compare = min(min_distance_from_source[B[i][0]] + B[i][3] + min_distance_from_dest[B[i][1]],
                          min_distance_from_source[B[i][1]] + B[i][3] + min_distance_from_dest[B[i][0]]);
        }
        ans = min(ans, compare);
    }
    return ans;
}
s