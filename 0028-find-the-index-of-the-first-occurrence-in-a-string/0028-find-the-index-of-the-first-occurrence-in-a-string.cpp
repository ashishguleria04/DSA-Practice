class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayLen = haystack.length();
        int needleLen = needle.length();

       
        if (needleLen == 0) {
            return 0;
        }

        if (needleLen > hayLen) {
            return -1;
        }

        for (int i = 0; i <= hayLen - needleLen; ++i) {
            bool match = true;
            for (int j = 0; j < needleLen; ++j) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break; 
                }
            }
            if (match) {
                return i; 
            }
        }

       
        return -1;
    }
};