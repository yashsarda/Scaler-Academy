// leetcode
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int> > matrix;
        matrix.resize(N);
        for(int i=0;i<N;i++)
            matrix[i].resize(N, 1);
        for(int i=0;i<mines.size();i++) {
            matrix[mines[i][0]][mines[i][1]] = 0;
        }
        int ans = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                ans |= matrix[i][j];
            }
        }
        if(ans == 0)
            return 0;
        int up[N][N], down[N][N], left[N][N], right[N][N];
        
        for(int i=0;i<N;i++) {
            left[i][0] = matrix[i][0];
            for(int j=1;j<N;j++) {
                if(matrix[i][j] == 0)
                    left[i][j] = 0;
                else
                    left[i][j] = matrix[i][j] + left[i][j - 1];
            }
        }
        
        for(int i=0;i<N;i++) {
            right[i][N - 1] = matrix[i][N - 1];
            for(int j=N - 2;j>=0;j--) {
                if(matrix[i][j] == 0)
                    right[i][j] = 0;
                else
                    right[i][j] = matrix[i][j] + right[i][j + 1];
            }
        }
        
        for(int i=0;i<N;i++) {
            up[0][i] = matrix[0][i];
            for(int j=1;j<N;j++) {
                if(matrix[j][i] == 0)
                    up[j][i] = 0;
                else
                    up[j][i] = matrix[j][i] + up[j - 1][i];
            }
        }
        for(int i=0;i<N;i++) {
            down[N - 1][i] = matrix[N - 1][i];
            for(int j=N - 2;j>=0;j--) {
                if(matrix[j][i] == 0)
                    down[j][i] = 0;
                else
                    down[j][i] = matrix[j][i] + down[j + 1][i];
            }
        }
        int answer = 0;
        for(int i=1;i<N - 1;i++) {
            for(int j=1;j<N - 1;j++) {
                if(matrix[i][j] == 0)
                    continue;
                int min_value = INT_MAX;
                min_value = min(min_value, up[i - 1][j]);
                min_value = min(min_value,down[i + 1][j]);
                min_value = min(min_value, left[i][j - 1]);      
                min_value = min(min_value, right[i][j + 1]);
                min_value = max(min_value + 1, 1);
                answer = max(answer, min_value);
            }
        }
        return (answer == 0 ? 1 : answer);
    }
};