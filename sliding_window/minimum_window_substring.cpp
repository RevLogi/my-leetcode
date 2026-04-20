#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (t.size() > s.size()) {
            return {};
        }

        int left = 0, right = 0;
        int remain_size = t.size();
        int min_len = INT_MAX, start_pos;
        std::vector<int> t_cnt(128, 0);

        for (char c : t) {
            ++t_cnt[c];
        }

        while (right < s.size()) {
            if (--t_cnt[s[right]] >= 0) {
                --remain_size;
            }
            while (remain_size == 0) {
                if (++t_cnt[s[left]] > 0) {
                    ++remain_size;
                    if (min_len > right - left + 1) {
                        min_len = right - left + 1;
                        start_pos = left;
                    }
                }
                left++;
            }
            right++;
        }

        if (min_len == INT_MAX) {
            return {};
        }

        return s.substr(start_pos, min_len);
    }
};
