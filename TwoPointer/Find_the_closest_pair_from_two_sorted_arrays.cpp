vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n1 = A.size();
    int n2 = B.size();
    int i = 0;
    int j = n2-1;
    int diff = INT_MAX;
    vector<int> ans;
    int a1 = INT_MAX,a2 = INT_MAX;
    while(i < n1 && j >= 0){
        int cal = abs(A[i] + B[j] - C);
        if(cal <= diff){
            if(cal < diff){
                a1 = i;
                a2 = j;
            }
            else if(cal == diff){
                if(i <= a1){
                    a1 = i;
                    if(j < a2)
                        a2 = j;
                }
            }
            diff = cal;
        }
        // Here we have to decrease j since if we increase i the sum is still going to increase
        if(A[i] + B[j] > C)
            j--;
        else
            i++;

    }
    ans.push_back(A[a1]);
    ans.push_back(B[a2]);
    return ans;


}
