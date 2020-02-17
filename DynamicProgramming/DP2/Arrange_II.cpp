/*
dp state
f(H, K, pos) :- minimum value of the sum of the product of white and black horses
If we are at position pos and we have K - 1 stables remaning, then in the current stable
we can store H - K horses so as to try all the possibilities

*/

int number_of_stables;
vector<vector<int> > dp;
int f(string A, int H, int K, int pos)
{
    if(K == 1) {
        int nw = 0;
        int nb = 0;
        for(int i=pos;i<A.size();i++) {
            nw += (A[i] == 'W');
            nb += (A[i] == 'B');
        }
        return  (dp[H][K] = nw * nb);
    }
    if(dp[H][K] != -1)
        return dp[H][K];
        
    int answer = INT_MAX;
    int number_of_white = 0;
    int number_of_black = 0;
    for(int i=pos;i < A.size() && i<= pos + (H - K);i++) {
        number_of_white += (A[i] == 'W');
        number_of_black += (A[i] == 'B');
        int temp_ans = (number_of_white * number_of_black) + f(A, H - (i - pos + 1), K - 1, i + 1);
        answer = min(answer,temp_ans);
    }
    return dp[H][K] = answer;
}
int Solution::arrange(string A, int B) {
    
    int n = A.size();
    if(B > n) {
        return -1;
    }
    dp.clear();
    dp.resize(n + 5);
    for(int i=0;i<=n+4;i++) {
        dp[i].resize(B + 5, -1);
    }
    number_of_stables = B;
    
    
    int answer = f(A, n, B, 0);
    return answer;
}
