const int mod = 1e9 + 7;
int Solution::solve(vector<int> &A) {
    int asize = A.size();
    if(asize <= 2)
        return -1;
    
    long long max_product = 0;
    set<int> s;
    vector<int> left(asize),right(asize);
    left[0] = 0;
    for(int i=1;i<asize;i++){
        s.insert(A[i-1]);
        auto it = s.lower_bound(A[i] - 1);
        if(it == s.end()){
            it--;
            //cout << A[i] << ' ' << *it << '\n';
            left[i] = *it;
        }
        else if(*it == A[i] - 1)
            left[i] = A[i] - 1;     
        else{
            if(it == s.begin())
                left[i] = 0;
            else{
                it--;
                left[i] = *it;
            }
        }
    }
    s.clear();
    
    right[asize - 1] = 0;
    
    for(int i=asize-2;i>=0;i--){
        s.insert(A[i + 1]);
        auto it = s.lower_bound(A[i] + 1);
        if(it == s.end()){
            right[i] = 0;
        }
        else {
            it = s.end();
            it--;
            right[i] = *it;
        }
    }
    for(int i=0;i<asize;i++){
        long long temp = (1ll * left[i] * right[i]);
        temp = (temp * 1ll * A[i]);
        max_product=  max(max_product, temp);
    }
    if(max_product == 0)
        return -1;
    return max_product % mod;
    
}
