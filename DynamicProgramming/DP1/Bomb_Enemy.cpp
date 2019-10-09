class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int rows = grid.size();
        int col = grid[0].size();
        if(!rows || !col) return 0;
        
        int pre[rows][col];
        memset(pre,0,sizeof(pre));
        int answer[rows][col];
        memset(answer,0,sizeof(answer));     
        int final_ans = 0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == 'W')
                    pre[i][j] = 0;
                else if(grid[i][j] == '0') {
                    pre[i][j] = (j - 1 >= 0 ? pre[i][j - 1] : 0);
                    answer[i][j] = pre[i][j];
                }
                else {
                    pre[i][j] = (j - 1 >= 0 ? pre[i][j - 1] + 1 : 1);
                }
            }
        }
        memset(pre, 0, sizeof(pre));
        
        for(int i=0;i<rows;i++) {
            for(int j=col-1;j>=0;j--) {
                if(grid[i][j] == 'W') 
                    pre[i][j] = 0;
                else if(grid[i][j] == '0') {
                    pre[i][j] = (j + 1 < col ? pre[i][j + 1] : 0);
                    answer[i][j] += pre[i][j];
                }
                else {
                    pre[i][j] = (j + 1 < col ? pre[i][j + 1] + 1 : 1);
                }
            }
        }
      
                
        memset(pre,0,sizeof(pre));
        
        for(int j=0;j<col;j++) {
            for(int i=0;i<rows;i++) {
                if(grid[i][j] == 'W')
                    pre[i][j] = 0;
                else if(grid[i][j] == '0'){
                    pre[i][j] = (i - 1 >= 0 ? pre[i - 1][j] : 0);
                    answer[i][j] += pre[i][j];
                }
                else {
                    pre[i][j] = (i - 1 >= 0 ? pre[i - 1][j] + 1 : 1);
                }
            }
        }
        
        memset(pre,0,sizeof(pre));
        
        for(int j=0;j<col;j++) {
            for(int i=rows-1;i>=0;i--) {
                if(grid[i][j] =='W')
                    pre[i][j] = 0;
                else if(grid[i][j] == '0') {
                    pre[i][j] = (i + 1 < rows ? pre[i + 1][j] : 0);
                    answer[i][j] += pre[i][j];
                }
                else {
                    pre[i][j] = (i + 1 < rows ? pre[i + 1][j] + 1: 1);
                }
            }
        }

        for(int i=0;i<rows;i++)
            for(int j=0;j<col;j++) {
                if(grid[i][j] == '0')
                    final_ans = max(final_ans, answer[i][j]);
            }
        return final_ans;
    }
};