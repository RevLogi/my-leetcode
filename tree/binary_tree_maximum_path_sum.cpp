#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int ans = INT_MIN;

    int maxPathSum(TreeNode *root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root) {
        if (!root) return 0;

        int left = std::max(0, dfs(root->left));
        int right = std::max(0, dfs(root->right));

        ans = std::max(ans, root->val + left + right);
        return root->val + std::max(left, right);
    }
};

