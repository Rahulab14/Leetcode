class Solution {
public:
    vector<int> vals;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(vals[mid]);

        root->left = build(left, mid - 1);
        root->right = build(mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, vals.size() - 1);
    }
};