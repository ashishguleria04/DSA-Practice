class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> a(26, 0), b(26,0);
        for (int i = 0; i < s1.size(); ++i){
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }
        if (a == b) return true;
        for (int i = s1.size(); i < s2.size(); ++i){
            b[s2[i] - 'a']++;
            b[s2[i - s1.size()] - 'a']--;
            if ( a == b) return true;
        }
        return false;
    }
};