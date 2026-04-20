#include <queue>
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> flags(numCourses, 0);
        int count = 0;

        for (auto &edge : prerequisites) {
            int next = edge[0];
            int pre = edge[1];
            adj[pre].push_back(next);
        }

        for (int i = 0; i < numCourses; i++) {
            if (flags[i] == 0) {
                if (!dfs(i, flags, adj)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool dfs(int course, std::vector<int> &flags, std::vector<std::vector<int>> &adj) {
        if (adj[course].empty()) {
            flags[course] = 2;
            return true;
        }
        flags[course] = 1;
        for (int next : adj[course]) {
            if (flags[next] == 1) {
                return false;
            }
            if (flags[next] == 0) {
            if (!dfs(next, flags, adj)) {
                return false;
            }
            }
        }
        flags[course] = 2;
        return true;
    }
};
