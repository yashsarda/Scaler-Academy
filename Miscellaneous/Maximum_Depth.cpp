const int N = 100000;
set<long long> s[N];
vector<int> Solution::solve(int A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E, vector<int> &F) {
    vector<int> answer;
    for(int i=0;i<N;i++)
        s[i].clear();
    int query = E.size();
    vector<int> level(A,-1);
    vector<bool> visited(A, false);
    vector<vector<int> >  v;
    v.resize(A);
    int bsize = B.size();
    
    // Make an adjacency list
    for(int i=0;i<bsize;i++){
        int a = B[i] - 1;
        int b = C[i] - 1;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    queue<int> q;
    q.push(0);
    visited[0] = true;
    level[0] = 0;
    int max_depth = 0;
    s[0].insert(D[0]);
    // run BFS for finding all nodes at particular level
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0;i<v[node].size();i++){
            int child = v[node][i];
            if(!visited[child]){
                visited[child] = true;
                level[child] = level[node] + 1;
                s[level[child]].insert(D[child]);
                q.push(child);
            }
        }
    }
    max_depth = *max_element(level.begin(),level.end());
    //assert(max_depth >= 0);
    for(int i=0;i<query;i++){
        long long le = E[i] % (max_depth + 1);
        assert(le >= 0);
        // use binary search to find smallest node which has value >= X
        auto ans = s[le].lower_bound(F[i]);
        if(ans == s[le].end())
            answer.push_back(-1);
        else{
            int a = *ans;
            answer.push_back(a);
        }
    }
    return answer;
    
}
