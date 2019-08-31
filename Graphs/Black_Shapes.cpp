//find the number of connected components
int rows,col;
vector<vector<int> > visited;
bool isSafe(int x,int y)
{
    return !(x < 0 || x >= rows || y < 0 || y >= col);
}
void dfs(int x,int y,vector<string>& A)
{
    int xa[] = {0,0,1,-1};
    int ya[] = {1,-1,0,0};
    
    for(int i=0;i<4;i++){
        int xd = x + xa[i];
        int yd = y + ya[i];
        if(isSafe(xd,yd) && !visited[xd][yd] && A[xd][yd] == 'X'){
            visited[xd][yd] = true;
            dfs(xd,yd,A);
        }
    }
}
int Solution::black(vector<string> &A) {
    rows = A.size();
    col = A[0].size();
    
    int ans = 0;
    visited.clear();
    visited.resize(rows + 1);
    for(int i=0;i<rows + 1;i++)
        visited[i].resize(col + 1, false);
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(A[i][j] == 'X' && !visited[i][j]){
                ans++;
                visited[i][j] = true;
                dfs(i,j,A);
            }
        }
    }
    return ans;
}
