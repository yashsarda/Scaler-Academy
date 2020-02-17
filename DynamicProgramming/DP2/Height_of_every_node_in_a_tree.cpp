/*
For every node, the answer for that node can come from it's ancestors or it's children
answer[node] = max(in[node], out[node])
in[node] :- maximum height for a node you can get from it's children
out[node] :- maximum height for a node you can get from it's ancestors

// https://blogarithms.github.io/articles/2019-10/inout-dp-tree

*/
vector<vector<int> > graph;
int dfs1(int V, int pV, vector<int>& in)
{
    int height_for_node = 0;
    for(int child : graph[V]) {
        if(child == pV) 
            continue;
        int height_for_child = dfs1(child, V, in);
        height_for_node = max(height_for_node, 1 + height_for_child);
    }
    in[V] = height_for_node;
    return height_for_node;
}
void dfs2(int V, int pV, vector<int>& in, vector<int>& out) 
{
    int mx1 = -1;
    int mx2 = -1;
    for(int child : graph[V]) {
        if(child == pV)
            continue;
        if(in[child] >= mx1) {
            mx2 = mx1;
            mx1 = in[child];
        }
        else if(in[child] > mx2) {
            mx2 = in[child];
        }
    }
    for(int child : graph[V]) {
        if(child == pV)
            continue;
        out[child] = out[V];
        out[child] = 1 + max(out[child], 1 + ((in[child] == mx1) ? mx2 : mx1));
        dfs2(child, V, in, out);
    }
}
vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> answer(A);
    if(A == 1) {
        answer[0] = 0;
        return answer;
    }
    graph.clear();
    graph.resize(A + 1);
    vector<int> parent(A + 1);
    // Tree construction
    for(int i=0;i<B.size();i++) {
        int from = B[i][0];
        int to = B[i][1];
        graph[from].push_back(to);
        graph[to].push_back(from);
        parent[to] = from;
    }
    vector<int> in(A + 1, 0);
    dfs1(1, 0, in);
    vector<int> out(A + 1, 0);
    dfs2(1, 0, in, out);
    for(int i=0;i<A;i++) {
        answer[i] = max(in[i + 1], out[i + 1]);
    } 
    return answer;
}
