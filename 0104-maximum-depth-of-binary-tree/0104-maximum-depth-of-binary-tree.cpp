class Solution {
public:
    int maxd = 0;

    void dfs(TreeNode* root, int dep) {
        if(root == NULL) return;

        maxd = max(maxd, dep);

        dfs(root->left, dep + 1);
        dfs(root->right, dep + 1);
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return maxd;
    }
};