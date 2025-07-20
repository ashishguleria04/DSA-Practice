class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        for (const auto& path : paths) {
            TrieNode* curr = root;
            for (const string& folder : path) {
                if (curr->children.find(folder) == curr->children.end()) {
                    curr->children[folder] = new TrieNode();
                }
                curr = curr->children[folder];
            }
        }

        unordered_map<string, vector<TrieNode*>> serial_map;
        serialize_subtrees(root, serial_map);

        unordered_set<TrieNode*> deleted_nodes;
        for (const auto& pair : serial_map) {
            if (pair.second.size() > 1) {
                for (TrieNode* node : pair.second) {
                    deleted_nodes.insert(node);
                }
            }
        }

        vector<vector<string>> result;
        vector<string> current_path;
        build_paths(root, current_path, result, deleted_nodes);

        return result;
    }

private:
    struct TrieNode {
        map<string, TrieNode*> children;
    };

    string serialize_subtrees(TrieNode* node, unordered_map<string, vector<TrieNode*>>& serial_map) {
        if (node->children.empty()) {
            return "";
        }

        string serial = "";
        for (const auto& pair : node->children) {
            serial += pair.first + "(" + serialize_subtrees(pair.second, serial_map) + ")";
        }

        serial_map[serial].push_back(node);
        return serial;
    }

    void build_paths(TrieNode* node, vector<string>& current_path, vector<vector<string>>& result, const unordered_set<TrieNode*>& deleted_nodes) {
        for (const auto& pair : node->children) {
            TrieNode* child = pair.second;
            if (deleted_nodes.count(child)) {
                continue;
            }
            current_path.push_back(pair.first);
            result.push_back(current_path);
            build_paths(child, current_path, result, deleted_nodes);
            current_path.pop_back();
        }
    }
};