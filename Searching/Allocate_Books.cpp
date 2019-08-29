typedef long long ll;
bool isPossible(vector<int>& A,int B,int max_pages)
{
    int number = 1;
    int sum = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] > max_pages)
            return false;
        if(A[i] + sum > max_pages){
            number++;
            sum = A[i];
            if(number > B)
                return false;
        }
        else
            sum += A[i];
    }
    return true;
    
    
}
int Solution::books(vector<int> &A, int B) {
    ll lb = *max_element(A.begin(),A.end());
    ll ub = accumulate(A.begin(),A.end(),0LL);
    if(A.size() < B)
        return -1;
    ll ans = -1;
    while(lb <= ub){
        ll mid = lb + (ub - lb) / 2;
        if(isPossible(A,B,mid)){
            ans = mid;
            ub = mid - 1;
        }
        else
            lb = mid + 1;
    }
    return ans;
    
}
