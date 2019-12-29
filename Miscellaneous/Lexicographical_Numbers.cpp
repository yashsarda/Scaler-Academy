// Leetcode
// DFS
// 10 11 12 ..... 19
// 100 101 102..... 109
class Solution {
public:
    void dfs(int start, int end, vector<int>& answer)
    {
        if(start > end) return;
        
        answer.push_back(start);
        
        for(int i=0;i<=9;i++) {
            dfs(start * 10 + i, end, answer);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        for(int i=1;i<=9;i++)
            dfs(i,n,answer);
        return answer;
    }
};