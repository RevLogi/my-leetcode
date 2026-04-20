
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
    int ans = 0;

    int depthOfBinaryTree(TreeNode *root) {
        if (!root) return 0;

        int left = depthOfBinaryTree(root->left);
        int right = depthOfBinaryTree(root->right);
        ans = std::max(ans, left + right);
        return 1 + std::max(left, right);
    }

    int diameterOfBinaryTree(TreeNode *root) {
        ans = 0;
        depthOfBinaryTree(root);
        return ans;
    }
};

