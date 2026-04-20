#include <vector>

class Solution {
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        std::vector<int> colored(graph.size(), 0);

        for (int i = 0; i < graph.size(); i++) {
            if (colored[i] == 0) {
                if (!dfs(i, 1, graph, colored)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(int node, int color, std::vector<std::vector<int>>& graph, std::vector<int>& colored) {
        colored[node] = color;
        for (const auto& next : graph[node]) {
            if (colored[next] == color) {
                return false;
            }
            if (colored[next] == 0) {
                if (!dfs(next, 3 - color, graph, colored)) {
                    return false;
                }
            }
        }
        return true;
    }
};
