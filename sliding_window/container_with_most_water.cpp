#include <vector>

class Solution {
   public:
    int maxArea(std::vector<int> &height) {
        int front = 0, back = height.size() - 1;
        int maxA = 0;
        int m;

        while (front < back) {
            if (height[front] > height[back]) {
                m = back;
            } else {
                m = front;
            }
            maxA = std::max(maxA, (back - front) * height[m]);
            if (m == front) {
                ++front;
            } else {
                --back;
            }
        }

        return maxA;
    }
};
