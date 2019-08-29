vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int left = -1;
    int right = n-1;
    vector<int> ans;

    //logic for left side
    for(int i=1;i<n;i++){
        if(A[i] < A[i-1]){
            left = i;
            break;
        }
    }
    if(left == -1){
        ans.push_back(-1);
        return ans;
    }

    int advance_left = left - 1;
    while(A[advance_left] > A[left] && advance_left >= 0)
        advance_left--;

    left = advance_left + 1;

    //logic for right side
    for(int i=n-2;i>=0;i--){
        if(A[i] > A[i+1]){
            right = i;
            break;
        }
    }

    int advance_right = right + 1;
    while(A[advance_right] < A[right] && advance_right <= n-1)
        advance_right++;

    right = advance_right - 1;

    int min_e = *min_element(A.begin() + left,A.begin() + right + 1);
    int max_e = *max_element(A.begin() + left,A.begin() + right + 1);

    advance_left = left - 1;
    while(A[advance_left] > min_e && advance_left >= 0)
        advance_left--;

    left = advance_left + 1;

    advance_right = right + 1;
    while(A[advance_right] < max_e && advance_right <= n-1)
        advance_right++;

    right = advance_right - 1;

    ans.push_back(left);
    ans.push_back(right);

    return ans;

}
