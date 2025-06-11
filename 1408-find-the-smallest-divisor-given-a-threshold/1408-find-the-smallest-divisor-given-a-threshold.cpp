class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = (left + right) / 2;
            int total = 0;

            for (int num : nums) {
                total += (num + mid - 1) / mid;  
            }

            if (total > threshold) {
                left = mid + 1; 
            } else {
                right = mid; 
            }
        }

        return left;
    }
};