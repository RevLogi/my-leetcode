#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
   public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> m;
        int left = 0, length = 0;

        for (int right = 0; right < s.size(); right++) {
            if (m.find(s[right]) != m.end() && m[s[right]] >= left) {
                left = m[s[right]] + 1;
            }
            m[s[right]] = right;
            length = std::max(length, right - left + 1);
        }

        return length;
    }
};
