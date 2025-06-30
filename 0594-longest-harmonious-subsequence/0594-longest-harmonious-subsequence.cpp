class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums){
            countMap[num]++; 
        }

        int maxLength = 0;
        for (auto& it : countMap){
            int num = it.first;
            if (countMap.find(num + 1) != countMap.end()){
                maxLength = max(maxLength, it.second + countMap[num + 1]);
            }
        }
        return maxLength;
    }
};