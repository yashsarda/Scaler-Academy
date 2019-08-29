//Just change it for both upper case and lower case
const int N = 55;
const int m = 1000003;
int Solution::findRank(string A) {
    int priority = 1;
    string given = A;
    sort(given.begin(),given.end());
    unordered_map<char,int> umap;
    for(int i=0;i<A.size();i++){
        umap[given[i]] = priority++;
    }
    int fact[N];
    fact[0] = 1;
    for(int i=1;i<N;i++)
        fact[i] = (1ll * fact[i-1] * i) %m;

    int ans = 0;
    int n = A.size();
    for(int i=0;i<n;i++){
        int pr = umap[A[i]];
        int cnt = 0;
        for(int j=i+1;j<n;j++){
            if(umap[A[j]] < pr)
                cnt++;
        }
        ans += (1ll * cnt * fact[n- i - 1]) %m;
    }
    ans = (ans + 1) % m;
    return ans;

}
