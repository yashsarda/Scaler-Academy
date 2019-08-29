bool isSafe(int i,int j,vector<vector<int> >& A)
{
    int n = A.size();
    int m = A[0].size();
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if(A[i][j] == -1)
        return false;
    return true;
}
int countPaths(int i,int j,vector<vector<int> >& visited,vector<vector<int> >& A,int target,int hops)
{
    if(A[i][j] == 2){
        if(hops == target)
            return 1;
        return 0;
    }
    
    int sum = 0;
    if(isSafe(i,j+1,A) && !visited[i][j+1]){
        visited[i][j+1] = 1;
        sum += countPaths(i,j+1,visited,A,target,hops+1);
        visited[i][j+1] = 0;
    }
    if(isSafe(i,j-1,A) && !visited[i][j-1]){
        visited[i][j-1] = 1;
        sum += countPaths(i,j-1,visited,A,target,hops+1);
        visited[i][j-1] = 0;
    }
    if(isSafe(i+1,j,A) && !visited[i+1][j]){
        visited[i+1][j] = 1;
        sum += countPaths(i+1,j,visited,A,target,hops+1);
        visited[i+1][j] = 0;
    }
    if(isSafe(i-1,j,A) && !visited[i-1][j]){
        visited[i-1][j] = 1;
        sum += countPaths(i-1,j,visited,A,target,hops+1);
        visited[i-1][j] = 0;
    }
    return sum;
}
int Solution::solve(vector<vector<int> > &A) {
    int rows = A.size();
    int col = A[0].size();
    vector<vector<int> > visited;
    visited.resize(rows);
    for(int i=0;i<rows;i++)
        visited[i].resize(col,0);
    
    int hops_required = 0;
    int start_index,end_index;
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(A[i][j] == 0)
                hops_required++;
            else if(A[i][j] == 1){
                start_index = i;
                end_index = j;
            }
        }
    }
    hops_required++;
    // Don't forget this
    visited[start_index][end_index] = 1;
    int ans = countPaths(start_index,end_index,visited,A,hops_required,0);
    return ans;
}
