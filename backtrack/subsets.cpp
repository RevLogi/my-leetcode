#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<int> path;

    void backtrack(std::vector<int>& nums, int index, std::vector<int> path, std::vector<std::vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }

        backtrack(nums, index + 1, path, res);

        path.push_back(nums[index]);
        backtrack(nums, index + 1, path, res);
        path.pop_back();
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        backtrack(nums, 0, path, res);
        return res;
    }
};
