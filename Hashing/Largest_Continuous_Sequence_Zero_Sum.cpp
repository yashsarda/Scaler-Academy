typedef long long ll;
vector<int> Solution::lszero(vector<int> &A) {
    vector<int> ans;
    int start = -1;
    int en = -1;
    ll sum = 0;
    map<ll,int> m;
    m[0] = -1;
    int n = A.size();
    int max_length = -1;
    for(int i=0;i<n;i++){
        sum += A[i];
        if(m.find(sum) != m.end()){
            int s = m[sum];
            int len = i - s;
            if(len > max_length){
                max_length = len;
                start = s + 1;
                en = i;
            }
        }
        else
            m[sum] = i;
    }
    if(start == -1 && en == -1)
        return ans;
    for(int i=start;i<=en;i++)
        ans.push_back(A[i]);
    return ans;
    
}
