//Basically the idea is to keep a left and right pointer
// Why is that ?
// Let's suppose height of left bar is less than the height of right bar
// then initially the area = left_height * (right - left)
// if we decrease right the area is going to decrease since the height is constant but the base is smaller
// hence we increase the left pointer
// Similarly if height of right bar is less than height of left bar we increase the right pointer
// The time complexity = O(n)
int Solution::maxArea(vector<int> &A) {
    int area = 0;
    int left = 0;
    int right = A.size() - 1;

    while(right > left) {
        int height_left = A[left];
        int height_right = A[right];
        int temp_ans = 0;
        temp_ans = (right - left) * min(height_left,height_right);
        if(temp_ans > area)
            area = temp_ans;
        if(height_left < height_right)
            left++;
        else
            right--;
    }
    return area;


}
