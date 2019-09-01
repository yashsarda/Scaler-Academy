// Traverse through the boundary of the grid.
// Whenever you encounter an 'O', this 'O' and all its neigbouring connected O's will not be changed to X
// i.e the connected component for the O on the boundary is set to O itself. Any O's not on the boundary and not 
// connected to an 'O' which is on the boundary will be converted to X 
vector<vector<int> > visited;
int rows, col;
bool isSafe(int x,int y)
{
    return !(x < 0 || x >= rows || y < 0 || y >= col);
}
void dfs(int i, int j,vector<vector<char> >& A)
{
    visited[i][j] = true;
    A[i][j] = 'Y';
    int x[] = {1,-1,0,0};
    int y[] = {0,0,1,-1};
    for(int k=0;k<4;k++){
        int xco = x[k] + i;
        int yco = y[k] + j;
        if(isSafe(xco,yco) && !visited[xco][yco] && A[xco][yco] == 'O'){
            dfs(xco, yco, A);
        }
    }
}
void Solution::solve(vector<vector<char> > &A) {
    rows = A.size();
    col = A[0].size();
    visited.clear();
    visited.resize(rows);
    for(int i=0;i<rows;i++)
        visited[i].resize(col, false);
    
    // Traverse through the 4 boudaries
    for(int i=0;i<col;i++){
        if(A[0][i] == 'O'){
            dfs(0,i,A);
        }
    }
    for(int i=0;i<col;i++){
        if(A[rows - 1][i] == 'O'){
            dfs(rows - 1, i,A);
        }
    }
    for(int i=0;i<rows;i++){
        if(A[i][0] == 'O'){
            dfs(i,0,A);
        }
    }
    for(int i=0;i<rows;i++){
        if(A[i][col - 1] == 'O'){
            dfs(i, col - 1,A);
        }
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(A[i][j] == 'Y')
                A[i][j] = 'O';
            else if(A[i][j] == 'O')
                A[i][j] = 'X';
        }
    }
    
}
