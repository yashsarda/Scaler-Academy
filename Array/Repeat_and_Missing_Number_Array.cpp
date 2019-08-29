vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long sum = 0;
    long long sum_of_squares = 0;
    int n= A.size();
    for(int i=0;i<A.size();i++){
        sum = sum + A[i];
        sum_of_squares = sum_of_squares + (1ll * A[i] * A[i]);
    }
    long long as = 1ll*n*(n+1) / 2;
    long long ap = 1ll*n *(n+1)*(2*n+1) / 6;

    long long aminusb = as - sum;
    long long aplusb = (ap - sum_of_squares) / (as - sum);
    vector<int> t(2);
    t[1] = (aminusb + aplusb) / 2;
    t[0] = (aplusb - aminusb) / 2;
    return t;

}
