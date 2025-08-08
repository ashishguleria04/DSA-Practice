class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        unsigned int unum = num;
        string hex_chars = "0123456789abcdef";
        string ans = "";

        while (unum != 0) {
            int digit_val = unum & 15; // Get the last 4 bits
            ans = hex_chars[digit_val] + ans; // Prepend the hex character
            unum >>= 4; // Shift right by 4 bits
        }

        return ans;
    }
};