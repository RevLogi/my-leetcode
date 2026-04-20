#include <string>
#include <vector>

class Solution {
   public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> res;
        std::vector<int> p_cnt(26, 0), win_cnt(26, 0);

        for (char c : p) {
            p_cnt[c - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            win_cnt[s[right] - 'a']++;

            if (right - left + 1 == p.size()) {
                if (win_cnt == p_cnt) {
                    res.push_back(left);
                }
                win_cnt[s[left] - 'a']--;
                left++;
            }
        }

        return res;
    }
};
