// One array for finding the next greater than or equal to element on the right hand side
// One array for finding the next smaller than or equal to element on the right hand side
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int len = A.size();
        vector<int> greater(len, -1), less(len, -1);
        set<pair<int,int> > s;
        s.insert({A[len - 1], len - 1});
        
        for(int i=len-2;i>=0;i--) {
            auto it = s.lower_bound({A[i], 0});
            if(it == s.end()) {
                greater[i] = -1;
                it--;
                less[i] = it -> second;
            }
            else if(A[i] == it -> first) {
                greater[i] = less[i] = it -> second;
            }
            else {
                greater[i] = it -> second;
                if(it == s.begin())
                    less[i] = -1;
                else {
                    it--;
                    it = s.lower_bound({it -> first, 0});
                    less[i] = it -> second;
                }
            }
            s.insert({A[i], i});
        }
        int answer = 0;
        vector<vector<int> > dp(len);
        for(int i=0;i<len;i++)
            dp[i].resize(2, -1);
        
        dp[len - 1][0] = dp[len - 1][1] = 1;
        
        for(int i=len-2;i>=0;i--) {
            if(greater[i] != -1 && dp[greater[i]][1] == 1)
                dp[i][0] = 1;
            if(less[i] != -1 && dp[less[i]][0] == 1)
                dp[i][1] = 1;
        }
        for(int i=0;i<len;i++)
            answer += dp[i][0] == 1;
        return answer;
    }
};