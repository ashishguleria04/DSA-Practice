class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        std::unordered_map<char, char> matching_parentheses = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (matching_parentheses.count(c)) { 
                if (st.empty() || st.top() != matching_parentheses[c]) {
                    return false; 
                }
                st.pop(); 
            } else { 
                st.push(c);
            }
        }

        return st.empty(); 
    }
};
