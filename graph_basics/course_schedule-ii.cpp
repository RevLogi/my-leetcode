#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> flags(numCourses, 0);
        std::vector<int> res;

        for (auto &edge : prerequisites) {
            int pre = edge[1];
            int next = edge[0];
            adj[pre].push_back(next);
        }

        for (int i = 0; i < numCourses; i++) {
            if (flags[i] == 0) {
                if (!dfs(i, adj, flags, res)) {
                    return {};
                }
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int course, std::vector<std::vector<int>> &adj, std::vector<int> &flags,
             std::vector<int> &res) {
        flags[course] = 1;

        for (auto &next : adj[course]) {
            if (flags[next] == 1) {
                return false;
            }
            if (flags[next] == 0) {
                if (!dfs(next, adj, flags, res)) {
                    return false;
                }
            }
        }
        flags[course] = 2;
        res.push_back(course);

        return true;
    }
};
