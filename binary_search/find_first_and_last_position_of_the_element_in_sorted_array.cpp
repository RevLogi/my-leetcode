#include <vector>

class Solution {
   public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        std::vector<int> res(2, -1);
        int mid, start = 0, end = nums.size() - 1;

        while (start <= end) {
            mid = start + ((end - start) >> 1);
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid, end = mid;
                while (start != 0 && nums[start - 1] == target) {
                    start--;
                }
                res[0] = start;
                while (end != nums.size() && nums[end + 1] == target) {
                    end++;
                }
                res[1] = end;
                break;
            }
        }

        return res;
    }
};
