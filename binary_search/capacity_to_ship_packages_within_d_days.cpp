#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
   public:
    int shipWithinDays(std::vector<int> &weights, int days) {
        int left = 0, right;
        int res = INT_MAX;

        for (auto weight : weights) {
            right += weight;
            left = std::max(left, weight);
        }

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int capacity = mid;
            int count = 1;

            for (auto weight : weights) {
                if (capacity < weight) {
                    capacity = mid;
                    count += 1;
                }
                capacity -= weight;
            }

            if (count <= days) {
                right = mid;
                res = std::min(mid, res);
            } else {
                left = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    std::vector<int> weights = {1, 2, 3, 1, 1};
    int days = 4;
    int answer = sol.shipWithinDays(weights, days);
    std::cout << "Output: " << answer << std::endl;
    return 0;
}
