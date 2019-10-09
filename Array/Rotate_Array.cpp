class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len <= 1)
            return;
        
        if(k % len == 0)
            return;
        // O(1) space but O(n*k) time
        /* int start = len - k % len;
        for(int i=start;i<len;i++) {
            int j = i - start;
            int k = i - 1;
            while(k >= j) {
                swap(nums[k], nums[k + 1]);
                k--;
            }
        }*/
        // O(1) space and O(n) runtime
        reverse(nums.begin(), nums.end());
        k = k % len;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};