// leetcode
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
            return 0;
        int rows = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        vector<vector<long long> > dp;
        dp.resize(rows);
        for(int i=0;i<rows;i++)
            dp[i].resize(col);
        dp[0][0] = 1;
        for(int i=1;i<col;i++){
            if(obstacleGrid[0][i] == 1)
                dp[0][i] = 0;
            else
                dp[0][i] = dp[0][i - 1];
        }
        for(int i=1;i<rows;i++){
            if(obstacleGrid[i][0] == 1)
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i - 1][0];
        }
        
        for(int i=1;i<rows;i++) {
            for(int j=1;j<col;j++) {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + 0ll + dp[i][j - 1];
            }
        }
        return dp[rows - 1][col - 1];
    }
};