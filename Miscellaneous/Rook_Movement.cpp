bool isSafe(int x,int y,int rows,int col)
{
    return !(x >= rows || x < 0 || y >= col || y < 0);
}
int Solution::solve(int A, int B, int C, int D, vector<string> &E) {
    A--;B--;C--;D--;
    
    int rows = E.size();
    int col = E[0].size();
    
    if(rows == 1 && col == 1)
        return 0;
    
    if(A == C && B == D)
        return 0;
        
    // visited array stores the the locations which are visited
    vector<vector<bool> >visited;
    visited.resize(rows);
    for(int i=0;i<rows;i++)
        visited[i].resize(col, false);
    
    // distance array stores the distance of locations and direction keep track of what is cuurent
    // direction. For column = 2, row = 1
    vector<vector<int> > distance,direction;
    distance.resize(rows);
    for(int i=0;i<rows;i++)
        distance[i].resize(col, INT_MAX);
    
    direction.resize(rows);
    for(int i=0;i<rows;i++)
        direction[i].resize(col);
        
    queue<pair<int,int> > q;
    q.push({A,B});
    
    visited[A][B] = true;
    distance[A][B] = 0;
    // normal BFS
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int xco = p.first;
        int yco = p.second;
        int dist = distance[xco][yco];
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0}; 
        for(int i=0;i<4;i++){
            int xd = x[i] + xco;
            int yd = y[i] + yco;
            // Go to each direction as much as you can
            while(isSafe(xd,yd,rows,col) && E[xd][yd] == '0'){
                if(!visited[xd][yd]){
                    visited[xd][yd] = true;
                    if(xco == A && yco == B){
                        distance[xd][yd] = dist + 1;
                        if(xco == xd)
                            direction[xd][yd] = 1;
                        else
                            direction[xd][yd] = 2;
                    }
                    else {
                        if(direction[xco][yco] == 1 && xd != xco){
                            direction[xd][yd] = 2;
                            distance[xd][yd] = dist + 1;
                        }
                        else if(direction[xco][yco] == 1){
                            direction[xd][yd] = 1;
                            distance[xd][yd] = dist;
                        }
                        else if(direction[xco][yco] == 2 && yd != yco){
                            direction[xd][yd] = 1;
                            distance[xd][yd] = dist + 1;
                        }
                        else{
                            direction[xd][yd] = 2;
                            distance[xd][yd] = dist;
                        }
                    }
                    if(xd == C && yd == D)
                        return distance[xd][yd];
                    q.push({xd,yd});
                }
                xd = xd + x[i];
                yd = yd + y[i];
            }
        }
    }
    return -1;
}
