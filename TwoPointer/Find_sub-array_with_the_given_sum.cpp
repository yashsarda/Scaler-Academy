vector<int> Solution::solve(vector<int> &A, int B) {
    int i=0,j=0;
    vector<int> ans;
    int n = A.size();
    int sum = A[i];
    while(i < n && j < n){
        if(sum == B){
            for(int k=i;k<=j;k++)
                ans.push_back(A[k]);
            return ans;
        }
        else if(sum < B){
            j++;
            sum += A[j];
        }
        else{
            sum -= A[i];
            i++;
        }
    }
    if(ans.size() == 0){
        ans.push_back(-1);
        return ans;
    }
}
