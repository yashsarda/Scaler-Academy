int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    if(n == 1)
        return 0;
    int left = 0;
    int right = n-1;
    int ans = 0;
    while(left < right){
        int base = right - left;
        int height = min(A[left],A[right]);
        int area = base * height;
        if(area > ans)
            ans = area;
        if(A[left] < A[right])
            left++;
        else
            right--;
    }
    return ans;

}
