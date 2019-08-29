struct t
{
    int f;
    int s;
};
bool cmp(struct t a,struct t b)
{
    if(a.f == b.f)
        return a.s > b.s;
    return a.f < b.f;
}
int Solution::solve(vector<vector<int> > &A) {
    int row = A.size();
    int col = 2;
    vector<struct t> v(2 * row);
    // start = 0, end = 1;
    int k = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<2;j++){
            v[k].f = A[i][j];
            v[k].s = j;
            k++;
        }
    }
  
    sort(v.begin(),v.end(),cmp);
    int ans = 0;
    int temp = 0;
    for(int i=0;i<v.size();i++){
        if(v[i].s == 0){
            ++temp;
            ans = max(ans,temp);
        }
        else
            --temp;
    }
    return ans;
}
