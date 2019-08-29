const int N = 1000006;
vector<int> prime(N);
vector<int> spf(N);
void sieve()
{
    prime[0] = 0;
    prime[1] = 0;
    for(int i=2;i*i<=N;i++){
        if(prime[i] == 1){
            for(int j=i*i;j<=N;j+=i){
                prime[j] = 0;
                spf[j] = i;
            }
        }
    }
}
int c_d(int a)
{
    map<int,int> m;
    int c = 1;
    if(a == 1)
        return c;
    while(spf[a] != -1){
        m[spf[a]]++;
        a = a / spf[a];
    }
    m[a]++;

    for(auto i=m.begin();i!=m.end();i++){
        int value = i->second;
        c = c * (value + 1);
    }
    return c;
}
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    fill(prime.begin(),prime.end(),1);
    fill(spf.begin(),spf.end(),-1);
    sieve();
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int c = c_d(A[i]);
        ans[i] = c;
    }
    return ans;


}
