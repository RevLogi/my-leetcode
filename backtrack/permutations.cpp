#include <vector>

class Solution {
public:
    std::vector<bool> used;
    std::vector<int> path;
    std::vector<std::vector<int>> res;

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        used.assign(nums.size(), false);
        backtrack(nums);
        return res;
    }

    void backtrack(std::vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }
};
