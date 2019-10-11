const int N = 705;
int dp[N][N];
int ways(string A,string B, int i, int j)
{
    if(j == -1) return 1;
    
    if(i == -1) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    int number = 0;
    if(A[i] == B[j])
        number = ways(A,B,i - 1, j) + ways(A,B, i - 1, j - 1);
    else
        number = ways(A,B,i - 1,j);
        
    return dp[i][j] = number;
}
int Solution::numDistinct(string A, string B) {
    int len1 = A.size();
    int len2 = B.size();
    
    if(len1 < len2)
        return 0;
    if(len1 == len2)
        return A == B;
    for(int i=0;i<705;i++) {
        for(int j=0;j<705;j++) {
            dp[i][j] = -1;
        }
     }
    int answer = ways(A,B,len1 - 1, len2 - 1);
    return answer;
}
