// leetcode
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        
        for(int i=1;i<rows;i++) {
            for(int j=0;j<=i;j++) {
                int min_value = INT_MAX;
                if(j < i)
                    min_value = triangle[i - 1][j];
                if(j - 1 >= 0)
                    min_value = min(min_value, triangle[i - 1][j - 1]);
                triangle[i][j] += min_value;
            }
        }
        int answer = INT_MAX;
        for(int i=0;i<rows;i++) {
            answer = min(answer, triangle[rows - 1][i]);
        }
        return answer;
    }
};