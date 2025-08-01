class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int sLen = s.length();
        int pLen = p.length();

        if (sLen < pLen) {
            return result;
        }

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        for (int i = 0; i < pLen; ++i) {
            pFreq[p[i] - 'a']++;
            windowFreq[s[i] - 'a']++;
        }

        if (pFreq == windowFreq) {
            result.push_back(0);
        }

        for (int i = pLen; i < sLen; ++i) {
            windowFreq[s[i - pLen] - 'a']--;
            windowFreq[s[i] - 'a']++;
            
            if (pFreq == windowFreq) {
                result.push_back(i - pLen + 1);
            }
        }

        return result;
    }
};