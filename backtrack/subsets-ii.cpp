#include <algorithm>
#include <vector>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<int> path;

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        backtrack(nums, 0, false);
        return res;
    }

    void backtrack (std::vector<int>& nums, int index, bool chosenPre) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }

        backtrack(nums, index + 1, false);
        if (index > 0 && nums[index] == nums[index - 1] && !chosenPre) {
            return;
        }

        path.push_back(nums[index]);
        backtrack(nums, index + 1, true);
        path.pop_back();
    }
};
