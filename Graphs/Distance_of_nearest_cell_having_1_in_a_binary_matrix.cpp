int rows, col;
struct point
{
    int x,y,dist;
};
bool isSafe(int x,int y)
{
    return !(x < 0 || x >= rows || y < 0 || y >= col);
}
vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    vector<vector<int> > ans;
    rows = A.size();
    col = A[0].size();
    
    ans.resize(rows);
    for(int i=0;i<rows;i++)
        ans[i].resize(col);
    
    queue<point> q;
    vector<vector<int> > visited;
    visited.resize(rows);
    for(int i=0;i<rows;i++)
        visited[i].resize(col,false);
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(A[i][j] == 1){
                ans[i][j] = 0;
                visited[i][j] = true;
                q.push({i,j,0});
            }
        }
    }
    while(!q.empty()){
        point node = q.front();
        q.pop();
        
        int xco = node.x;
        int yco = node.y;
        int distance = node.dist;
        
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        
        for(int i=0;i<4;i++){
            int xd = x[i] + xco;
            int yd = y[i] + yco;
            
            if(isSafe(xd,yd) && !visited[xd][yd]){
                visited[xd][yd] = true;
                ans[xd][yd] = distance + 1;
                q.push({xd,yd,ans[xd][yd]});
            }
        }
    }
    
    return ans;
}
