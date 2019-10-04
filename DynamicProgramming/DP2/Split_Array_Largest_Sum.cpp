// leetcode problem
class Solution {
public:
    vector<long long> pref;
    vector<vector<int> > dp;
    int getSum(int index,vector<int>& nums)
    {
        return (pref[nums.size() - 1] - (index > 0 ? pref[index - 1] : 0));
    }
    int recur(int index, int splits,vector<int>& nums)
    {
        if(splits == 1) {
            int sum = getSum(index,nums);
            dp[index][1] = sum;
            return sum;
        }
        if(dp[index][splits] != -1)
            return dp[index][splits];
        int endpos = nums.size() - splits;
        int sum = 0;
        long long answer =  LONG_MAX;
        for(int i=index;i<=endpos;i++){
            sum += nums[i];
            answer = min(answer, (long long)max(sum, recur(i + 1, splits - 1, nums)));
        }
        return dp[index][splits] = answer;
    }
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        if(len == 1)
            return nums[0];
        int answer = 0;
        dp.resize(len + 5);
        for(int i=0;i<len;i++)
            dp[i].resize(m + 5, -1);
        pref.clear();
        pref.resize(len,0);
        pref[0] = nums[0];
        for(int i=1;i<len;i++)
            pref[i] = nums[i] + pref[i - 1];
        answer = recur(0,m,nums);
        return answer;
    }
};