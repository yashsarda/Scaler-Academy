// looked up on geeks for geeks
// Similar to matrix chain multiplication
typedef long long ll;
vector<vector<int> > parent;                // to construct the sequence back
vector<vector<ll> > dp;                    // to store the minimum answer
vector<int> cuts;                           // to find length of the cut
ll find_ans(int i,int j)
{
    if(i + 1 >= j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    ll ans = LONG_MAX;
    int best_index = -1;
    
    for(int k=i+1;k<j;k++){
        ll t = find_ans(i,k) + find_ans(k,j) + cuts[j] - cuts[i];
        
        if(t < ans){
            ans = t;
            best_index = k;
        }
    }
    parent[i][j] = best_index;
    dp[i][j] = ans;
    return ans;
}
// Bottom up
void find_ans_bu()
{
    int n = cuts.size();
    for(int i=0;i<=n-1;i++)
        dp[i][i + 1] = 0;
    
    for(int size=3;size<=n;size++){
        for(int l=0;l+size-1<n;l++){
            int r = l + size - 1;
            int best_index = -1;
            for(int k=l+1;k<r;k++){
                ll t = dp[l][k] + dp[k][r] + cuts[r] - cuts[l];
                if(t < dp[l][r]){
                    dp[l][r] = t;
                    parent[l][r] = k;
                }
            }
        }
    }
}
void construct_solution(vector<int>& ans,int i,int j)
{
    if(i + 1 >= j)  return;
    ans.push_back(cuts[parent[i][j]]);
    
    construct_solution(ans,i,parent[i][j]);
    construct_solution(ans,parent[i][j],j);
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    int size = B.size();
    cuts.clear();
    dp.clear();
    parent.clear();
    for(int i=0;i<size;i++)
        cuts.push_back(B[i]);
    
    cuts.push_back(A);
    cuts.insert(cuts.begin(),0);
    
    int n = cuts.size();
    
    dp.resize(n + 1);
    parent.resize(n + 1);
    for(int i=0;i<=n;i++){
        parent[i].resize(n + 1);
        dp[i].resize(n + 1, LONG_MAX);
    }
    
  //  ll x = find_ans(0,n - 1);
    find_ans_bu();
    vector<int> ans;
   construct_solution(ans,0,n-1);
    return ans;
}
