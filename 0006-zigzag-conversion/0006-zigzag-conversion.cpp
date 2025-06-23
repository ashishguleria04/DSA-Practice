class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(numRows);
        int curr = 0, step = 1;

        for (char c : s){
            rows[curr] += c;
            if (curr == 0) step = 1;
            else if (curr == numRows - 1) step = -1;
            curr += step;
        }
        string res;
        for (string& row : rows) res += row;
        return res;
    }
};