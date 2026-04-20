#include <algorithm>
#include <vector>

class Solution {
   public:
    int splitArray(std::vector<int> &nums, int k) {
        int left = 0, right = 0;

        for (auto num : nums) {
            right += num;
            left = std::max(num, left);
        }

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int capacity = mid;
            int count = 1;

            for (auto num : nums) {
                if (capacity < num) {
                    capacity = mid;
                    count++;
                }
                capacity -= num;
            }

            if (count > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};
