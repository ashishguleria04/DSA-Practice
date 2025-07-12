class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> countMap;
        countMap[0] = -1;

        int maxLen = 0, count = 0;

        for (int i = 0; i < nums.size(); ++i){
            count += (nums[i] == 1) ? 1 : -1;

            if (countMap.find(count) != countMap.end()){
                maxLen = max(maxLen, i - countMap[count]);
            }else{
                countMap[count] = i;
            }
        }
        return maxLen;
    }
};