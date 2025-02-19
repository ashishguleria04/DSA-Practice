class Solution {
public:
    string getHappyString(int n, int k) {
        string result;
        int count = 0;
        backtrack(n, k, "", result, count);
        return result;
    }

private:
    void backtrack(int n, int k, string current, string& result, int& count) {
        // If the current string is of length n, increment the count
        if (current.length() == n) {
            count++;
            // If this is the k-th string, set it as the result
            if (count == k) {
                result = current;
            }
            return;
        }

        // Try adding 'a', 'b', or 'c' to the current string
        for (char ch : {'a', 'b', 'c'}) {
            // Ensure the new character is not the same as the last character in the current string
            if (current.empty() || ch != current.back()) {
                backtrack(n, k, current + ch, result, count);
                // If the result is already found, stop further exploration
                if (!result.empty()) {
                    return;
                }
            }
        }
    }
};