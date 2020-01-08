// leetcode
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return 0;
        int rows = matrix.size();
        int columns = matrix[0].size();
        // prefix array stores the sum from (0,0) to (i,j)
        int prefix[rows][columns];
        for(int i=0;i<rows;i++) {
            for(int j=0;j<columns;j++) {
                prefix[i][j] = 0;
            }
        }
        
        for(int i=0;i<rows;i++) {
            prefix[i][0] = matrix[i][0];
            for(int j=1;j<columns;j++) {
                prefix[i][j] = prefix[i][j - 1] + matrix[i][j];
            }
        }
        
        for(int i=1;i<rows;i++) {
            for(int j=0;j<columns;j++) {
                prefix[i][j] += prefix[i - 1][j];
            }
        }
        
        
        int answer = 0;
        // Consider every submatrix
        for(int r1=0;r1<rows;r1++) {
            for(int r2=r1;r2<rows;r2++) {
                
                unordered_map<int,int> counter;
                // Logic is same as the number of subarrays with sun equals K
                int sum = 0;
                for(int c=0;c<columns;c++) {
                    // this gives the sum for (0,0) to (r2,c)
                    sum = prefix[r2][c];
                    if(r1 != 0)
                        sum -= prefix[r1 - 1][c];
                    if(sum == target)
                        answer++;
                    answer += counter[sum - target];
                    counter[sum]++;
                }
            }
        }
        return answer;
    }
};