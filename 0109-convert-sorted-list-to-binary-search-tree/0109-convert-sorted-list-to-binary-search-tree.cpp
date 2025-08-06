class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        return buildBST(arr, 0, arr.size() - 1);
    }

private:
    TreeNode* buildBST(const std::vector<int>& arr, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildBST(arr, start, mid - 1);
        root->right = buildBST(arr, mid + 1, end);
        return root;
    }
};