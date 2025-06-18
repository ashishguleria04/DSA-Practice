class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0), window(128, 0);
        for (char c : t) need[c]++;

        int left = 0, right = 0, valid = 0, start = 0, len = INT_MAX;

        // Count how many unique characters are needed
        int required = count_if(need.begin(), need.end(), [](int x) { return x > 0; });

        while (right < s.size()) {
            char c = s[right++];
            if (need[c]) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (valid == required) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left++];
                if (need[d]) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
