#include <queue>
#include <vector>

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
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;

        std::queue<TreeNode *> fringe;
        fringe.push(root);

        while (!fringe.empty()) {
            int size = fringe.size();
            std::vector<int> levelNodes(size, 0);

            for (int i = 0; i < size; i++) {
                TreeNode *curr = fringe.front();
                fringe.pop();
                if (curr->left) fringe.push(curr->left);
                if (curr->right) fringe.push(curr->right);
                levelNodes[i] = curr->val;
            }

            res.push_back(levelNodes);
        }

        return res;
    }
};

