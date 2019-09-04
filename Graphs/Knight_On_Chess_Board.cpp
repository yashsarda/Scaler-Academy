int rows, col;
bool isSafe(int x, int y)
{
    return !(x < 0 || x >= rows || y < 0 || y >= col);
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    rows = A;
    col = B;
    
    // Perform a BFS from the source point
    // Keep a distance array, which stores the distance of a vertex from the source node
    vector<vector<int> > visited, distance;
    visited.resize(rows);
    distance.resize(rows);
    for(int i=0;i<rows;i++){
        visited[i].resize(col, false);
        distance[i].resize(col, false);
    }
    
    C--; D--; E--; F--;
    queue<pair<int,int> > q;
    q.push({C,D});
    visited[C][D] = true;
    distance[C][D] = 0;
    if(E == C && F == D)
        return 0;
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        int xco = node.first;
        int yco = node.second;
        int x[] = {-2,-2,-1,-1,1,1,2,2};
        int y[] = {-1,1,-2,2,-2,2,-1,1};
        
        for(int i=0;i<8;i++){
            int xd = xco + x[i];
            int yd = yco + y[i];
            
            if(isSafe(xd, yd) && !visited[xd][yd]){
                distance[xd][yd] = distance[xco][yco] + 1;
                if(xd == E && yd == F)
                    return distance[xd][yd];
                q.push({xd,yd});
                visited[xd][yd] = true;
            }
        }
    }
    return -1;
    
    
}
