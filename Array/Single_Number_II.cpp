//Just look at the binary representation of number
int Solution::singleNumber(const vector<int> &A) {
    int result = 0;
    for(int i=0;i<32;i++){
        int power_of_2 = 1 << i;
        int cnt = 0;
        for(int j=0;j<A.size();j++){
            if(A[j] & power_of_2)
                cnt++;
        }
        if(cnt % 3)
            result = result | power_of_2;
    }
    return result;
}
