class Solution {
public:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
        std::unordered_map<int, int> cnt;
        for (int x : basket1) {
            cnt[x]++;
        }
        for (int x : basket2) {
            cnt[x]--;
        }

        int min_val = INT_MAX;
        std::vector<int> to_swap;

        for (auto const& [fruit_cost, count_diff] : cnt) {
            if (count_diff % 2 != 0) {
                return -1; 
            }
            
            for (int i = 0; i < std::abs(count_diff) / 2; ++i) {
                to_swap.push_back(fruit_cost);
            }
            min_val = std::min(min_val, fruit_cost);
        }

        std::sort(to_swap.begin(), to_swap.end());

        long long total_cost = 0;
        
        for (int i = 0; i < to_swap.size() / 2; ++i) {
            total_cost += std::min(to_swap[i], 2 * min_val);
        }

        return total_cost;
    }
};