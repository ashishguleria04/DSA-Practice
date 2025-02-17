class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char c : tiles) {
            freq[c]++;
        }
        return backtrack(freq);
    }
    
    int backtrack(unordered_map<char, int>& freq) {
        int count = 0;
        for (auto& [c, f] : freq) {
            if (f > 0) {
                count++;  
                freq[c]--;  
                count += backtrack(freq);  
                freq[c]++;  
            }
        }
        return count;
    }
};