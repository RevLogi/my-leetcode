#include <queue>
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        std::vector<int> id(numCourses, 0);
        std::vector<std::vector<int>> adj(numCourses);
        std::queue<int> delete_queue;
        int count = 0;

        for (auto &edge : prerequisites) {
            int next = edge[0];
            int pre = edge[1];
            id[next]++;
            adj[pre].push_back(edge[next]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (id[i] == 0) {
                delete_queue.push(i);
            }
        }

        while (!delete_queue.empty()) {
            int curr = delete_queue.front();
            delete_queue.pop();
            count++;
            for (int next : adj[curr]) {
                id[next]--;
                if (id[next] == 0) {
                    delete_queue.push(next);
                }
            }
        }

        return count == numCourses;
    }
};
