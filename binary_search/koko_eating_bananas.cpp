#include <algorithm>
#include <vector>

class Solution {
   public:
    int minEatingSpeed(std::vector<int> &piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());

        while (left < right) {
            int time = 0;
            int speed = left + ((right - left) >> 1);
            for (auto p : piles) {
                time += (p + speed - 1) / speed;
            }
            if (time <= h) {
                right = speed;
            } else {
                left = speed + 1;
            }
        }
        return left;
    }
};
