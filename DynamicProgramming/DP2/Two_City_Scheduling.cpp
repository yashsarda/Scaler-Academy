class Solution {
public:
    int rows, cols;
    int dp[105][105][105];
    int minCost(vector<vector<int> >& costs, int index, int A, int B)
    {
        if(A == 0 && B == 0) {
            dp[index][A][B] = 0;
            return 0;
        }
        
        if(dp[index][A][B] != -1)
            return dp[index][A][B];
        
        int answer = INT_MAX;
        
       if(A != 0 && B != 0) {
           int cost1 = costs[index][0] + minCost(costs, index + 1, A - 1, B);
           int cost2 = costs[index][1] + minCost(costs, index + 1, A, B - 1);
           answer = min(answer, min(cost1, cost2));
       }
        if(A != 0) {
            int cost = costs[index][0] + minCost(costs, index + 1, A - 1, B);
            answer = min(answer, cost);
        }
        
        if(B != 0) {
            int cost = costs[index][1] + minCost(costs, index + 1, A, B - 1);
            answer = min(answer, cost);
        }
        dp[index][A][B] = answer;
        return answer;
        
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        rows = costs.size();
        cols = costs[0].size();
        
        for(int i=0;i<105;i++) {
            for(int j=0;j<105;j++) {
                for(int k=0;k<105;k++) {
                    dp[i][j][k] = -1;
                }
            }
         }
        
        int answer = minCost(costs, 0, rows / 2, rows / 2);
        return answer;
    }
};