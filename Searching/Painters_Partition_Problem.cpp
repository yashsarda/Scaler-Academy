typedef long long ll;
const int mod = 10000003;
bool isPossible(vector<int>& C,int K,ll time)
{
    int number = 1;
    ll sum = 0;
    for(int i=0;i<C.size();i++){
        if(C[i] > time)
            return false;
        if((sum + C[i])> time){
            number++;
            sum = C[i];
            if(number > K)
                return false;
        }
        else
            sum = (sum + C[i]);
    }
    return true;
}
ll s(vector<int>& C)
{
    ll ans = 0;
    for(int i=0;i<C.size();i++)
        ans = ans + C[i];
    return ans;
}
int Solution::paint(int A, int B, vector<int> &C) {
    ll lb = *max_element(C.begin(),C.end());
    ll ub = s(C);
    ll ans;
    if(C.size() <= A){
        ans = lb;
        return (ans * B) % mod;
    }
    while(lb <= ub){
        ll mid = (lb + (ub - lb) / 2);
        if(isPossible(C,A,mid)){
            ans = mid;
            ub = mid - 1;
        }
        else
            lb = mid + 1;
    }
    return (ans * 1ll * B) % mod;
    
}
