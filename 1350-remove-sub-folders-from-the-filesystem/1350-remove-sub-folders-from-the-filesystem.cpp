class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;

        for (const string& f : folder) {
            if (result.empty() || f.rfind(result.back() + "/", 0) != 0) {
                result.push_back(f);
            }
        }
        
        return result;
    }
};