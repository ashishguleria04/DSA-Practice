class Solution {
public:
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
       
        int max_coord = 200000; 
        std::vector<long long> prefixSum(max_coord + 1, 0);

        for (const auto& fruit : fruits) {
            prefixSum[fruit[0]] += fruit[1];
        }

      
        for (int i = 1; i <= max_coord; ++i) {
            prefixSum[i] += prefixSum[i - 1];
        }

        long long maxFruits = 0;

        
        for (int left_bound = std::max(0, startPos - k); left_bound <= startPos; ++left_bound) {
            
            int steps_taken = startPos - left_bound;
            int remaining_k = k - steps_taken;

            
            int right_bound = std::min(max_coord, startPos + remaining_k);

            
            if (steps_taken * 2 <= k) { 
                right_bound = std::min(max_coord, startPos + (k - 2 * steps_taken));
            } else { 
                right_bound = startPos;
            }
            
            
            right_bound = std::max(left_bound, right_bound);


            long long currentFruits = prefixSum[right_bound] - (left_bound > 0 ? prefixSum[left_bound - 1] : 0);
            maxFruits = std::max(maxFruits, currentFruits);
        }

       
        for (int right_bound = startPos; right_bound <= std::min(max_coord, startPos + k); ++right_bound) {
            
            int steps_taken = right_bound - startPos;
            int remaining_k = k - steps_taken;

            
            int left_bound = std::max(0, startPos - remaining_k);

           
            if (steps_taken * 2 <= k) { 
                left_bound = std::max(0, startPos - (k - 2 * steps_taken));
            } else { 
                left_bound = startPos;
            }

           
            left_bound = std::min(right_bound, left_bound);

            long long currentFruits = prefixSum[right_bound] - (left_bound > 0 ? prefixSum[left_bound - 1] : 0);
            maxFruits = std::max(maxFruits, currentFruits);
        }

        return maxFruits;
    }
};