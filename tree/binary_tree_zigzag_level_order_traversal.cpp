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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        bool leftToRight = true;

        std::deque<TreeNode *> fringe;
        fringe.push_back(root);

        while (!fringe.empty()) {
            int size = fringe.size();
            std::vector<int> levelNodes(size, 0);

            for (int i = 0; i < size; i++) {
                if (leftToRight) {
                    TreeNode *curr = fringe.front();
                    fringe.pop_front();
                    if (curr->left) fringe.push_back(curr->left);
                    if (curr->right) fringe.push_back(curr->right);
                    levelNodes[i] = curr->val;
                } else {
                    TreeNode *curr = fringe.back();
                    fringe.pop_back();
                    if (curr->right) fringe.push_front(curr->right);
                    if (curr->left) fringe.push_front(curr->left);
                    levelNodes[i] = curr->val;
                }
            }
            leftToRight = !leftToRight;

            res.push_back(levelNodes);
        }

        return res;
    }
};
