const int mod = 1e9 + 7;
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> aux;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(A[k] != 0){
                    aux.push_back((A[i] + A[j]) * A[k]);
                }
            }
        }
    }
    sort(aux.begin(),aux.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                int x = (A[i] * A[j]) + A[k];
                int l = lower_bound(aux.begin(),aux.end(),x) - aux.begin();
                if(aux[l] == x){
                    int y = upper_bound(aux.begin(),aux.end(),x) - aux.begin();
                    y--;
                    ans = (ans + (y - l + 1)) % mod;
                }
            }
        }
    }
    return ans;
}
