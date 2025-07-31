class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> current_ors;

        for (int x : arr) {
            unordered_set<int> next_ors = {x};
            for (int y : current_ors) {
                next_ors.insert(x | y);
            }
            current_ors = next_ors;
            result.insert(current_ors.begin(), current_ors.end());
        }

        return result.size();
    }
};