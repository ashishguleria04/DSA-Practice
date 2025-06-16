class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = static_cast<int>(s.size()) - 1;
        while(i < j) std::swap(s[i++], s[j--]);
    }
};