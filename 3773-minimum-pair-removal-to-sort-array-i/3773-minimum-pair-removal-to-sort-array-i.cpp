class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int operations = 0;
        
        while (!isNonDecreasing(nums)) {
           
            int minSum = std::numeric_limits<int>::max(); 
            int minSumIndex = -1; 

            for (int i = 0; i < nums.size() - 1; ++i) {
                int currentSum = nums[i] + nums[i+1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    minSumIndex = i;
                }
            }

            
            nums[minSumIndex] = minSum; 
            nums.erase(nums.begin() + minSumIndex + 1); 
            operations++;
        }
        
        return operations;
    }

private:
    bool isNonDecreasing(const std::vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) {
                return false; 
            }
        }
        return true; 
    }
};