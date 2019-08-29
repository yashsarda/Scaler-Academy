int Solution::maxSubArray(const vector<int> &A) {

    int max_sum = INT_MIN;
    int end_here,start_here,temp = 0;
    for(int i=0;i<A.size();i++){
        end_here = temp + A[i];
        start_here = A[i];

        if(end_here > start_here){
            temp = end_here;
        }
        else{
            temp = start_here;
        }
        if(temp > max_sum)
            max_sum = temp;
    }
    return max_sum;
}
