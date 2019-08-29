const int mod = 1000000007;
#define ll long long int
int add_self(int a,int b)
{
  ll val = (ll)a + b;

    return (val+mod)%mod;
}
int sub_self(int a,int b)
{
    ll val = a-b+mod;
  return val%mod;
}
vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    int row = A.size();
    int column = A[0].size();
    int pref[row][column];
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            pref[i][j] = 0;

    for(int i=0;i<row;i++)
        pref[i][0] = A[i][0];
    //process rows
    for(int i=0;i<row;i++){
        for(int j=1;j<column;j++){
            pref[i][j] = add_self(pref[i][j-1],A[i][j]);
        }
    }
    //process column

    for(int j=0;j<column;j++){
        for(int i=1;i<row;i++){
            pref[i][j] = add_self(pref[i-1][j],pref[i][j]);
        }
    }
    // answer queries
    int si = B.size();
    vector<int> ans(si,0);
    for(int i=0;i<si;i++){
        int tli = B[i];
        int tlj = C[i];
        int bri = D[i];
        int brj = E[i];
        tli--;
        tlj--;
        bri--;
        brj--;

        //Formula = pref[bri][brj] - pref[bri][tlj-1] - pref[tli-1][brj] + pref[tli-1][tlj-1]
        ans[i] = pref[bri][brj];

        if(tlj-1 >= 0)
            ans[i] = sub_self(ans[i],pref[bri][tlj-1]);
        if(tli-1 >= 0)
            ans[i] = sub_self(ans[i],pref[tli-1][brj]);
        if(tli-1 >= 0 && tlj - 1 >= 0)
            ans[i] = add_self(ans[i],pref[tli-1][tlj-1]);
    }

    return ans;


}
