#include <iostream>

class Solution {
    public:
        std::vector<std::vector<int>> threeSum (std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> res;

            for (int i = 0; i < nums.size() - 2; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                if (nums[i] > 0) break;

                int target = 0 - nums[i];
                int front = i + 1, back = nums.size() - 1;

                while (front < back) {
                    if (nums[front] + nums[back] > target) {
                        --back;
                    } else if (nums[front] + nums[back] < target) {
                        ++front;
                    } else {
                        res.push_back({nums[i], nums[front], nums[back]});
                        while (front < back && nums[front] == nums[front + 1] && nums[back] == nums[back - 1]) {
                            front++;
                            back--;
                        }
                        front++;
                        back--;
                    }
                }
            }

            return res;
        }
};
