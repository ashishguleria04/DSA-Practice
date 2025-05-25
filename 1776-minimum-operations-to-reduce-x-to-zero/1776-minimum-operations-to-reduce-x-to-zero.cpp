class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        if (target < 0) return -1; // x is greater than total sum — impossible
        
        int n = nums.size();
        int maxLen = -1, currSum = 0, left = 0;

        for (int right = 0; right < n; ++right) {
            currSum += nums[right];

            while (currSum > target && left <= right) {
                currSum -= nums[left++];
            }

            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return (maxLen == -1) ? -1 : n - maxLen;
    }
};