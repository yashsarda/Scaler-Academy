vector<vector<int> > same;
vector<vector<int> > rev;
vector<int> forw;
vector<int> backward;
void init(int A)
{
    same.clear();
    rev.clear();
    forw.clear();
    backward.clear();
    same.resize(A + 5);
    rev.resize(A + 5);
    forw.resize(A + 5);
    backward.resize(A + 5);
}
void dfs(int node, int parent, int& total)
{
    for(int i=0;i<same[node].size();i++) {
        int child = same[node][i];
        if(child == parent) continue;
        dfs(child, node, total);
    }
    
    for(int i=0;i<rev[node].size();i++) {
        int child = rev[node][i];
        if(child == parent) continue;
        total++;
        dfs(child, node, total);
    }
}
void dfs2(int node, int parent, int fcount, int bcount)
{
    forw[node] = fcount;
    backward[node] = bcount;
    
    for(int i=0;i<same[node].size();i++) {
        int child = same[node][i];
        if(child == parent) continue;
        
        dfs2(child, node, fcount + 1, bcount);
    }
    
    for(int i=0;i<rev[node].size();i++) {
        int child = rev[node][i];
        if(child == parent) continue;
        
        dfs2(child, node, fcount, bcount + 1);
    }
}
vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    int edges = A - 1;
    init(A);
    for(int i=0;i<B.size();i++) {
        same[B[i][0]].push_back(B[i][1]);
        rev[B[i][1]].push_back(B[i][0]);
    }
    int total = 0;
    dfs(1, 0, total);
    vector<int> answer;
    dfs2(1, 0, 0, 0);
    
    int min_val = INT_MAX;
    for(int i=1;i<=A;i++) {
        min_val = min(min_val, forw[i] + total - backward[i]);
    }
    for(int i=1;i<=A;i++) {
        if(forw[i] + total - backward[i] == min_val)
            answer.push_back(i);
    }
    return answer;
    
}
