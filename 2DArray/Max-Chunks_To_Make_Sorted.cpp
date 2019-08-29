int Solution::solve(vector<int> &A) {
    int n = A.size();

    int chunks = 0;

    int max_element = INT_MIN;
    for(int i=0;i<n;i++){
        max_element = max(max_element,A[i]);
        if(max_element == i)
            chunks++;
    }
    return chunks;
}
