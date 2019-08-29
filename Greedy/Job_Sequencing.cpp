#define f first
#define s second
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.s == b.s)
        return a.f > b.f;
    return a.s > b.s;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    int asize = A.size();
    int bsize = B.size();
    if(asize == 1)
        return B[0];
    
    vector<pair<int,int> > v(asize);
    for(int i=0;i<asize;i++){
        if(A[i] > asize){
            A[i] = asize;
        }
        v[i].f = A[i];
        v[i].s = B[i];
    }
    sort(v.begin(),v.end(),cmp);
    long long ans = 0;
    vector<bool> used(asize + 1,false);
    for(int i=0;i<asize;i++){
        int deadline = v[i].f;
        while(used[deadline]){
            deadline--;
            if(deadline < 0)
                break;
        }
        if(deadline > 0 && !used[deadline]){
            used[deadline] = true;
            ans += v[i].s;
        }
    }
    return ans;
}
