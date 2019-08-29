int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    int n = A.size();
    int i = 0,j = n - 1;
    while(i < j){
        int sum = A[i] + A[j];
        if(sum < B)
            i++;
        else if(sum > B)
            j--;
        else{
            int e_i = A[i];
            int e_j = A[j];
            if(A[i] == A[j]){
                int l = j - i + 1;
                ans += (l *(l - 1)) >> 1;
                break;
            }
            else{
                int cnt1 = 0;
                int c_i = i;
                while(A[c_i] == A[i]){
                    cnt1++;
                    c_i++;
                }
                int cnt2 = 0;
                int c_j = j;
                while(A[c_j] == A[j]){
                    cnt2++;
                    c_j--;
                }
                i = c_i;
                j = c_j;
                ans += cnt1 * cnt2;
            }
        }
    }
    return ans;
}
