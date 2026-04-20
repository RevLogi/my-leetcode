#include <vector>

class Solution {
   public:
    int search(std::vector<int> &nums, int target) {
        int mid, start = 0, end = nums.size() - 1;

        while (start <= end) {
            mid = start + ((end - start) >> 1);
            if (nums[mid] < target) {
                if (nums[mid] <= nums[end] && nums[end] < target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (nums[mid] > target) {
                if (nums[start] <= nums[mid] && nums[start] > target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                return mid;
            }
        }
        return -1;
    }
};
