#define inf 90000000000000000ll
int convert_to_int(string x)
{
    int answer = 0;
    int p2 = 1;
    for(int i=9;i>=0;i--) {
        answer += p2 * (x[i] - '0');
        p2 *= 2;
    }
    return answer;
}
int Solution::solve(vector<int> &A, vector<string> &B) {
    int lenA = A.size();
    int lenB = B.size();
    vector<int> values(lenB);
    for(int i=0;i<lenB;i++) {
        values[i] = convert_to_int(B[i]);
    }
    long long dp[1 << 10 + 5];
    for(int i=0;i<(1 << 10) + 5;i++)
        dp[i] = inf;
    dp[0] = 0;
    for(int mask=0;mask<(1 << 10);mask++) {
        for(int j=0;j<lenA;j++) {
            dp[mask | values[j]] = min(dp[mask | values[j]], dp[mask] + A[j]); 
        }
    }
    vector<vector<long long> > no_of_bits(15);
    for(int i=1;i<(1 << 10);i++) {
        int number = 0;
        for(int j=31;j>=0;j--) {
            number += ((i & (1 << j)) ? 1 : 0);
        }
        no_of_bits[number].push_back(i);
    }
    long long answer = INT_MAX;
    for(int i=10;i>=1;i--) {
        int si = no_of_bits[i].size();
        if(si > 0) {
            for(int j=0;j<si;j++) {
                answer = min(answer, dp[no_of_bits[i][j]]);
            }
            break;
        }
    }
    return answer;
    
}
