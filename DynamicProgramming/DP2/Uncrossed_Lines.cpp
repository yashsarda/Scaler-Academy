/**
 * Absolutely fucking beautifull
 */
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();
        
        int dp[lenA + 5][lenB + 5];
        for(int i=0;i<lenA + 5;i++) {
            for(int j=0;j<lenB + 5;j++) {
                dp[i][j] = 0;
            }
        }
        
        for(int i=1;i<=lenA;i++) {
            for(int j=1;j<=lenB;j++) {
                if(A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int max_len = 0;
        for(int i=1;i<=lenA;i++) {
            for(int j=1;j<=lenB;j++) {
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};