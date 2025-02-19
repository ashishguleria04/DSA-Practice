class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        string result;
        int num = 1; // Start with the smallest digit

        for (char ch : pattern) {
            if (ch == 'I') {
                st.push(num++);
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            } else if (ch == 'D') {
                st.push(num++);
            }
        }

        // Push the last number
        st.push(num++);

        // Pop all remaining numbers from the stack
        while (!st.empty()) {
            result += to_string(st.top());
            st.pop();
        }

        return result;
    }
};