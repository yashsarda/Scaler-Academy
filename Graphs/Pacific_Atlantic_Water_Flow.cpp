/**

1st row and 1st column are completely surrounded by pacific
last row and last column are surrounded by atlantic

So if we have to find a path from some (i,j) to either end of pacific and atlantic
we can reverse the problem
We can start from pacific or atlantic and check all the nodes we can reach
If a node is reachable by both pacific and atlantic then we push it into answer

*/
class Solution {
public:
    int rows, columns;
    bool safe(int x,int y)
    {
        return !(x < 0 || x >= rows || y < 0 || y >= columns);
    }
    void bfs(queue<pair<int,int> >& q, vector<vector<bool> >& visited, vector<vector<int> >& matrix)
    {
        while(!q.empty()) {
            pair<int,int> node = q.front();
            q.pop();
            int x[] = {1,-1,0,0};
            int y[] = {0,0,1,-1};
            
            for(int i=0;i<4;i++) {
                int xd = x[i] + node.first;
                int yd = y[i] + node.second;
                
                if(safe(xd,yd) && !visited[xd][yd] && matrix[xd][yd] >= matrix[node.first][node.second]) {
                    visited[xd][yd] = true;
                    q.push({xd,yd});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return matrix;
        rows = matrix.size();
        columns = matrix[0].size();
        
        vector<vector<bool> > pacific(rows + 1, vector<bool>(columns + 1, false));
        vector<vector<bool> > atlantic(rows + 1, vector<bool>(columns + 1, false));
        
        queue<pair<int,int> > qp, qa;
        for(int i=0;i<columns;i++) {
            pacific[0][i] = atlantic[rows - 1][i] = true;
            qp.push({0, i});
            qa.push({rows - 1, i});
        }
        
        for(int i=0;i<rows;i++) {
            pacific[i][0] = atlantic[i][columns - 1] = true;
            qp.push({i, 0});
            qa.push({i, columns - 1});
        }
        
        bfs(qp, pacific, matrix);
        bfs(qa, atlantic, matrix);
        
        vector<vector<int> > answer;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<columns;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    answer.push_back({i,j});
                }
            }
        }
        return answer;
    }
};