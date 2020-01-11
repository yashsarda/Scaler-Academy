/*
leetcode binary indexed tree
 */
class Solution {
public:
    int BIT[50005];
    int n;
    int getSum(int idx)
    {
        int sum = 0;
        while(idx > 0) {
            sum += BIT[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    void update(int idx, int val)
    {
        while(idx <= n) {
            BIT[idx] += val;
            idx += (idx & -idx);
        }
    }
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        memset(BIT, 0, sizeof(BIT));
        int answer = 0;
        for(int i=0;i<n;i++) {
            int position = upper_bound(temp.begin(), temp.end(), 2ll * nums[i]) - temp.begin();
            answer += i - getSum(position);
            position = upper_bound(temp.begin(),temp.end(), nums[i]) - temp.begin();
            update(position, 1);
        }
        return answer;
    }
};