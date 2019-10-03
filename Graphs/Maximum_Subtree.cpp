/*
5
4 1 3 3 5
4 3 2 4 1
2 1 3
*/
const int N = 100005;
int max_size;
vector<int> size(N);
vector<int> parent(N);
void init(int A)
{
    for(int i=1;i<=A;i++) {
        parent[i] = i;
        size[i] = 1;
    }
    max_size = 1;
}
int findset(int node)
{
    return (parent[node] == node ? node : findset(parent[node]));
}
void merge(int a, int b)
{
    a = findset(a);
    b = findset(b);
    if(a == b)
        return;
    
        
   if(size[a] < size[b])
   {
        parent[a] = b  ;
        size[b] += size[a] ;
        if(max_size < size[b])
            max_size = size[b];
   }
   else
   {
        parent[b] = a  ;
        size[a] += size[b] ;
        if(max_size < size[a])
            max_size = size[a];
   }
}
vector<int> Solution::solve(int A, vector<int> &B, vector<int> &C, vector<int> &D) {
    int dsize = D.size();
    int bsize = B.size();
    vector<int> ans;
    vector<bool> which_edge(A + 5, false);
    for(int x: D) {
        which_edge[x - 1] = true;
    }
    init(A);
    for(int i=0;i<bsize;i++) {
        int from = B[i];
        int to = C[i];
        if(which_edge[i])
            continue;
        merge(from, to);
    }
    ans.push_back(max_size);
    for(int i=dsize-1;i>=1;i--) {
        int edge_number = D[i] - 1;
        int node1 = B[edge_number];
        int node2 = C[edge_number];
        merge(node1, node2);
        ans.push_back(max_size);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}
