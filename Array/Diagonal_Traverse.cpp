class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        if(matrix.empty()) return answer;
        int rows = matrix.size();
        int cols = matrix[0].size();      
         
        for(int i=0;i<cols;i++) {
            int row = 0;
            int col = i;
            vector<int> temp;
            
            while(row < rows && col >= 0) {
                temp.push_back(matrix[row][col]);    
                row++;
                col--;
            }
            if(i % 2 == 0)
                reverse(temp.begin(),temp.end());
            for(auto element:temp)
                answer.push_back(element);
        }
        for(int i=1;i<rows;i++) {
            int row = i;
            int col = cols - 1;
             vector<int> temp;
            
            while(row < rows && col >= 0) {
                temp.push_back(matrix[row][col]);    
                row++;
                col--;
            }
            if((cols - 1) % 2 == 0 && i % 2 == 0)
                reverse(temp.begin(),temp.end());
            else if((cols - 1) % 2 && i % 2)
                 reverse(temp.begin(),temp.end());
            for(auto element:temp)
                answer.push_back(element);
        }
        return answer;
     }
};