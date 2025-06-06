class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;

        for (char digit : num) {
      
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }


        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        int index = 0;
        while (index < result.size() && result[index] == '0') {
            index++;
        }

        result = result.substr(index);

        return result.empty() ? "0" : result;
    }
};