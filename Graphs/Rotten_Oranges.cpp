
bool isSafe(int x,int y,int rows,int col)
{
    if(x < 0 || x >= rows || y < 0 || y >= col)
        return false;
    
    return true;
}
int Solution::solve(vector<vector<int> > &A) {
    
    int rows = A.size();
    int col = A[0].size();
    
    if(rows == 1 && col == 1)
        return (A[0][0] == 2 ? 0 : -1);
    
    queue<pair<pair<int,int>,int> > q;
    vector<vector<int> > visited;
    visited.resize(rows + 1);
    for(int i=0;i<=rows;i++)
        visited[i].resize(col + 1, false);
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(A[i][j] == 2){
                q.push({{i,j},0});
                visited[i][j] = true;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        pair<pair<int,int>,int> node = q.front();
        q.pop();
        int xco = node.first.first;
        int yco = node.first.second;
        int ti = node.second;
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        
        for(int i=0;i<4;i++){
            int xd = x[i] + xco;
            int yd = y[i] + yco;
            if(isSafe(xd,yd,rows,col) && !visited[xd][yd] && A[xd][yd] == 1){
                A[xd][yd] = 2;
                visited[xd][yd] = true;
                ans = max(ans, ti + 1);
                q.push({{xd,yd}, ti + 1});
            }
        }
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(A[i][j] == 1){
                return -1;
            }
        }
    }
    return ans;
    
    
}
