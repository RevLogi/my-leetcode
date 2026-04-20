#include <algorithm>
#include <vector>
#include <stack>

class Solution {
   public:
    int largestRectangleArea(std::vector<int> &heights) {
        heights.push_back(0);
        std::stack<int> mono;
        int res = 0;
        int i_left, i_right;

        for (int i = 0; i < heights.size(); i++) {
            while (!mono.empty() && heights[i] < heights[mono.top()]) {
                i_right = mono.top();
                mono.pop();
                if (mono.empty()) {
                    i_left = -1;
                } else {
                    i_left = mono.top();
                }
                int wide = i - i_left - 1;
                res = std::max(res, heights[i_right] * wide);
            }
            mono.push(i);
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> heights {1};
    int result = sol.largestRectangleArea(heights);
    return result;
}

