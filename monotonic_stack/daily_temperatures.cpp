#include <vector>
#include <stack>

class Solution {
   public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<int> mono;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!mono.empty() && temperatures[i] > temperatures[mono.top()]) {
                int prev_i = mono.top();
                mono.pop();
                res[prev_i] = i - prev_i;
            }
            mono.push(i);
        }

        return res;
    }
};
