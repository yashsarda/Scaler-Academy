const int mod = 10000003;
int Solution::seats(string A) {
    int size = A.size();
    int a = 0;
    for(int i=0;i<size;i++){
        a |= (A[i] == 'x');
    }
    if(a == 0)
        return 0;
    int ans = INT_MAX;
    vector<int> findMedian;
    for(int i=0;i<size;i++){
        if(A[i] == 'x')
            findMedian.push_back(i);
    }
    // The optimal answer will be around the median, and the median is just the middle element
    int median = 0;
    int s = findMedian.size();
    if(s % 2 == 0)
        median = (findMedian[s / 2] + findMedian[s / 2 - 1]) / 2;
    else
        median = findMedian[s / 2];
    int counter = 0;
    int temp = 0;
    for(int j=median;j>=0;j--){
            if(A[j] == 'x')
                temp = (temp % mod + counter % mod) % mod;
            else
                counter = (counter % mod + 1) % mod;
    }
    counter = 0;
    for(int j=median+1;j<size;j++){
        if(A[j] == 'x')
            temp = (temp % mod + counter % mod) % mod;
        else
            counter = (counter % mod + 1) % mod;
    }
    ans = temp;
    return ans;
}
