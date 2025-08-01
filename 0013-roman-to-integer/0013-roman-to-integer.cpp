class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            
            int currentValue = romanValues[s[i]];

           
            if (i + 1 < n && currentValue < romanValues[s[i+1]]) {
              
                result -= currentValue;
            } else {
               
                result += currentValue;
            }
        }
        return result;
    }
};