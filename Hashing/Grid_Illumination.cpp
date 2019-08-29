vector<int> Solution::solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
    int n = B.size();
    int m = C.size();
    unordered_map<int,int> rowMap;
    unordered_map<int,int> columnMap;
    unordered_map<int,int> majorMap;
    unordered_map<int,int> minorMap;
    set<pair<int,int> > lamp;
    
    for(int i=0;i<n;i++){
        int x = B[i][0];
        int y = B[i][1];
        if(lamp.find({x,y}) == lamp.end()){
            lamp.insert({x,y});
            rowMap[x]++;
            columnMap[y]++;
            majorMap[x + y]++;
            minorMap[x - y]++;
        }
    }
    vector<int> D(m,0);
    for(int i=0;i<m;i++){
        int x = C[i][0];
        int y = C[i][1];
        if(rowMap[x] > 0 || columnMap[y] > 0 || majorMap[x + y] > 0 || minorMap[x - y] > 0)
            D[i] = 1;
        else
            D[i] = 0;
         int dx[] = {0,0,0,-1,1,-1,-1,1,1};
         int dy[] = {0,-1,1,0,0,-1,1,-1,1};
        for(int j=0;j<9;j++){
            int xd = x + dx[j];
            int yd = y + dy[j];
            if(lamp.find({xd,yd}) != lamp.end()){
                 lamp.erase({xd,yd});
                 rowMap[xd]--;
                 columnMap[yd]--;
                 majorMap[xd + yd]--;
                 minorMap[xd - yd]--;
                }
            }
    }
    return D;
}
