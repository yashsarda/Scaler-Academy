long long dp[1 << 20 + 1];
bool findIfAllSet(vector<vector<int> >& adjList, long long mask, int A, int check)
{
    vector<int> lis = adjList[check + 1];
    if(lis.empty()) return true;
    for(int element : lis) {
        int x = element - 1;
        if((mask & (1 << x)) == 0)    
            return false;
    }
    return true;
}
long long countAllTopologicalSort(vector<vector<int> >& adjList, long long mask, int A)
{
    if(mask == (1 << A) - 1) {
        return 1;
    }
    if(dp[mask] != -1)
        return dp[mask];
    long long answer = 0;
    for(int i=1;i<=A;i++) {
        int j = i - 1;
        if((mask & (1 << j))) continue;
        bool check = findIfAllSet(adjList, mask | (1 << j), A, j);
        if(check)
            answer += countAllTopologicalSort(adjList, mask | (1 << j), A);
    }
    dp[mask] = answer;
}
string Solution::solve(int A) {
    vector<vector<int> > adjList;
    adjList.resize(A + 5);
    for(int i=0;i<(1 << 20) + 1;i++)
        dp[i] = -1;
    for(int i=1;i<=A;i++) {
        for(int j=1;j<=A;j++) {
            if(i == j) continue;
            if((i & j) == i) {
                adjList[j].push_back(i);
            }
        }
    }
    int mask = 0;
    long long answ = countAllTopologicalSort(adjList, mask, A);
    string answer = "";
    answer = to_string(answ);
    return answer;
    
}
