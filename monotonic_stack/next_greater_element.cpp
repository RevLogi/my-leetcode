#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> mono;
        std::vector<int> res(nums1.size(), -1);

        for (int i = 0; i < nums2.size(); i++) {
            int num = nums2[i];
            while (!mono.empty() && num > mono.top()) {
                next_greater[mono.top()] = num;
                mono.pop();
            }
            mono.push(num);
        }

        for (int j = 0; j < nums1.size(); j++) {
            int num = nums1[j];
            if (next_greater.find(num) != next_greater.end()) {
                res[j] = next_greater[num];
            }
        }

        return res;
    }
};
