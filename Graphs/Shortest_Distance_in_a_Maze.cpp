// To find shortest path we need to use BFS
// Now, the thing here is that we need to push only that element in the queue which can be travelled the
// maximum distance until a wall is hit
// If our stop is the destination(i.e we will hit the wall if we travel any further then we return answer)
// If the queue is empty and we still did not hit our destination then our answer is -1
struct node
{
    int x;
    int y;
};
int rows, col;
bool isSafe(int x,int y)
{
    return !(x < 0 || x >= rows || y < 0 || y >= col);
}

int Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    rows = A.size();
    col = A[0].size();
    vector<vector<int> > visited, ans;
    visited.resize(rows);
    for(int i=0;i<rows;i++)
        visited[i].resize(col, false);
    
    ans.resize(rows);
    for(int i=0;i<rows;i++)
        ans[i].resize(col, 0);
    
    queue<node> q;
    q.push({B[0],B[1]});
    visited[B[0]][B[1]] = true;
    
    while(!q.empty()){
        node c = q.front();
        q.pop();
        int xc[] = {1,-1,0,0};
        int yc[] = {0,0,1,-1};
        for(int i=0;i<4;i++){
            node prev = c;
            int xd = xc[i] + c.x;
            int yd = yc[i] + c.y;
            int add = 0;
            while(isSafe(xd,yd) && A[xd][yd] == 0){
                prev = {xd,yd};
                xd += xc[i];
                yd += yc[i];
                add++;
            }
            if((prev.x != c.x || prev.y != c.y) && !visited[prev.x][prev.y]){
                visited[prev.x][prev.y] = true;
                q.push(prev);
                ans[prev.x][prev.y] = add + ans[c.x][c.y];
                if(prev.x == C[0] && prev.y == C[1])
                    return ans[prev.x][prev.y];
            }
        }
    }
    return -1;
    
}
